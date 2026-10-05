#ifndef Can_GeneralTypes_H_
#define Can_GeneralTypes_H_

#include "PduR_Types.h"

/*
*@name       : Can_IdType
*@Description: Represents the Identifier of an L-PDU.
*               The two most significant bits specify the frame type: 00 CAN message with Standard CAN ID 
*               01 CAN FD frame with Standard CAN ID 10 CAN message
*               with Extended CAN ID 11 CAN FD frame with Extended CAN ID)           
*@Available via: Can_GeneralTypes.h
 */

typedef uint32 Can_IdType;

/*
*@name       : Can_IdType
*@Description: Represents the hardware object handles of a CAN hardware unit.
*                For CAN hardware units with more than 255 HW objects use extended range
*@range       :Standard (0->0x0FF) |Extended(0->0xFFFF)
*@Available via: Can_GeneralTypes.h
*/

typedef uint32 Can_HwHandleType;

/*
*@name       : Can_PduType
*@Description:  This type unites PduId (swPduHandle)
*              , SduLength (length), SduData (sdu),
*                and CanId (id) for any CAN L-SDU.
*@Available via: Can_GeneralTypes.h
 */


typedef struct {
PduIdType   swPduHandle;
uint8       length;
Can_IdType  id;
uint8*      sdu;
}Can_PduType;



/*
*@name       : Can_HwType
*@Description:  This type defines a data structure which clearly provides an Hardware Object Handle including its
*               corresponding CAN Controller and therefore CanDrv as well as the specific CanId.
*@Available via: Can_GeneralTypes.h
 */

typedef struct {
Can_IdType   CanId; /*Standard/Extended CAN ID of CAN L-PDU */
Can_HwHandleType Hoh;/**ID of the corresponding Hardware Object Range */
uint8  ControllerId;/**ControllerId provided by CanIf clearly identify the corresponding controller */
}Can_HwType;

#define CAN_BUSY 0x02

/*
*@name       : Can_ErrorStateType
*@Description:Error states of a CAN controller.
*@Available via: Can_GeneralTypes.h
 */
typedef enum{
    CAN_ERRORSTATE_ACTIVE,/**The CAN controller takes fully part in communication */
    CAN_ERRORSTATE_PASSIVE,/*The CAN controller takes part in communication, but does not send active error frames*/
    CAN_ERRORSTATE_BUSOFF /*The CAN controller does not take part in communication*/
}Can_ErrorStateType;

/*
*@name       : Can_ControllerStateType
*@Description:States that are used by the several ControllerMode functions
*@Available via: Can_GeneralTypes.h
 */
typedef enum{
    CAN_CS_UNINIT,/**CAN controller state UNINIT. */
    CAN_CS_STARTED,/*CAN controller state STARTED */
    CAN_CS_STOPPED ,/*CAN controller state STOPPED*/
    CAN_CS_SLEEP    /**CAN controller state SLEEP */
}Can_ControllerStateType;


typedef struct {
    uint8   TS2;         /* Time Segment 2       (0..7)   */
    uint8   TS1;         /* Time Segment 1       (0..15)  */
    uint8   SJW;         /* Sync Jump Width      (0..3)   */
    uint16  Prescaler;   /* Baud prescaler       (1..1023)*/
    boolean LoopBack;    /* TRUE -> loop-back mode         */
    boolean Silent;      /* TRUE -> silent mode           */
} Can_ConfigType;


#endif /* CAN_H_ */
