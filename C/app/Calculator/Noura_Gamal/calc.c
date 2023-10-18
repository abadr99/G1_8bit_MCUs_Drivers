#include <util/delay.h>
#include "../../../common/Types.h"
#include "../../../common/Utils.h"
#include "../../../utils/stack/stack.h"
#include "../../../hal/Keypad/Keypad_config_only_one.h"
#include "../../../hal/Keypad/Keypad_only_one.h"
#include "../../../hal/LCD/LCD_Interface.h"
#include "calc.h"

static uint8_t IsHigherPriority(uint8_t op);
static sint8_t Calculate(uint8_t op, sint8_t operand1, sint8_t operand2);

sint32_t num =0, num1=0, num2=0, op = 0;
uint8_t String[] = "Error";

void CalcConf(keypad_t *pKeypad, lcd_t *pLcd)
{
    pKeypad->Keypad_RowArr[0].port = kPORTA;
    pKeypad->Keypad_RowArr[1].port = kPORTA;
    pKeypad->Keypad_RowArr[2].port = kPORTA;
    pKeypad->Keypad_RowArr[3].port = kPORTA;
    pKeypad->Keypad_COLArr[0].port = kPORTA;
    pKeypad->Keypad_COLArr[1].port = kPORTA;
    pKeypad->Keypad_COLArr[2].port = kPORTA;
    pKeypad->Keypad_COLArr[3].port = kPORTA;

    pKeypad->Keypad_RowArr[0].pin =kPIN0;
    pKeypad->Keypad_RowArr[1].pin =kPIN1;
    pKeypad->Keypad_RowArr[2].pin =kPIN2;
    pKeypad->Keypad_RowArr[3].pin =kPIN3;
    pKeypad->Keypad_COLArr[0].pin =kPIN4;
    pKeypad->Keypad_COLArr[1].pin =kPIN5;
    pKeypad->Keypad_COLArr[2].pin =kPIN6;
    pKeypad->Keypad_COLArr[3].pin =kPIN7;

    Keypad_Init(pKeypad);
    pLcd -> kLcdMode = LCD_8Bit;
    pLcd -> kLcdDataPort = kPORTC;
    pLcd -> kLcdControlPort = kPORTD;
    pLcd -> kRS_PinNum = kPIN0;
    pLcd -> kRW_PinNum = kPIN1;
    pLcd -> kEN_PinNum = kPIN2;

    LCD_Init(pLcd);
}
void Calculator(charStack_t *opStack,
                 sint32_tStack_t *numStack, lcd_t *lcd, uint8_t key)
{
    num =0, num1=0, num2=0, op = 0;
    if ((key >= '0') && (key <= '9'))
    {
        LCD_SendChar(lcd, key);
        num = (num * 10) + (key -'0');
        sint32_tStack_Push(numStack, num);
        num =0;
    }
    else if ((key == '+') || (key == '-') || (key == '*') || (key == '/'))
    {
        LCD_SendChar(lcd, key);
        if (charStack_GetSize(opStack) != 0)
        {
            if (IsHigherPriority(charStack_GetTop(opStack))
                            > IsHigherPriority(key))
            {
                num2 = sint32_tStack_Pop(numStack);
                num1 = sint32_tStack_Pop(numStack);
                op = charStack_Pop(opStack);
                if (op == '/' && num2 == 0)
                {
                    LCD_SetPosition(lcd, LCD_ROW_2, LCD_COL_1);
                    LCD_SendString(lcd, String);
                    return;
                }
                num = Calculate(op, num1, num2);
                sint32_tStack_Push(numStack, num);
                charStack_Push(opStack, key);
            }
            else if ((IsHigherPriority(charStack_GetTop(opStack))
                        == IsHigherPriority(key)))
            {
                num2 = sint32_tStack_Pop(numStack);
                num1 = sint32_tStack_Pop(numStack);
                op = charStack_Pop(opStack);
                if (op == '/' && num2 == 0)
                {
                    LCD_SetPosition(lcd, LCD_ROW_2, LCD_COL_1);
                    LCD_SendString(lcd, String);
                    return;
                }
                num = Calculate(op, num1, num2);
                sint32_tStack_Push(numStack, num);
                charStack_Push(opStack, key);
            }
            else if (IsHigherPriority(charStack_GetTop(opStack))
                            < IsHigherPriority(key))
            {
                charStack_Push(opStack, key);
            }
        }
        else
        {
            charStack_Push(opStack, key);
        }
    }
    else if (key == '=')
    {
        while ((charStack_GetSize(opStack) != 0)
            && (sint32_tStack_GetSize(numStack) != 0))
        {
            num2 = sint32_tStack_Pop(numStack);
            num1 = sint32_tStack_Pop(numStack);
            op = charStack_Pop(opStack);
            if (op == '/' && num2 == 0)
            {
                LCD_SetPosition(lcd, LCD_ROW_2, LCD_COL_1);
                LCD_SendString(lcd, String);
                return;
            }
            num = Calculate(op, num1, num2);
            sint32_tStack_Push(numStack, num);
        }
        LCD_SetPosition(lcd, LCD_ROW_2, LCD_COL_1);
        LCD_SendNumber(lcd, sint32_tStack_Pop(numStack));
    }
    else if (key == '&')
    {
        LCD_ClearScreen(lcd);
        key = 0;
        num = 0, num1 = 0, num2 = 0;

        opStack ->size = 0;
        opStack ->top = 0;

        numStack ->size = 0;
        opStack ->top = 0;
    }
}
uint8_t IsHigherPriority(uint8_t op)
{
    uint8_t flag = 0;
    if ((op == '*' || op == '/'))
    {
        flag =2;
    }
    else if ((op == '+' || op == '-'))
    {
        flag =1;
    }
    return flag;
}
sint8_t Calculate(uint8_t op, sint8_t operand1, sint8_t operand2)
{
    switch (op)
    {
    case '+':return (operand1 + operand2);
    case '-':return (operand1 - operand2);
    case '/':return (operand1 / operand2);
    case '*':return (operand1 * operand2);
    default: return 0;
    }
}
