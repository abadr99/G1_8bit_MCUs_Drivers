#ifndef _LED_H_
#define _LED_H_

typedef enum
{
    LED_PORTA,
    LED_PORTB,
    LED_PORTC,
    LED_PORTD,
    #if MCU_TYPE == _PIC 
    LED_PORTE,
    #endif
}LED_PORT_t;

typedef enum
{
    LED_PIN0,
    LED_PIN1,
    LED_PIN2,
    LED_PIN3,
    LED_PIN4,
    LED_PIN5,
    LED_PIN6,
    LED_PIN7,
}LED_PIN_t;

typedef enum
{
    LED_ACTIVE_LOW,
    LED_ACTIVE_HIGH,
}LED_STATE_t;

typedef struct 
{
    uint8_t Port;
    uint8_t Pin;
    uint8_t ActiveState;
}LED_t;

void LED_Init(LED_t LED_Type);
void LED_LedOn(LED_t LED_Type);
void LED_LedOff(LED_t LED_Type);
#endif