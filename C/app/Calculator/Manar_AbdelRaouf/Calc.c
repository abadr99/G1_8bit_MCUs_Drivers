#include "../../../common/Types.h"
#include "../../../common/Utils.h"
#include "../../../common/Config.h"
#include "../../../common/Registes.h"
#include "../../../mcal/GPIO/GPIO.h"
#include "../../../hal/Keypad/Keypad_config_only_one.h"
#include "../../../hal/Keypad/Keypad_only_one.h"
#include "../../../hal/LCD/LCD_Interface.h"
#include "../../../Data_Structure/Stack/Stack_Config.h"
#include "../../../Data_Structure/Stack/Stack.h"
#include "Calc.h"

error_t Calculator(keypad_t * pKeypad, lcd_t * pLCD)
{
    error_t retErrorState = kNoError;
    if (pKeypad != NULL_PTR && pLCD != NULL_PTR)
    {
        f32_t inputChar;
        f32_t inputNum=0;
        f32_t result;
        Stack_t numStack, opStack;
        Stack_Init(& numStack);
        Stack_Init(&opStack);
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
                    Stack_Push(&numStack, inputNum);
                    result = IsEqual(&opStack, &numStack);
                    DisplayResult(pLCD, result);
                }
                else if (inputChar == 'C')
                {
                    LCD_ClearScreen(pLCD);
                    Clear_Stack(&numStack);
                    Clear_Stack(&opStack);
                    inputNum=0;
                }
                else
                {
                    Stack_Push(&numStack, inputNum);
                    inputNum=0;
                    PushOp(&opStack, &numStack, inputChar);
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
f32_t Input(keypad_t * pKeypad)
{
    f32_t input=NOT_PRESSED;
    input = Keypad_GetPressedButton(pKeypad);
    return input;
}
void Output(lcd_t * pLCD, f32_t outputChar)
{
    if (outputChar != '=')
    {
    LCD_SendChar(pLCD, (uint8_t)outputChar);
    }
}
f32_t Evaluate(f32_t num1, f32_t num2, f32_t op)
{
    f32_t result=0;
    switch ((uint8_t)op)
    {
    case '+': result = num1 + num2; break;
    case '-': result = num1 - num2; break;
    case '*': result = num1 * num2; break;
    case '/': result = num1 / num2; break;
    }
    return result;
}
uint8_t Priority(f32_t op)
{
    f32_t retVal=0;
    switch ((uint8_t)op)
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
void PushOp(Stack_t * opStack, Stack_t * numStack, f32_t op)
{
    f32_t num1, num2, result;
    if (Is_Empty (opStack))
    {
        Stack_Push(opStack, op);
    }
    else
    {
        if (Priority(op) > Priority(opStack->pTop->Value))
        {
            Stack_Push(opStack, op);
        }
        else
        {
            while (Priority(op) <= Priority(opStack->pTop->Value))
            {
            num2 = numStack->pTop->Value;
            Stack_Pop(numStack);
            num1 = numStack->pTop->Value;
            Stack_Pop(numStack);
            result = Evaluate(num1, num2, opStack->pTop->Value);
            Stack_Push (numStack, result);
            Stack_Pop(opStack);
            }
            Stack_Push(opStack, op);
        }
    }
}
f32_t  IsEqual(Stack_t * opStack, Stack_t * numStack)
{
    f32_t num1, num2, result;
    while ((Is_Empty(opStack)) == 0)
    {
        num1=0;
        num2=0;
        num2 = numStack->pTop->Value;
        Stack_Pop(numStack);
        num1 = numStack->pTop->Value;
        Stack_Pop(numStack);
        result = Evaluate(num1, num2, opStack->pTop->Value);
        Stack_Push (numStack, result);
        Stack_Pop(opStack);
    }
    result = numStack->pTop->Value;
    return result;
}
void DisplayResult(lcd_t  * pLCD, f32_t result)
{
    LCD_SetPosition(pLCD, LCD_ROW_2, LCD_COL_1);
    LCD_SendChar(pLCD, '=');
    LCD_SendFloat(pLCD, result);
}
