/*************************************************************************************************************************************
@file           Rcc.h
@version        1.0.0
@brief          AUTOSAR MCU/RCC Driver Header (STM32F103X6).
@details        AUTOSAR 4.4.0 Reset and Clock Control (RCC) driver public interface.
                Declares clock configuration types, peripheral clock enable/disable macros,
                clock tree control APIs, and software reset interfaces.
@author         abdallah mohamed sedik
*************************************************************************************************************************************/

/*************************************************************************************************************************************
Project         : AUTOSAR 4.4.0 MCAL
Platform        : ARM Cortex-M3
MCU             : STM32F103X6
Package         : LQFP48
Module          : RCC
Autosar Version : 4.4.0
Vendor Release  : R24-11
Autosar Revision: ASR_REL_4_4_REV_0000
Sw Version      : 1.0.0
*************************************************************************************************************************************/
#ifndef RCC_RCC_H_
#define RCC_RCC_H_

#include "Platform_types.h"

#include "Reg_eSys_Rcc.h"

void Rcc_GpioA_Enable(void);

#endif /* RCC_RCC_H_ */
