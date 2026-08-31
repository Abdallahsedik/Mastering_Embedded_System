/*************************************************************************************************************************************
@file           Port.h
@version        1.0.0
@brief          AUTOSAR PORT Driver Header (STM32F103X6).
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

#ifndef PORT_H_
#define PORT_H_

/*==================================================================================================
 *                                       INCLUDES
==================================================================================================*/

#include "Reg_eSys_Gpio.h"
#include "Port_Cfg.h"
#include "Std_Types.h"



/********************************************************************
*@Name       : Port_PinType
*@Kind       : uint8
*@Range      : 0 - 15
*@Description: Data type for the symbolic name of a port pin.
********************************************************************/
typedef uint8  Port_PinType;


/********************************************************************
*@Name       : Port_PinDirectionType
*@Kind       : Enumeration
*@Range      : PORT_PIN_IN 0x00 Sets port pin as input ,PORT_PIN_OUT 0x01 Sets port pin as output.
*@Description: Possible directions of a port pin.
********************************************************************/
typedef enum
{
	PORT_PIN_IN =0x00,
	PORT_PIN_OUT=0x01

}Port_PinDirectionType;

/********************************************************************
*@Name       : Port_PinModeType
*@Kind       : uint8
*@Range      :
*@Description: Different port pin modes.
********************************************************************/
typedef uint8  Port_PinModeType;


/*==================================================================================================
 *                                      function Prototypes
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
//void Port_Init ( const Port_ConfigType* ConfigPtr );



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
/* The function Port_SetPinDirection shall set the port pin direction during runtime.*/
/*[SWS_Port_00054] The function Port_SetPinDirection shall be re-entrant if accessing
different pins independent of a port*/
/*The function Port_SetPinDirection shall only be available to the user if the precompile
parameter PortSetPinDirectionApi is set to TRUE. If set to FALSE, the
function Port_SetPinDirection is not available.*/

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection(Port_PinType Pin,Port_PinDirectionType Direction);
#endif

/*
 * Service name: Port_RefreshPortDirection
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in):    None
 * Parameters (inout): None
 * Parameters (out):   None
 * Return value:       None
 * Description: Refreshes port direction.
*/

/*{SWS_Port_00060}->The function Port_RefreshPortDirection shall refresh the direction of all configured
ports to the configured direction (PortPinDirection)*/

/*{SWS_Port_00061}->The function Port_RefreshPortDirection shall exclude those port pins from refreshing
that are configured as ’pin direction changeable during runtime*/
void Port_RefreshPortDirection(void);


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
/* {SWS_Port_00225}->dif Det is enabled, the parameter versioninfo shall be checked for being NULL.
 *  The error PORT_E_PARAM_POINTER shall be reported in case the value is a NULL pointer.*/
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);
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
void Port_SetPinMode(Port_PinType Pin,Port_PinModeType Mode);
#endif

/* [SWS_Port_00125] ->The function Port_SetPinMode shall set the port pin mode of
the referenced pin during runtime*/
/*[SWS_Port_00128] -> dThe function Port_SetPinMode shall be re-entrant if accessing
different pins, independent of a port.*/
/*[SWS_Port_00223] -> dIf Det is enabled, the function Port_SetPinMode shall report
PORT_E_MODE_UNCHANGEABLE error and return without any other action, if the parameter
PortPinModeChangeable is set to FALSE*/

#endif /* PORT_H_ */
