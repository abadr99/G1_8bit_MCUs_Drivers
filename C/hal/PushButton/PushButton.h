#ifndef PushButton_H
#define PushButton_H

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
               }PushButton_t;

void PushButton_Init(PushButton_t* pPB);
PressedState_t PushButton_GetValue(PushButton_t* pPB);
#endif
