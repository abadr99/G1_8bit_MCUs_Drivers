#ifndef KEYPAD_H_
#define KEYPAD_H_


#define NOTPRESSED (0xff)
#define MAXROW      (4)
#define MAXCOL      (6)
/**
 * A structure to represent keypadPin
 */
typedef struct keyadPin_t
{
    /*@{*/
    port_t port;/**< the port number */
    pin_t pin;/**< the pin number*/
    /*@}*/
}keypadPin_t;
/**
 * A structure to represent keypad
 */
typedef struct keypad_t
{
    /*@{*/
    /**< array of keypadPin_t represents rows */
    keypadPin_t Keypad_RowArr[MAXROW];
    /**< array of keypadPin_t represents columns */
    keypadPin_t Keypad_COLArr[MAXCOL];
    /**< represent number of rows*/
    uint8_t rowsize;
     /**< represent number of colmuns*/
    uint8_t colsize;
    /*@}*/
}keypad_t;
 /**
  * @brief This Function is used to initialize the keypad
  * @param pKeypad pointer to the keypad which is a struct from type keypad_t.
  * @return error_t This Function returns kNoError if the Parameter is correct
  *                 and returns kFunctionParameterError
  *                 if the Parameter isn't correct
  */
error_t Keypad_Initiate(keypad_t * pKeypad);
/**
 * @brief This Function is used to get which button was pressed in  the keypad
 * @param pKeypad pointer to the keypad which is a struct from type keypad_t.
 * @return uint8_t  return the value which was pressed from the keypad
 */
uint8_t Keypad_GetPressedButon(keypad_t * pKeypad, uint8_t keypadButtons[MAXROW][MAXCOL]);   //IGNORE-STYLE-CHECK[L004]

#endif
