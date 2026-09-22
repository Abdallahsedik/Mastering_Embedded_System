#include "Icu.h"
#define RCC_APB2ENR_TIM1EN 1

const Icu_ConfigType Icu_Config[] =
{
    {ICU_CHANNEL_SENSOR1, ICU_RISING_EDGE},   
    {ICU_CHANNEL_SENSOR2, ICU_RISING_EDGE}
};
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
    Icu_EdgeType    activationEdge;  
} Icu_ConfigType;

typedef struct {
    Gpt_RegisterType* timReg;      /* which Timer           */
    uint8             timChannel;  /* which channel: 1,2,3,4*/
    volatile uint32*  clockReg;    /* which RCC register    */
    uint8             clockBit;
} Icu_HwDescriptorType;

static const Icu_HwDescriptorType Icu_HwDescriptor[ICU_CHANNEL_MAX] =
{
    [ICU_CHANNEL_SENSOR1] = { TIM1_REG, 1, &RCC_REG->APB2ENR, RCC_APB2ENR_TIM1EN },
    [ICU_CHANNEL_SENSOR2] = { TIM1_REG, 2, &RCC_REG->APB2ENR, RCC_APB2ENR_TIM1EN }
};
static volatile uint32* Icu_GetCcmrReg(Gpt_RegisterType* timReg, uint8 timChannel)
{
    if (timChannel <= 2)
    {
        return &timReg->TIMx_CCMR1;
    }
    else
    {
        return &timReg->TIMx_CCMR2;
    }
}
void Icu_Init(const Icu_ConfigType* configPtr)
{
    if (configPtr->channelId >= ICU_CHANNEL_MAX)
    {
        return;
    }

    const Icu_HwDescriptorType* icu_ptr = &Icu_HwDescriptor[configPtr->channelId];

    /* 1. Enable peripheral clock */
    *(icu_ptr->clockReg) |= (1 << icu_ptr->clockBit);

    /* 2. Set as Input Capture direct (CCxS = 01) */
    volatile uint32* ccmrReg = Icu_GetCcmrReg(icu_ptr->timReg, icu_ptr->timChannel);
    uint8 ccmrShift = ((icu_ptr->timChannel - 1) % 2) * 8;
    *ccmrReg &= ~(0x3 << ccmrShift);
    *ccmrReg |= (0x1 << ccmrShift);

    /* 3. Set edge polarity (CCxP) - ده منتظم على طول، مفيش تغيير */
    uint8 ccerShift = (icu_ptr->timChannel - 1) * 4;
    icu_ptr->timReg->TIMx_CCER &= ~(1 << (ccerShift + 1));
    if (configPtr->activationEdge == ICU_FALLING_EDGE)
    {
        icu_ptr->timReg->TIMx_CCER |= (1 << (ccerShift + 1));
    }

    /* 4. Enable capture (CCxE) */
    icu_ptr->timReg->TIMx_CCER |= (1 << ccerShift);
}


