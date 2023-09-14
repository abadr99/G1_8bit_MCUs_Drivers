#include <util/delay.h>
#include "../../../common/Types.h"
#include "../../../common/Utils.h"
#include "Stack_Config.h"
#include "Stack.h"
#include "../../../hal/LCD/LCD_Interface.h"
#include "Calculator.h"

static uint8_t IsHigherPriority(uint8_t op);
static sint8_t Calculate(uint8_t op, uint8_t operand1, uint8_t operand2);

sint8_t num =0, num1=0, num2=0, op = 0;
uint8_t String[] = "Error";
void Calculator(Stack_t *opStack, Stack_t *numStack, lcd_t *lcd, uint8_t key)
{
    num =0, num1=0, num2=0, op = 0;
     if ((key >= '0') && (key <= '9'))
        {
            LCD_SendChar(lcd, key);
            num = (num * 10) + (key -'0');
            Stack_Push(numStack, num);
            num =0;
        }
        else if ((key == '+') || (key == '-') || (key == '*') || (key == '/'))
        {
            LCD_SendChar(lcd, key);
            if ( Is_Empty(opStack) == 0)
            {
                if (IsHigherPriority(Stack_Top(opStack)) 
                                > IsHigherPriority(key))
                {
                    num2 = Stack_Pop(numStack);
                    num1 = Stack_Pop(numStack);
                    op = Stack_Pop(opStack);
                    if (op == '/' && num2 == 0)
                    {
                        LCD_SetPosition(lcd, LCD_ROW_2, LCD_COL_1);
                        LCD_SendString(lcd, String);
                        return;
                    }
                    num = Calculate(op, num1, num2);
                    Stack_Push(numStack, num);
                    Stack_Push(opStack, key);
                }
                else if (IsHigherPriority(Stack_Top(opStack)) 
                                    == IsHigherPriority(key))
                {
                    num2 = Stack_Pop(numStack);
                    num1 = Stack_Pop(numStack);
                    op = Stack_Pop(opStack);
                    if (op == '/' && num2 == 0)
                    {
                        LCD_SetPosition(lcd, LCD_ROW_2, LCD_COL_1);
                        LCD_SendString(lcd, String);
                        return;
                    }
                    num = Calculate(op, num1, num2);
                    Stack_Push(numStack, num);
                    Stack_Push(opStack, key);
                }
            }
            else
            {
                Stack_Push(opStack, key);
            }
        }
        else if (key == '=')
        {
            while ((Is_Empty(numStack) == 0) 
                && (Is_Empty(opStack) == 0))
            {
                num2 = Stack_Pop(numStack);
                num1 = Stack_Pop(numStack);
                op = Stack_Pop(opStack);
                if (op == '/' && num2 == 0)
                {
                    LCD_SetPosition(lcd, LCD_ROW_2, LCD_COL_1);
                    LCD_SendString(lcd, String);
                    return;
                }
                num = Calculate(op, num1, num2);
                Stack_Push(numStack, num);
            }
            LCD_SetPosition(lcd, LCD_ROW_2, LCD_COL_1);
            LCD_SendNumber(lcd, num);
        }
        else if (key == 'C')
        {
            LCD_ClearScreen(lcd);
            key =0;
            num = 0, num1 = 0, num2 = 0;
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
sint8_t Calculate(uint8_t op, uint8_t operand1, uint8_t operand2)
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
