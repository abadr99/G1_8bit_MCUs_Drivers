#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/*
Set Prescaler      1-ENABLED 
                   2-DISABLED
*/
#define TIMER0_PRESCALER_SET  ENABLED

/*
Configure Prescaler  1-TIMER0_PRESCALER_DIV_BY_2  
               2-TIMER0_PRESCALER_DIV_BY_4  
               3-TIMER0_PRESCALER_DIV_BY_8  
               4-TIMER0_PRESCALER_DIV_BY_16 
               5-TIMER0_PRESCALER_DIV_BY_32 
               6-TIMER0_PRESCALER_DIV_BY_64 
               7-TIMER0_PRESCALER_DIV_BY_128
               8-TIMER0_PRESCALER_DIV_BY_256
*/
#define TIMER0_PRESCALER_VALUE  TIMER0_PRESCALER_DIV_BY_2

/*
Configure Timer Mode 1-TIMER_MODE
                     2-COUNTER_MODE
*/
#define TIMER0_MODE  TIMER_MODE

/*
Configure Edge For Counter Mode 1-RAISING_EDGE
                                2-FALING_EDGE 
*/
#define TIMER0_COUNTER_EDGE   RAISING_EDGE

/*
Configure TIMER0 Register Size 1-TIMER_8BIT 
                               2-TIMER_16BIT
*/
#define TIMER0_REG_SIZE TIMER_8BIT

/*
Set TIMER0 Interrupt   1-ENABLED
                       2-DISABLED
*/
#define TIMER0_INTERRUPT ENABLED



#endif