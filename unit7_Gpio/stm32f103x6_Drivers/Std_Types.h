/*************************************************************************************************************************************
@file Std Types.h
@version 1.0.0
@brief AUTOSAR Base - Standard types definition.
@details AUTOSAR standard types header file.
It contains all types that are used across several modules of the basic software and that are platform and compiler independent
@author abdallah mohamed sedik
*************************************************************************************************************************************/

/*************************************************************************************************************************************
Project         : AUTOSAR 4.4.0 MCAL
Platform        : ARM Cortex-M3
MCU             : STM32F103X6
Package         : LQFP48
Autosar Version : 4.4.0
Vendor  Release : R24-11
Autosar Revision: ASR_REL_4_4_REV_0000
Sw Version      : 1.0.0
*************************************************************************************************************************************/


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#include "Platform_types.h"

#ifndef STD_ON
#define STD_ON   1u
#endif

#ifndef STD_OFF
#define STD_OFF  0u
#endif

#ifndef NULL_PTR
#define NULL_PTR ((void *)0)
#endif

#ifndef STD_LOW
#define STD_LOW     0x00U
#endif

#ifndef STD_HIGH
#define STD_HIGH    0x01U
#endif

typedef struct
{
    uint16 vendorID;
    uint16 moduleID;
    uint8  sw_major_version;
    uint8  sw_minor_version;
    uint8  sw_patch_version;
} Std_VersionInfoType;
#endif /* STD_TYPES_H_ */
