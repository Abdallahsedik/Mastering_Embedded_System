/*************************************************************************************************************************************
@file           Mcu.h
@version        1.0.0
@brief          AUTOSAR MCU Driver Header (STM32F103X6).
@details        AUTOSAR 4.4.0 MCU module public interface. Contains the external 
                API declarations, data types, and macros required to use the MCU 
                clock, reset, and power management services.
@author         abdallah mohamed sedik
*************************************************************************************************************************************/

/*************************************************************************************************************************************
Project         : AUTOSAR 4.4.0 MCAL
Platform        : ARM Cortex-M3
MCU             : STM32F103X6
Package         : LQFP48
Module          : MCU
Autosar Version : 4.4.0
Vendor Release  : R24-11
Autosar Revision: ASR_REL_4_4_REV_0000
Sw Version      : 1.0.0
*************************************************************************************************************************************/
#ifndef MCU_H_
#define MCU_H_


/*==================================================================================================
 *                                       INCLUDES
==================================================================================================*/
#include "Reg_eSys_Rcc.h"
#include "Std_Types.h"
#include "Mcu_Cfg.h"
/*==================================================================================================
 *                                       Private Macros
==================================================================================================*/

#define HSI                      0
#define HSE                      1
#define PLL                      2


#define NOT_BYPASSED              0
#define BYPASSED                  1



Std_ReturnType Mcu_InitClock (void);

#endif /* MCU_H_ */
