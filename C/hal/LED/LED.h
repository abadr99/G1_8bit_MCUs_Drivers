#ifndef _LED_H_
#define _LED_H_

typedef enum
{
    ActiveLow,
    ActiveHigh,
}LedState_t;

typedef struct 
{
    port_t Port;
    pin_t Pin;
    LedState_t ActiveState;
}LED_t;

void LED_Init(LED_t* pLED);
error_t LED_TurnOn(LED_t* pLED);
error_t LED_TurnOff(LED_t* pLED);
#endif