#ifndef COM_CFG_H_
#define COM_CFG_H_

#include "Std_Types.h"

/* I-PDU IDs (Must match CanIf configuration) */
#define COM_IPDU_TX_WARNING         0u  /* CAN ID 0x300 */
#define COM_IPDU_RX_ABS             2u  /* CAN ID 0x100 */

/* Signal Properties Configuration */
typedef struct {
    uint16  SignalId;
    uint16  PduId;
    uint8   BitPosition;
    uint8   BitLength;
    boolean IsTx;
} Com_SignalConfigType;

extern const Com_SignalConfigType Com_SignalConfig[];

#endif /* COM_CFG_H_ */
