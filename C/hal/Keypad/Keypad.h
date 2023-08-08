#ifndef KEYPAD_H_
#define KEYPAD_H_

#define NOTPRESSED (0xff)

typedef struct keyadPin_t
{
    port_t port;
    pin_t pin;
}keyadPin_t;

typedef struct keypad_t
{
    keyadPin_t Keypad_RowArr[Keypad_numberOfRows];
    keyadPin_t Keypad_COLArr[Keypad_numberOfCols];
}keypad_t;


error_t Keypad_Init(keypad_t * pKeypad);
uint8_t Keypad_GetPressedButton(void);

#endif
