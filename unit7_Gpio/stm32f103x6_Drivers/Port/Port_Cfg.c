
#include "Port.h"

static const Port_ConfigPinType Port_PinConfigTable[] =
{
    /* Port_Num  Pin_Num  Direction      Mode                          InitialValue */
    { GPIOA_ID,  PIN13,    PORT_PIN_OUT,  PORT_PIN_MODE_OUTPUT_PP,      STD_LOW  },
    { GPIOA_ID,  PIN12,    PORT_PIN_OUT,  PORT_PIN_MODE_OUTPUT_PP,      STD_LOW  },
    { GPIOA_ID,  PIN14,    PORT_PIN_OUT,  PORT_PIN_MODE_OUTPUT_PP,      STD_LOW  },
    { GPIOB_ID,  PIN0,    PORT_PIN_IN,   PORT_PIN_MODE_INPUT_FLOAT,    STD_LOW  },  /* button input           */
};

const Port_ConfigType Port_Config =
{
    .Pins         = Port_PinConfigTable,
    .NumberOfPins = (uint8)(sizeof(Port_PinConfigTable) / sizeof(Port_PinConfigTable[0]))
};
