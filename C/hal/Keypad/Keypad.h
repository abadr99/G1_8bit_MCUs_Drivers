#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "Config.h"

#define NOTPRESSED (0xff)

/**
 * @brief  keyadPin_t: is the data type to define the keypad pin
 *         port  : for avr [kPORTA ... kPORTD], for pic [kPORTA ... kPORTE]
 *         pin   : [kPIN0 ... kPIN7]
 */
typedef struct keyadPin_t
{
    port_t port;
    pin_t pin;
}keypadPin_t;
/**
 * @brief keypad_t:is the data type to define the keypad as
 * two arrays one for columuns and the other for rows.
 */
typedef struct keypad_t
{
    keypadPin_t Keypad_RowArr[Keypad_numberOfRows];
    keypadPin_t Keypad_COLArr[Keypad_numberOfCols];
}keypad_t;
 /**
  * @brief This Function is used to initialize the keypad
  * @param pKeypad pointer to the keypad which is a struct from type keypad_t.
  * @return error_t This Function returns kNoError if the Parameter is correct
  *                 and returns kFunctionParameterError
  *                 if the Parameter isn't correct
  */
error_t Keypad_Init(keypad_t * pKeypad);
/**
 * @brief This Function is used to get which button was pressed in  the keypad
 * @param pKeypad pointer to the keypad which is a struct from type keypad_t.
 * @return uint8_t  return the value which was pressed from the keypad
 */
uint8_t Keypad_GetPressedButton(keypad_t * pKeypad);

#endif
