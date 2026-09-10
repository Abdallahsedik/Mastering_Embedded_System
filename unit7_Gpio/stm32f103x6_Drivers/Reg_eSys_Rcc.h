/*************************************************************************************************************************************
@file           Reg_eSys_Rcc.h
@version        1.0.0
@brief          RCC Register Definitions for STM32F103X6 (LQFP48).
@details        Memory-mapped register structures and base addresses for the RCC peripheral.
                This file provides the hardware abstraction layer for the RCC unit,
                used by the AUTOSAR MCU module for clock initialization and configuration,
                and referenced by the PORT module to enable GPIO/AFIO peripheral clocks.
@author         abdallah mohamed sedik
*************************************************************************************************************************************/

/*************************************************************************************************************************************
Project         : AUTOSAR 4.4.0 MCAL
Platform        : ARM Cortex-M3
MCU             : STM32F103X6
Package         : LQFP48
Peripheral      : RCC
Autosar Version : 4.4.0
Vendor Release  : R24-11
Autosar Revision: ASR_REL_4_4_REV_0000
Sw Version      : 1.0.0
*************************************************************************************************************************************/


#ifndef REG_ESYS_RCC_H_
#define REG_ESYS_RCC_H_

/*==================================================================================================
 *                                       INCLUDES
==================================================================================================*/

#include "Platform_types.h"

/*==================================================================================================*
 *                                       Base addresses for AHB Peripheral
 *==================================================================================================*/

#define RCC_BASE										( 0x40021000UL )

/*==================================================================================================*
 *                                       Peripheral registers
 *==================================================================================================*/

typedef struct
{
	volatile uint32 CR;
	volatile uint32 CFGR;
	volatile uint32 CIR;
	volatile uint32 APB2RSTR;
	volatile uint32 APB1RSTR;
	volatile uint32 AHBENR;
	volatile uint32 APB2ENR;
	volatile uint32 APB1ENR;
	volatile uint32 BDCR;
	volatile uint32 CSR;
} RCC_RegisterType;


/*==================================================================================================*
 *                                       Peripheral Instants
 *==================================================================================================*/

#define RCC_REG 				((RCC_RegisterType  *)RCC_BASE  )




#endif /* REG_ESYS_RCC_H_ */
