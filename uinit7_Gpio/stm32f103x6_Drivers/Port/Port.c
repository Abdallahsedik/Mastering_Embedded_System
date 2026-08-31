/*************************************************************************************************************************************
@file           Port.c
@version        1.0.0
@brief          AUTOSAR PORT Driver  (STM32F103X6).
@details        AUTOSAR 4.4.0 PORT module interface. Provides pin initialization,
                mode configuration, and alternate function selection for all GPIO ports.
                This module owns the GPIO and AFIO peripheral initialization at startup.
@author         abdallah mohamed sedik
*************************************************************************************************************************************/

/*************************************************************************************************************************************
Project         : AUTOSAR 4.4.0 MCAL
Platform        : ARM Cortex-M3
MCU             : STM32F103X6
Package         : LQFP48
Module          : PORT
Autosar Version : 4.4.0
Vendor Release  : R24-11
Autosar Revision: ASR_REL_4_4_REV_0000
Sw Version      : 1.0.0
*************************************************************************************************************************************/

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PORT_VENDOR_ID              43U      /* fake id number  — real AUTOSAR assigns vendor IDs officially */
#define PORT_MODULE_ID              124U     /* AUTOSAR-standard module ID for PORT is 124 */

#define PORT_SW_MAJOR_VERSION       1U
#define PORT_SW_MINOR_VERSION       0U
#define PORT_SW_PATCH_VERSION       0U
/*==================================================================================================
 *                                       INCLUDES
==================================================================================================*/

#include "Port.h"


/*==================================================================================================
 *                                       LOCAL MACROS AND DEFINITIONS
 ==================================================================================================*/

#define PORT_PIN_ID(PortIdx, PinNum)   ((Port_PinType)(((PortIdx) << 4U) | (PinNum)))

#define PORT_GET_PORT_IDX(PinId)       ((uint8)(((PinId) >> 4U) & 0x0FU))
#define PORT_GET_PIN_NUM(PinId)        ((uint8)((PinId) & 0x0FU))

/*==================================================================================================
 *                                       LOCAL DATA AND CONSTANTS
 ==================================================================================================*/
/* Index = Port_PinModeType value. Value = packed CNF[1:0]:MODE[1:0] nibble.
   MODE bits fixed at speed=01 (10MHz) for all outputs; PU/PD ODR handled separately. */
static const uint8 Port_ModeToCr[8] =
{
    /* PORT_PIN_MODE_ANALOG      */ 0x0U,   /* CNF=00 MODE=00 */
    /* PORT_PIN_MODE_INPUT_FLOAT */ 0x4U,   /* CNF=01 MODE=00 */
    /* PORT_PIN_MODE_INPUT_PU    */ 0x8U,   /* CNF=10 MODE=00 */
    /* PORT_PIN_MODE_INPUT_PD    */ 0x8U,   /* CNF=10 MODE=00 (same as PU, ODR sets which) */
    /* PORT_PIN_MODE_OUTPUT_PP   */ 0x1U,   /* CNF=00 MODE=01 */
    /* PORT_PIN_MODE_OUTPUT_OD   */ 0x5U,   /* CNF=01 MODE=01 */
    /* PORT_PIN_MODE_AF_PP       */ 0x9U,   /* CNF=10 MODE=01 */
    /* PORT_PIN_MODE_AF_OD       */ 0xDU    /* CNF=11 MODE=01 */
};


/*==================================================================================================
 *                                       GLOBAL FUNCTION DEFINITIONS
 ==================================================================================================*/
/*
 * Service name: Port_Init
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): ConfigPtr Pointer to configuration set.
 * Parameters(inout):None
 * Parameters (out): None
 * Return value:     None
 * Description: Initializes the Port Driver module.
*/
//void Port_Init ( const Port_ConfigType* ConfigPtr ){}


/*
 * Service name: Port_SetPinDirection
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Pin       -> Port Pin ID number
                    Direction -> Port Pin Direction
 * Parameters (inout): None
 * Parameters (out):   None
 * Return value:       None
 * Description: Sets the port pin direction
*/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection(Port_PinType Pin,Port_PinDirectionType Direction)
{

		 uint8 portIdx = PORT_GET_PORT_IDX(Pin);
		 uint8 pinNum  = PORT_GET_PIN_NUM(Pin);

	      Gpio_RegisterType* gpio = Port_GpioLookup[portIdx];   // one array index, no switch
	      volatile uint32* cr = (pinNum < 8U) ? &gpio->CRL : &gpio->CRH; //decide which one of them should used (CRL vs CRH)
	      uint8 pos = (uint8)((pinNum & 0x07U) * 4U);

	      *cr &= ~(0x3UL << pos);                 // clear MODE bits only, keep CNF

	      if (Direction == PORT_PIN_OUT)
	      {
	          *cr |= (0x1UL << pos);              // MODE=01 (10MHz default)
	      }
}
#endif

/*
 * Service name: Port_SetPinMode
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in):     Pin  ->  Port Pin ID number
                        Mode -> New Port Pin mode to be set on port pin.
 * Parameters (inout):  None
 * Parameters (out):    None
 * Return value:        None
 * Description: Sets the port pin mode.
*/
#if (PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode(Port_PinType Pin,Port_PinModeType Mode)
{
	 	uint8 portIdx = PORT_GET_PORT_IDX(Pin);
	    uint8 pinNum  = PORT_GET_PIN_NUM(Pin);

	    Gpio_RegisterType* gpio = Port_GpioLookup[portIdx];
	    volatile uint32* cr = (pinNum < 8U) ? &gpio->CRL : &gpio->CRH;
	    uint8 pos = (uint8)((pinNum & 0x07U) * 4U);

	    *cr &= ~(0xFUL << pos);                          // clear full CNF+MODE nibble (4 bits, not 2)
	    *cr |= ((uint32)Port_ModeToCr[Mode] << pos);      // OR in looked-up pattern

	    if (Mode == PORT_PIN_MODE_INPUT_PU)
	    {
	        gpio->ODR |= (1UL << pinNum);                 // pull-up: ODR=1
	    }
	    else if (Mode == PORT_PIN_MODE_INPUT_PD)
	    {
	        gpio->ODR &= ~(1UL << pinNum);                // pull-down: ODR=0
	    }
}
#endif
/*
 * Service name: Port_GetVersionInfo
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in):     None
 * Parameters (inout):  None
 * Parameters (out): versioninfo Pointer to where to store the version information of this module.
 * Return value:        None
 * Description: Returns the version information of this module.
*/
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
    if (versioninfo != NULL_PTR)
    {
        versioninfo->vendorID         = PORT_VENDOR_ID;
        versioninfo->moduleID         = PORT_MODULE_ID;
        versioninfo->sw_major_version = PORT_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = PORT_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = PORT_SW_PATCH_VERSION;
    }
    /* else: DET error PORT_E_PARAM_POINTER, if Det is enabled */
}

#endif
