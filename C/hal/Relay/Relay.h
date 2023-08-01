#ifndef RELAY_H
#define RELAY_H

typedef struct {
    port_t Port;
    pin_t Pin;
               }Relay_t;

error_t Relay_Init(Relay_t* pRelay);
error_t Relay_TurnOn(Relay_t* pRelay);
error_t Relay_TurnOff(Relay_t* pRelay);
#endif
