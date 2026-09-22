/*************************************************************************************************************************************
@file           Gpt.h
@version        1.0.0
@brief          AUTOSAR GPT Driver  (STM32F103X6).
@details        AUTOSAR 4.4.0 GPT module interface. Provides APIs for starting and stopping
                hardware timers, configuring notification callbacks, and controlling timer
                channels in one-shot or continuous modes, built on top of the timer
                peripherals (TIM2/TIM3) registers.
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


#ifndef GPT_H
#define GPT_H

#include "Reg_eSys_Gpt.h"
#include "Gpt_Cfg.h"
#include "Std_Types.h"

typedef enum {
    GPT_CHANNEL_TIM2 = 0,
    GPT_CHANNEL_TIM3,
    GPT_CHANNEL_MAX
} Gpt_ChannelType;

typedef enum {
    GPT_MODE_ONESHOT = 0,
    GPT_MODE_CONTINUOUS
} Gpt_ModeType;

typedef uint32 Gpt_ValueType;

typedef struct {
    Gpt_ChannelType channelId;
    uint16        prescaler;   /* PSC register value */
    Gpt_ModeType    mode;
} Gpt_ConfigType;
extern const Gpt_ConfigType Gpt_Config[];


void Gpt_Init(const Gpt_ConfigType* configPtr);

void Gpt_StartTimer(Gpt_ChannelType channel, Gpt_ValueType value);

void Gpt_StopTimer(Gpt_ChannelType channel);

Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType channel);



#endif