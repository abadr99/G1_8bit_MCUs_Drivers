#ifndef GPIO_H
#define GPIO_H

typedef enum {
    kLow,
    kHigh
             }state_t;

typedef enum {
    kInput,
    kOutput
             }direction_t;


typedef enum {
    kOutput_PORT = 0xff,
    kInput_PORT  = 0x00
             }port_direction_t;
error_t GPIO_SetPinDirection(port_t pPortNumber, pin_t pin,
                             direction_t direction);
error_t GPIO_SetPinValue(port_t PortNumber, pin_t PinNumber,
                         state_t PintVoltageLevel);
error_t GPIO_GetPinValue(port_t PortNumber, pin_t PinNumber, state_t * state);
error_t GPIO_SetPortDirection(port_t PortNumber, uint8_t PortValue);
error_t GPIO_SetPortValue(port_t PortNumber, uint8_t PintVoltageLevel);
error_t GPIO_GetPortValue(port_t PortNumber, uint8_t * state);


error_t GPIO_SetLowNibbleValue(port_t PortNumber, uint8_t Value);
error_t GPIO_SetHighNibbleValue(port_t PortNumber, uint8_t Value);

error_t GPIO_SetHighNibbleDirection(port_t PortNumber, uint8_t Direction);
error_t GPIO_SetLowNibbleDirection(port_t PortNumber, uint8_t Direction);
#endif /* _GPIO_H_ */
