#include "../../common/Types.h"
#include "../../mcal/GPIO/GPIO.h"
#include "Keypad.h"


error_t Keypad_Initiate(keypad_t * pKeypad)
{
    error_t retErrorState = kNoError;
    if (pKeypad != NULL)
    {
        uint8_t i;
        /*--------Set Rows Pin as Pullup Pin if AVR-------------*/
        #if MCU_TYPE == _AVR
        for (i = 0; i < Keypad_numberOfRows; i++)
        {
            GPIO_SetPinPullup(pKeypad->Keypad_RowArr[i].port,
                              pKeypad->Keypad_RowArr[i].pin);
        }
        /*--------Set Rows Pin as input  Pin if PIC-------------*/
        #elif MCU_TYPE == _PIC
        for (i = 0; i < Keypad_numberOfRows; i++)
        {
            GPIO_SetPinDirection(pKeypad->Keypad_RowArr[i].port,
                              pKeypad->Keypad_RowArr[i].pin);
        }
uint8_t Keypad_GetPressedKey(keypad_t * pKeypad, uint8_t keypadButtons[MAXROW][MAXCOL])       //IGNORE-STYLE-CHECK[L004]
{
    uint8_t retValueButton = NOT_PRESSED;
    uint8_t rowCount;
    uint8_t colCount;
    state_t buttonValue;
    state_t buttonIsPressed = kLow;
    for (colCount = 0; c; ++colCount)
    {
        GPIO_SetPinValue(pKeypad->Keypad_COLArr[colCount].port,
                         pKeypad->Keypad_COLArr[colCount].pin,
                         kLow);
        for (rowCount = 0; rowCount < pKeypad->numOfRow; rowCount++)
        {
            GPIO_GetPinValue(pKeypad->Keypad_RowArr[rowCount].port,
                             pKeypad->Keypad_RowArr[rowCount].pin,
                             &buttonValue);
            if (buttonValue == buttonIsPressed)
            {
                retValueButton = keypadButtons[rowCount][colCount];
            }
            while (buttonValue == buttonIsPressed)
            {
                GPIO_GetPinValue(pKeypad->Keypad_RowArr[rowCount].port,
                                 pKeypad->Keypad_RowArr[rowCount].pin,
                                 &buttonValue);
            }
            return retValueButton;
        }
        GPIO_SetPinValue(pKeypad->Keypad_COLArr[colCount].port,
                         pKeypad->Keypad_COLArr[colCount].pin,
                         kHigh);
    }
    return retValueButton;
}
