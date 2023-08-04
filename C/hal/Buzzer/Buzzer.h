#ifndef BUZZER_H_
#define BUZZER_H

typedef enum
{
    kBuzzerActiveLow,
    kBuzzerActiveHigh,
}BuzzerState_t;

typedef struct
{
    port_t port;
    pin_t pin;
    BuzzerState_t activeState;
}Buzzer_t;

void Buzzer_Init(Buzzer_t* pBuzzer);
error_t Buzzer_TurnOn(Buzzer_t* pBuzzer);
error_t Buzzer_TurnOff(Buzzer_t* pBuzzer);
#endif
