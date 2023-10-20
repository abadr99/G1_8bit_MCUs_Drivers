#include "../../../common/Types.h"
#include "../../../common/Utils.h"
#include "../../../common/Config.h"
#include "../../../common/Registes.h"
#include "../../../mcal/GPIO/GPIO.h"
#include "../../../hal/Keypad/Keypad_config_only_one.h"
#include "../../../hal/Keypad/Keypad_only_one.h"
#include "../../../hal/LCD/LCD_Interface.h"
#include "../../../utils/stack/stack.h"
#include "Calc.h"

error_t Calculator(keypad_t * pKeypad, lcd_t * pLCD)
{
    error_t retErrorState = kNoError;
    if (pKeypad != NULL_PTR && pLCD != NULL_PTR)
    {
        uint8_t inputChar;
        f32_t inputNum=0;
        f32_t result;
        f32_tStack_t numStack;
        charStack_t opStack;
        f32_tStack_Init(&numStack);
        charStack_Init(&opStack);
        while (1)
        {
            inputChar = Input(pKeypad);
            if (inputChar != NOT_PRESSED)
            {
                Output(pLCD, inputChar);
                if (inputChar >= '0' && inputChar <= '9')
                {
                    inputNum = inputNum *10 +(inputChar - '0');
                }
                else if (inputChar == '.')
                {
                    // later
                }
                else if (inputChar == '=')
                {
                    f32_tStack_Push(&numStack, inputNum);
                    result = IsEqual(&opStack, &numStack);
                    DisplayResult(pLCD, result);
                }
                else if (inputChar == 'C')
                {
                    LCD_ClearScreen(pLCD);
                    f32_tStack_Clear(&numStack);
                    charStack_Clear(&opStack);
                    inputNum=0;
                }
                else
                {
                    f32_tStack_Push(&numStack, inputNum);
                    inputNum=0;
                    PushOp(&opStack, &numStack, inputChar, pLCD);
                }
            }
        }
    }
    else
    {
        retErrorState = kFunctionParameterError;
    }
    return retErrorState;
}
uint8_t Input(keypad_t * pKeypad)
{
    uint8_t input=NOT_PRESSED;
    input = Keypad_GetPressedButton(pKeypad);
    return input;
}
void Output(lcd_t * pLCD, uint8_t outputChar)
{
    if (outputChar != '=')
    {
    LCD_SendChar(pLCD, outputChar);
    }
}
f32_t Evaluate(f32_t num1, f32_t num2, uint8_t op)
{
    f32_t result=0;
    switch (op)
    {
    case '+': result = num1 + num2; break;
    case '-': result = num1 - num2; break;
    case '*': result = num1 * num2; break;
    case '/': result = num1 / num2; break;
    }
    return result;
}
uint8_t Priority(char op)
{
    f32_t retVal=0;
    switch (op)
    {
        case '+':
        case '-': retVal = 1;
        break;
        case '*':
        case '/': retVal = 2;
        break;
    }
    return retVal;
}
void PushOp(charStack_t * opStack, f32_tStack_t * numStack, uint8_t op, lcd_t * pLCD)
{
    f32_t num1, num2, result;
    if (charStack_GetSize(opStack) == 0)
    {
        charStack_Push(opStack, op);
    }
    else
    {
        if (Priority(op) > Priority(charStack_GetTop(opStack)))
        {
            charStack_Push(opStack, op);
        }
        else
        {
            while (Priority(op) <= Priority(charStack_GetTop(opStack)))
            {
            num2 = f32_tStack_GetTop(numStack);
            f32_tStack_Pop(numStack);
            num1 = f32_tStack_GetTop(numStack);
            f32_tStack_Pop(numStack);
            result = Evaluate(num1, num2, charStack_GetTop(opStack));
            f32_tStack_Push (numStack, result);
            charStack_Pop(opStack);
            }
            charStack_Push(opStack, op);
        }
    }
}
f32_t  IsEqual(charStack_t * opStack, f32_tStack_t * numStack)
{
    f32_t num1, num2, result;
    while (charStack_GetSize(opStack) != 0)
    {
        num1=0;
        num2=0;
        num2 = f32_tStack_GetTop(numStack);
        f32_tStack_Pop(numStack);
        num1 = f32_tStack_GetTop(numStack);
        f32_tStack_Pop(numStack);
        result = Evaluate(num1, num2, charStack_GetTop(opStack));
        f32_tStack_Push (numStack, result);
        charStack_Pop(opStack);
    }
    result = f32_tStack_GetTop(numStack);
    return result;
}
void DisplayResult(lcd_t  * pLCD, f32_t result)
{
    LCD_SetPosition(pLCD, LCD_ROW_2, LCD_COL_1);
    LCD_SendChar(pLCD, '=');
    LCD_SendFloat(pLCD, result);
}
