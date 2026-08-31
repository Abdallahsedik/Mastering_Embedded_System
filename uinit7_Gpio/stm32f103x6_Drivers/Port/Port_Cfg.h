/*************************************************************************************************************************************
@file           Port_Cfg.h
@version        1.0.0
@brief          AUTOSAR PORT Driver Configuration Header (STM32F103X6).
@details        AUTOSAR 4.4.0 PORT module configuration. Contains the post-build and pre-compile
                configuration parameters, pin definitions, and configuration structures used to
                initialize the GPIO and AFIO peripherals based on the specific application requirements.
@author         abdallah mohamed sedik
*************************************************************************************************************************************/

/*************************************************************************************************************************************
Project         : AUTOSAR 4.4.0 MCAL
Platform        : ARM Cortex-M3
MCU             : STM32F103X6
Package         : LQFP48
Module          : PORT (Configuration)
Autosar Version : 4.4.0
Vendor Release  : R24-11
Autosar Revision: ASR_REL_4_4_REV_0000
Sw Version      : 1.0.0
*************************************************************************************************************************************/

#ifndef PORT_CFG_H_
#define PORT_CFG_H_

/*==================================================================================================
 *                                       INCLUDES
==================================================================================================*/
#include "Platform_types.h"

/*==================================================================================================
 *                                       CONFIGURATION
==================================================================================================*/


/* Port A — fully available (16 pins) */
#define PORT_PIN_PA0     PORT_PIN_ID(PORTA_IDX, 0U)
#define PORT_PIN_PA1     PORT_PIN_ID(PORTA_IDX, 1U)
#define PORT_PIN_PA2     PORT_PIN_ID(PORTA_IDX, 2U)
#define PORT_PIN_PA3     PORT_PIN_ID(PORTA_IDX, 3U)
#define PORT_PIN_PA4     PORT_PIN_ID(PORTA_IDX, 4U)
#define PORT_PIN_PA5     PORT_PIN_ID(PORTA_IDX, 5U)
#define PORT_PIN_PA6     PORT_PIN_ID(PORTA_IDX, 6U)
#define PORT_PIN_PA7     PORT_PIN_ID(PORTA_IDX, 7U)
#define PORT_PIN_PA8     PORT_PIN_ID(PORTA_IDX, 8U)
#define PORT_PIN_PA9     PORT_PIN_ID(PORTA_IDX, 9U)
#define PORT_PIN_PA10    PORT_PIN_ID(PORTA_IDX, 10U)
#define PORT_PIN_PA11    PORT_PIN_ID(PORTA_IDX, 11U)
#define PORT_PIN_PA12    PORT_PIN_ID(PORTA_IDX, 12U)
#define PORT_PIN_PA13    PORT_PIN_ID(PORTA_IDX, 13U)
#define PORT_PIN_PA14    PORT_PIN_ID(PORTA_IDX, 14U)
#define PORT_PIN_PA15    PORT_PIN_ID(PORTA_IDX, 15U)

/* Port B — fully available (16 pins) */
#define PORT_PIN_PB0     PORT_PIN_ID(PORTB_IDX, 0U)
#define PORT_PIN_PB1     PORT_PIN_ID(PORTB_IDX, 1U)
#define PORT_PIN_PB2     PORT_PIN_ID(PORTB_IDX, 2U)
#define PORT_PIN_PB3     PORT_PIN_ID(PORTB_IDX, 3U)
#define PORT_PIN_PB4     PORT_PIN_ID(PORTB_IDX, 4U)
#define PORT_PIN_PB5     PORT_PIN_ID(PORTB_IDX, 5U)
#define PORT_PIN_PB6     PORT_PIN_ID(PORTB_IDX, 6U)
#define PORT_PIN_PB7     PORT_PIN_ID(PORTB_IDX, 7U)
#define PORT_PIN_PB8     PORT_PIN_ID(PORTB_IDX, 8U)
#define PORT_PIN_PB9     PORT_PIN_ID(PORTB_IDX, 9U)
#define PORT_PIN_PB10    PORT_PIN_ID(PORTB_IDX, 10U)
#define PORT_PIN_PB11    PORT_PIN_ID(PORTB_IDX, 11U)
#define PORT_PIN_PB12    PORT_PIN_ID(PORTB_IDX, 12U)
#define PORT_PIN_PB13    PORT_PIN_ID(PORTB_IDX, 13U)
#define PORT_PIN_PB14    PORT_PIN_ID(PORTB_IDX, 14U)
#define PORT_PIN_PB15    PORT_PIN_ID(PORTB_IDX, 15U)


/* Port C — ONLY PC13, PC14, PC15 bonded out on LQFP48 */
#define PORT_PIN_PC13   PORT_PIN_ID(PORTC_IDX, 13U)
#define PORT_PIN_PC14   PORT_PIN_ID(PORTC_IDX, 14U)
#define PORT_PIN_PC15   PORT_PIN_ID(PORTC_IDX, 15U)

/* Port D — ONLY PD0, PD1 bonded out on LQFP48 */
#define PORT_PIN_PD0    PORT_PIN_ID(PORTD_IDX, 0U)
#define PORT_PIN_PD1    PORT_PIN_ID(PORTD_IDX, 1U)

// Port_PinModeType
#define PORT_PIN_MODE_ANALOG        0U
#define PORT_PIN_MODE_INPUT_FLOAT   1U
#define PORT_PIN_MODE_INPUT_PU      2U
#define PORT_PIN_MODE_INPUT_PD      3U
#define PORT_PIN_MODE_OUTPUT_PP     4U
#define PORT_PIN_MODE_OUTPUT_OD     5U
#define PORT_PIN_MODE_AF_PP         6U
#define PORT_PIN_MODE_AF_OD         7U

#endif /* PORT_CFG_H_ */
