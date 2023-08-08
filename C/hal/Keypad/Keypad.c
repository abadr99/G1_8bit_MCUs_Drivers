#include "../../common/Types.h"
#include "../../mcal/GPIO/GPIO.h"
#include "Config.h"
#include "Keypad.h"


error_t Keypad_Init(keypad_t * pKeypad)
{
    error_t retErrorState = kNoError;
    if (pKeypad != NULL)
    {
        uint8_t i;
        /*--------Set Rows Pin as Pullup Pin-------------*/
        for (i = 0; i < Keypad_numberOfRows; i++)
        {
            GPIO_SetPinPullup(pKeypad->Keypad_RowArr[i].port, pKeypad->Keypad_RowArr[i].pin);             //IGNORE-STYLE-CHECK[L004]
        }
        /*--------Set Columns Pin as Output Pin---------*/
        for (i = 0; i < Keypad_numberOfCols; i++)
        {
            GPIO_SetPinDirection(pKeypad->Keypad_COLArr[i].port, pKeypad->Keypad_COLArr[i].pin, kOutput); //IGNORE-STYLE-CHECK[L004]
        }
        /*--------Set Columns Pin as High---------------*/
        for (i = 0; i < Keypad_numberOfCols; i++)
        {
            GPIO_SetPinValue(pKeypad->Keypad_COLArr[i].port, pKeypad->Keypad_COLArr[i].pin, kHigh);        //IGNORE-STYLE-CHECK[L004]
        }
    }else
    {
        retErrorState = kFunctionParameterError;
    }
    return retErrorState;
}
uint8_t Keypad_GetPressedButton(keypad_t * pKeypad)
{
    uint8_t retValueButton = NOTPRESSED;
    uint8_t rowCount;
    uint8_t colCount;
    state_t buttonValue;
    state_t buttonIsPressed = kLow;
    for (colCount = 0; colCount<Keypad_numberOfCols; colCount++)
    {
        GPIO_SetPinValue(pKeypad->Keypad_COLArr[colCount].port, pKeypad->Keypad_COLArr[colCount].pin, kLow);                 //IGNORE-STYLE-CHECK[L004]
        for (rowCount = 0; rowCount < Keypad_numberOfRows; rowCount++)
        {
            GPIO_GetPinValue(pKeypad->Keypad_RowArr[rowCount].port, pKeypad->Keypad_RowArr[rowCount].pin, &buttonValue);     //IGNORE-STYLE-CHECK[L004]
            if (buttonValue == buttonIsPressed)
            {
                retValueButton = keypadButtons[rowCount][colCount];
            }
            while (buttonValue == buttonIsPressed)
            {
                GPIO_GetPinValue(pKeypad->Keypad_RowArr[rowCount].port, pKeypad->Keypad_RowArr[rowCount].pin, &buttonValue); //IGNORE-STYLE-CHECK[L004]
            }
            return retValueButton;
        }
        GPIO_SetPinValue(pKeypad->Keypad_COLArr[colCount].port, pKeypad->Keypad_COLArr[colCount].pin, kHigh);                //IGNORE-STYLE-CHECK[L004]
    }
    return retValueButton;
}
