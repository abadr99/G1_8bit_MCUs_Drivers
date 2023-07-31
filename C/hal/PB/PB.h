#ifndef PB_H
#define PB_H

typedef enum {
    kNotPressed,
    kPressed,
             }PressedState_t;

typedef enum {
    kIntPullUp,
    kExtPullUp,
    kPullDown,
             }PullState_t;

typedef struct {
    port_t Port;
    pin_t Pin;
    PullState_t State;
               }PB_t;

void PB_Init(PB_t* pPB);
PressedState_t PB_GetPressed(PB_t* pPB);
#endif
