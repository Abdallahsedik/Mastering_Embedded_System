/*************************************************************************************************************************************
@file           Rcc.c
@version        1.0.0
@brief          AUTOSAR MCU/RCC Driver (STM32F103X6).
@details        AUTOSAR 4.4.0 Reset and Clock Control (RCC) driver implementation.
                Provides configuration and control of system clock sources (HSI, HSE, PLL),
                prescalers (AHB, APB1, APB2), peripheral clock gating, and reset generation.
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


#include "Rcc.h"

void Rcc_GpioA_Enable(void)
{
	RCC_REG->APB2ENR |= (1<<2);

}
