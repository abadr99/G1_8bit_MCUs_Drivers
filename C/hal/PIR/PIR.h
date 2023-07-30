#ifndef PIR_H_
#define PIR_H

typedef struct {
    port_t Port;
    pin_t Pin;
               }PIR_t;

error_t PIR_Init(PIR_t* pPIR);
error_t PIR_GetVal(PIR_t* pPIR, state_t * state);
#endif
