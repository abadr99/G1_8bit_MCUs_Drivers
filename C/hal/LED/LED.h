#ifndef _LED_H_
#define _LED_H_

typedef struct 
{
    port_t Port;
    pin_t Pin;
    state_t ActiveState;
}LED_t;

void LED_Init(LED_t* pLED_Configration);
error_t LED_TurnOn(LED_t* pLED_Configration);
error_t LED_TurnOff(LED_t* pLED_Configration);
#endif