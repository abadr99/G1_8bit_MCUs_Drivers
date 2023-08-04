#ifndef LED_H_
#define LED_H

typedef enum
{
    kLedActiveLow,
    kLedActiveHigh,
}LedState_t;

typedef struct
{
    port_t port;
    pin_t pin;
    LedState_t activeState;
}LED_t;

void LED_Init(LED_t* pLED);
error_t LED_TurnOn(LED_t* pLED);
error_t LED_TurnOff(LED_t* pLED);
#endif
