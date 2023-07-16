#ifndef _GPIO_H_
#define _GPIO_H_


typedef enum  {
    kPORTA,
    kPORTB,
    kPORTC,
    kPORTD
   
}port_t;

typedef enum  {
    kPIN0,
    kPIN1,
    kPIN2,
    kPIN4,
    kPIN5,
    kPIN6,
    kPIN7
}pin_t;

typedef enum  {
    kLow,
    kHigh
}state_t;

typedef enum  {
    kInput,
    kOutput
}direction_t;


error_t GPIO_SetPinDirection(port_t port,pin_t pin , direction_t direction);
error_t GPIO_SetPinValue(port_t PortNumber , pin_t PinNumber , state_t PintVoltageLevel);

#endif /* _GPIO_H_ */