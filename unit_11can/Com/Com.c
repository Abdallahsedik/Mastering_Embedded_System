#include "Com.h"
#include "Com_Cfg.h"
#include "../PduR/PduR.h"

/* TX and RX I-PDU Buffers (Max 8 bytes for classic CAN) */
static uint8 Com_TxIpduBuffer[8];
static uint8 Com_RxIpduBuffer[8];

/* Configuration Table */
const Com_SignalConfigType Com_SignalConfig[] =
{
    /* SignalId,                  PduId,                BitPos, BitLen, IsTx   */
    { COM_SIG_WARNING_STATUS,    COM_IPDU_TX_WARNING,  0,      8,      TRUE  }, /* 8-bit signal at byte 0 */
    { COM_SIG_VEHICLE_SPEED,      COM_IPDU_RX_ABS,      0,      16,     FALSE }  /* 16-bit signal at byte 0-1 */
};

void Com_Init(void)
{
    uint8 i;
    for (i = 0; i < 8; i++)
    {
        Com_TxIpduBuffer[i] = 0;
        Com_RxIpduBuffer[i] = 0;
    }
}

uint8 Com_SendSignal(uint16 SignalId, const void* SignalDataPtr)
{
    const Com_SignalConfigType* cfg = &Com_SignalConfig[SignalId];

    /* Simple packing for 8-bit and 16-bit byte-aligned signals */
    if (cfg->BitLength == 8)
    {
		uint8 value = *(const uint8*)SignalDataPtr;
        Com_TxIpduBuffer[cfg->BitPosition / 8] = (uint8)value;
    }
    else if (cfg->BitLength == 16)
    {
		uint16 value = *(const uint16*)SignalDataPtr;
        Com_TxIpduBuffer[cfg->BitPosition / 8] = (uint8)(value & 0xFF);         /* Low byte */
        Com_TxIpduBuffer[(cfg->BitPosition / 8) + 1] = (uint8)((value >> 8) & 0xFF); /* High byte */
    }

    /* Prepare PduInfo for PduR */
    PduInfoType pduInfo;
    pduInfo.SduDataPtr = Com_TxIpduBuffer;
    pduInfo.SduLength = 8; /* Send full 8-byte frame for this example */

    /* Request transmission */
    return PduR_ComTransmit(cfg->PduId, &pduInfo);
}

uint8 Com_ReceiveSignal(uint16 SignalId, void* SignalDataPtr)
{
    const Com_SignalConfigType* cfg = &Com_SignalConfig[SignalId];

    /* Simple unpacking for 8-bit and 16-bit byte-aligned signals */
    if (cfg->BitLength == 8)
    {    uint8* value = (uint8*)SignalDataPtr;
        *value = Com_RxIpduBuffer[cfg->BitPosition / 8];
    }
    else if (cfg->BitLength == 16)
    {
        uint16* value = (uint16*)SignalDataPtr;
        *value = (uint16)Com_RxIpduBuffer[cfg->BitPosition / 8];
        *value |= ((uint16)Com_RxIpduBuffer[(cfg->BitPosition / 8) + 1] << 8);
    }

    return E_OK;
}

/* Called by PduR when a CAN message is received */
void Com_RxIndication(PduIdType RxPduId, uint8* Data, uint8 DLC)
{
    uint8 i;
    (void)RxPduId;
    (void)DLC;

    /* Copy received data into our RX buffer */
    for (i = 0; i < 8; i++)
    {
        Com_RxIpduBuffer[i] = Data[i];
    }

    /* In a full COM module, you would evaluate filters and notify the RTE here.
       Since we are polling in main, we just store the data. */
}
