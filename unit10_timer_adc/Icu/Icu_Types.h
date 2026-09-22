#ifndef ICU_TYPES_H
#define ICU_TYPES_H

#include "Std_Types.h"

typedef enum {
    ICU_CHANNEL_SENSOR1 = 0,   /* TIM1_CH1 */
    ICU_CHANNEL_SENSOR2,       /* TIM1_CH2 */
    ICU_CHANNEL_MAX
} Icu_ChannelType;

typedef enum {
    ICU_RISING_EDGE = 0,
    ICU_FALLING_EDGE,
    ICU_BOTH_EDGES
} Icu_EdgeType;

typedef uint32 Icu_ValueType;

typedef struct {
    Icu_ChannelType channelId;
    Icu_EdgeType    activationEdge;   /* أول edge نبدأ نـ capture بيه */
} Icu_ConfigType;

#endif