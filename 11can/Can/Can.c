#include "can.h"
#include "../Reg_eSys_Rcc.h"
#include "Reg_esys_Can.h"



#define     MAX_TS2 0x07
#define     MAX_TS1 0x0F
#define     MAX_SJW 0x03
#define     MAX_PRE 1023



/* Can_IdType frame type bits */
#define CAN_ID_EXT_MASK   ((Can_IdType)0x80000000u) /* 10/11 = extended ID   */
#define CAN_ID_FD_MASK    ((Can_IdType)0x40000000u) /* 01/11 = CAN FD frame  */
#define CAN_ID_VALUE_MASK ((Can_IdType)0x1FFFFFFFu) /* 29-bit ID value       */

/* The 3 transmit mailboxes form ONE transmit HOH (Hth = 0) */
#define CAN_TX_HOH_COUNT   1u
#define CAN_NUM_TX_MAILBOX 3u

/* swPduHandle per mailbox, confirmation */
static boolean   Can_TxPending[CAN_NUM_TX_MAILBOX];
static PduIdType Can_TxSwPduHandle[CAN_NUM_TX_MAILBOX];


Can_ControllerStateType Can_CurrentState = CAN_CS_UNINIT;

void Can_Init(const Can_ConfigType* Config)
{
	if ((Config == NULL_PTR) ||  (Config->TS2 > MAX_TS2) || (Config->TS1 > MAX_TS1) || (Config->SJW > MAX_SJW)
	    ||(Config->Prescaler == 0 )||( Config->Prescaler > MAX_PRE) )
	{
        Can_CurrentState = CAN_CS_UNINIT;
		return ;
	}

	/* 1- Enable Clock  CAN peripheral */
	/*RCC_APB1ENR_CAN1ENABLE*/
	RCC_REG->APB1ENR |= RCC_APB1ENR_CAN1ENABLE;

	/* leave sleep */
	CAN_REG->CAN_MCR &= ~CAN_MCR_Sleep;
   /*update can state  */
    Can_CurrentState = CAN_CS_SLEEP;
	uint32 t = CAN_TIMEOUT;
	while ((CAN_REG->CAN_MSR & CAN_MSR_SLAK) && --t);
	if (t == 0u)
    {
        Can_CurrentState = CAN_CS_UNINIT;
        return;
    } 

	/* enter init */
	CAN_REG->CAN_MCR |= (1u << CAN_INRQ_BIT);
	t = CAN_TIMEOUT;
	while (!(CAN_REG->CAN_MSR & (1u << CAN_INAK_BIT)) && --t);
	if (t == 0u)
    {
        Can_CurrentState = CAN_CS_UNINIT;
        return;
    } 
	/* 3-  Bit Timing (baud rate) */

	CAN_REG->CAN_BTR = ((uint32)Config->SJW << 24) | ((uint32)Config->TS2 << 20) |
			            ((uint32)Config->TS1 << 16) | (uint32)(Config->Prescaler - 1u) |
			            (Config->LoopBack ? CAN_BTR_LBKM : 0u) |
			            (Config->Silent   ? CAN_BTR_SILM : 0u) ;

	/* leave init */
	CAN_REG->CAN_MCR &= ~(1u << CAN_INRQ_BIT);
	t = CAN_TIMEOUT;
	while ((CAN_REG->CAN_MSR & (1u << CAN_INAK_BIT)) && --t);
    if (t == 0u)
    {
        Can_CurrentState = CAN_CS_UNINIT;
	    return;
    }
    else
    {
        Can_CurrentState =CAN_CS_STOPPED;

    }
}
void Can_DeInit(void)
{
    uint32 t;

    if (Can_CurrentState == CAN_CS_UNINIT)
    {
        /* Module not initialized — nothing to do / or report det */
        return;
    }

    /* The controller should be in STOPPED state before de-initialization
       (AUTOSAR: CanIf ensures this by calling Can_SetControllerMode(CAN_STOPPED) first) */
    if (Can_CurrentState != CAN_CS_STOPPED)
    {
        /* Optional: force stop by entering init mode */
    }

    /* Enter initialization mode to request the controller out of the bus */
    CAN_REG->CAN_MCR |= (1u << CAN_INRQ_BIT);
    t = CAN_TIMEOUT;
    while (!(CAN_REG->CAN_MSR & (1u << CAN_INAK_BIT)) && --t);
    /* ignore timeout here — proceed with de-init anyway? */

    /* Request software reset (bxCAN: MCR.RESET sets all registers to reset values) */
    CAN_REG->CAN_MCR |= CAN_MCR_Reset;

    /* Wait until reset done  */
    t = CAN_TIMEOUT;
    while ((CAN_REG->CAN_MCR & CAN_MCR_Reset) && --t);

    /* Disable CAN clocks */
    RCC_REG->APB1ENR &= ~RCC_APB1ENR_CAN1ENABLE;

    Can_CurrentState = CAN_CS_UNINIT;
}



/* Service ID [hex]: 0x11, Sync/Async: Synchronous, Reentrancy: Non Reentrant */
Std_ReturnType Can_Write(Can_HwHandleType Hth, const Can_PduType* PduInfo)
{
    uint8   Mailbox;
    uint32  tsr;
    uint32  tdlr = 0u;
    uint32  tdhr = 0u;
    uint32  idValue;
    boolean extId;
    uint8   i;

    /* ---------------------checks --------------- */
    if (Can_CurrentState != CAN_CS_STARTED)          /* must be STARTED       */
    {
        return E_NOT_OK;
    }
    if ((Hth >= CAN_TX_HOH_COUNT) || (PduInfo == NULL_PTR))
    {
        return E_NOT_OK;
    }
    if (PduInfo->length > 8u)                        /* classic CAN: 0..8     */
    {
        return E_NOT_OK;
    }
    if ((PduInfo->length > 0u) && (PduInfo->sdu == NULL_PTR))
    {
        return E_NOT_OK;
    }
    if ((PduInfo->id & CAN_ID_FD_MASK) != 0u)        /* bxCAN has no CAN FD   */
    {
        return E_NOT_OK;
    }

    extId   = ((PduInfo->id & CAN_ID_EXT_MASK) != 0u);
    idValue = (uint32)(PduInfo->id & CAN_ID_VALUE_MASK);
    if ((extId == FALSE) && (idValue > 0x7FFu))      /* std = 11-bit ID only  */
    {
        return E_NOT_OK;
    }

    /* -------- find a free transmit mailbox ------------------------------ */
    tsr = CAN_REG->CAN_TSR;
    if      (tsr & TSR_TME0) Mailbox = 0u;
    else if (tsr & TSR_TME1) Mailbox = 1u;
    else if (tsr & TSR_TME2) Mailbox = 2u;
    else                     return CAN_BUSY;        /* none free             */

    /* -------- copy exactly DLC bytes  ---------- */
    for (i = 0u; (i < PduInfo->length) && (i < 4u); i++)
    {
        tdlr |= ((uint32)PduInfo->sdu[i]) << (8u * i);
    }
    for (; (i < PduInfo->length) && (i < 8u); i++)
    {
        tdhr |= ((uint32)PduInfo->sdu[i]) << (8u * (i - 4u));
    }

    /* -------- store swPduHandle for the later Tx confirmation ----------- */
    Can_TxPending[Mailbox]     = TRUE;
    Can_TxSwPduHandle[Mailbox] = PduInfo->swPduHandle;

    /* -------- fill mailbox ----------- */
    if (extId != FALSE)
    {
        /* extended: EXID[28:0] -> TIR[31:3], IDE = 1 */
        CAN_REG->sTxMailBox[Mailbox].TIR = (idValue << 3) | CAN_TIR_IDE;
    }
    else
    {
        /* standard: STID[10:0] -> TIR[31:21], IDE = 0 */
        CAN_REG->sTxMailBox[Mailbox].TIR = (idValue << 21);
    }

    CAN_REG->sTxMailBox[Mailbox].TDTR = ((uint32)PduInfo->length & 0x0Fu);
    CAN_REG->sTxMailBox[Mailbox].TDLR = tdlr;
    CAN_REG->sTxMailBox[Mailbox].TDHR = tdhr;

    CAN_REG->sTxMailBox[Mailbox].TIR |= CAN_TIR_TXRQ;   /* start transmission */

    return E_OK;
}
