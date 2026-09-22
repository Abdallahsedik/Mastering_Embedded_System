/*************************************************************************************************************************************
@file           Reg_eSys_Gpt.h
@version        1.0.0
@brief          GPT Registers Definitions  (STM32F103X6).
@details        Memory-mapped register definitions and bit field masks for the STM32F103X6
                General Purpose Timer peripherals (TIM2/TIM3). Defines structure overlays
                for control registers (CR1, CR2, DIER), status registers (SR), interrupt
                enable/mask registers, prescaler (PSC), auto-reload (ARR), and counter
                (CNT) registers.
@author         abdallah mohamed sedik
*************************************************************************************************************************************/

/*************************************************************************************************************************************
Project         : AUTOSAR 4.4.0 MCAL
Platform        : ARM Cortex-M3
MCU             : STM32F103X6
Package         : LQFP48
Module          : GPT
Autosar Version : 4.4.0
Vendor Release  : R24-11
Autosar Revision: ASR_REL_4_4_REV_0000
Sw Version      : 1.0.0
*************************************************************************************************************************************/

#ifndef REG_ESYS_GPT_H
#define REG_ESYS_GPT_H

#include "Std_Types.h"

#define TIM2_BASE   (0x40000000UL)
#define TIM3_BASE   (0x40000400UL)
typedef struct 
{
   volatile uint32 CR1;
   volatile uint32 CR2;
   volatile uint32 SMCR;
   volatile uint32 DIER;
   volatile uint32 SR;
   volatile uint32 EGR;
   volatile uint32 CCMR1;
   volatile uint32 CCMR2;
   volatile uint32 CCER;
   volatile uint32 CNT;
   volatile uint32 PSC;
   volatile uint32 ARR;
   volatile uint32 RESERVED;
   volatile uint32 CCR1;
   volatile uint32 CCR2;
   volatile uint32 CCR3;
   volatile uint32 CCR4;
   volatile uint32 RESERVED2;
   volatile uint32 DCR;
   volatile uint32 DMAR;
}Gpt_RegisterType;

#define GPT2_REG               ((Gpt_RegisterType *)TIM2_BASE)
#define GPT3_REG               ((Gpt_RegisterType *)TIM3_BASE)

#define TIM_CR1_OPM        3
#define TIM_CR1_CEN        0
#define TIM_SR_UIF   	   0

#endif