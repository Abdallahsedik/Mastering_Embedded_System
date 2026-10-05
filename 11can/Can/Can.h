/*
 * Can.h
 *
 *  Created on: Oct 4, 2026
 *      Author: pc
 */

#ifndef CAN_H_
#define CAN_H_

#include "Std_Types.h"
#include "Can_GeneralTypes.h"




void Can_Init (const Can_ConfigType* Config);
void Can_DeInit(void);

Std_ReturnType Can_Write(Can_HwHandleType Hth, const Can_PduType* PduInfo);


//Std_ReturnType Can_CheckBaudrate( uint8 Controller,const uint16 Baudrate);

#endif /* CAN_CAN_H_ */
