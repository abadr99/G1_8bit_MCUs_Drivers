#ifndef TIMER_PRIVATE_H_ 
#define TIMER_PRIVATE_H_

#define TIMER0_TMR0ON       (7)
#define TIMER0_T08BIT       (6)
#define TIMER0_T0CS         (5)
#define TIMER0_T0SE         (4)
#define TIMER0_PSA          (3)
#define TIMER0_T0PS2        (2)
#define TIMER0_T0PS1        (1)
#define TIMER0_T0PS0        (0)

#define INTCON_PEIE         (6)
#define INTCON_TMR0IE       (5)
#define INTCON_TMR0IF       (2)

#define DISABLED            (0)
#define ENABLED             (1)

#define TIMER0_PRESCALER_DIV_BY_2       (0)
#define TIMER0_PRESCALER_DIV_BY_4       (1)
#define TIMER0_PRESCALER_DIV_BY_8       (2)
#define TIMER0_PRESCALER_DIV_BY_16      (3)
#define TIMER0_PRESCALER_DIV_BY_32      (4)
#define TIMER0_PRESCALER_DIV_BY_64      (5)
#define TIMER0_PRESCALER_DIV_BY_128     (6)
#define TIMER0_PRESCALER_DIV_BY_256     (7)

#define TIMER0_PRESCALER_MASK   (0b11111000)

#define TIMER_MODE        (1)
#define COUNTER_MODE      (2)

#define RAISING_EDGE    (1)
#define FALING_EDGE     (2)

#define TIMER_8BIT          (0)
#define TIMER_16BIT         (1)

#endif
