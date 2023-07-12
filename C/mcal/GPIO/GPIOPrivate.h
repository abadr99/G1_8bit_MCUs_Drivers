#ifndef _GPIO_PRIVATE_H_
#define _GPIO_PRIVATE_H_

typedef enum port_t {
    PORTA,
    PORTB,
    PORTC,
    PORTD,
    #if MCU_TYPE == PIC
    PORTE,
    #endif
}port_t;

typedef enum pin_t {
    kPin0,
    kPin1,
    kPin2,
    kPin4,
    kPin5,
    kPin6,
    kPin7,
}pin_t;

typedef enum state_t {
    kLow,
    kHigh,
}state_t;

typedef enum direction_t {
    kInput,
    kOutput,
}state_t;


#endif //_GPIO_PRIVATE_H_