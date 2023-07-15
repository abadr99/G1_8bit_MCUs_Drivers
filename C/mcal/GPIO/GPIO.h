#ifndef _GPIO_H_
#define _GPIO_H_


typedef enum  {
    kPORTA,
    kPORTB,
    kPORTC,
    kPORTD
   
}PORT_t;

typedef enum  {
    kPIN0,
    kPIN1,
    kPIN2,
    kPIN4,
    kPIN5,
    kPIN6,
    kPIN7
}PIN_t;

typedef enum  {
    kLow,
    kHigh
}STATE_t;

typedef enum  {
    kInput,
    kOutput
}DIRECTION_t;


Error_t GPIO_SetPinDirection(PORT_t port,PIN_t pin , DIRECTION_t direction);
Error_t GPIO_SetPinValue(PORT_t PortNumber , PIN_t PinNumber , STATE_t PintVoltageLevel);

#endif /* _GPIO_H_ */