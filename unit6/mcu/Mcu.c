/*************************************************************************************************************************************
@file           Mcu.c
@version        1.0.0
@brief          AUTOSAR MCU Driver (STM32F103X6).
@details        AUTOSAR 4.4.0 MCU module implementation. Provides initialization and 
                control of the microcontroller clock, PLL configuration, reset handling, 
                and low power mode transitions.
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
/*==================================================================================================
 *                                       INCLUDES
==================================================================================================*/
#include "Mcu.h"


#define CLK_READY_TIMEOUT   100000uL

#define SWS_MASK 			0x3uL
#define SWS_POS   			2uL


Std_ReturnType Mcu_InitClock(void)
{
    Std_ReturnType ret    = E_OK;
    uint32         timeout= CLK_READY_TIMEOUT;

#if (SYS_CLK_SRC == HSI)

    /* 1- Enable HSI */
    RCC_REG->CR |= (1UL << HSION);

    /* 2- Wait for HSIRDY  *//* real autosar driver  Mcu_InitClock non blocking*/
    while( ((RCC_REG->CR & (1UL << HSIRDY)) == 0u) && (timeout > 0u) )
    {
        timeout--;
    }

    if(timeout == 0u)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /* 3- Select HSI as system clock: SW = 00 */
        RCC_REG->CFGR &= ~((1UL << SW0) | (1UL << SW1));

    }

#elif (SYS_CLK_SRC == HSE)

    /* 1- Configure bypass BEFORE enabling */
  #if (HSE_BYPASS_MODE == BYPASSED)
    RCC_REG->CR |= (1UL << HSEBYP);
  #else
    RCC_REG->CR &= ~(1UL << HSEBYP);
  #endif

    /* 2- Enable HSE */
    RCC_REG->CR |= (1UL << HSEON);

    /* 3- Wait for HSERDY  */
    while( ((RCC_REG->CR & (1UL << HSERDY)) == 0u) && (timeout > 0u) )
    {
        timeout--;
    }

    if(timeout == 0u)
    {
        ret = E_NOT_OK;
    }
    else
    {
        /* 4- Select HSE as system clock: SW = 01 */
        RCC_REG->CFGR |=  (1UL << SW0);
        RCC_REG->CFGR &= ~(1UL << SW1);
    }

#elif (SYS_CLK_SRC == PLL)
    /* to be continued */
	#error "PLL path not implemented yet"
#else
    #error "Invalid SYS_CLK_SRC configuration"
#endif

    if (ret == E_OK)
        {
        	timeout = CLK_READY_TIMEOUT;
            /*SWS: System clock switch status */
        	/* check which source is selected */
            while ( (((RCC_REG->CFGR >> SWS_POS) & SWS_MASK) != (uint32)SYS_CLK_SRC)
                    && (timeout > 0u) )
            {
                timeout--;
            }

            if (timeout == 0u)
            {
                ret = E_NOT_OK;
            }


        }

    return ret;
}






