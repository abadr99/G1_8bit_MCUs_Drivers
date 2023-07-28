#ifndef _BUZZER_H_
#define _BUZZER_H_

typedef enum
{
    kBuzzerActiveLow,
    kBuzzerActiveHigh,
}BuzzerState_t;

typedef struct 
{
    port_t Port;
    pin_t Pin;
    BuzzerState_t ActiveState;
}Buzzer_t;

void Buzzer_Init(Buzzer_t* pBuzzer);
error_t Buzzer_TurnOn(Buzzer_t* pBuzzer);
error_t Buzzer_TurnOff(Buzzer_t* pBuzzer);
#endif