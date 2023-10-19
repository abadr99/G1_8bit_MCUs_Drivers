#include "../../../common/Types.h"
#include "../../../common/Utils.h"
#include "../../../common/Config.h"
#include "../../../common/Registes.h"
#include "../../../mcal/GPIO/GPIOPrivate.h"
#include "../../../mcal/GPIO/GPIO.h"
#include "../../../hal/Keypad/Keypad_config_only_one.h"
#include "../../../hal/Keypad/Keypad_only_one.h"
#include "../../../hal/LCD/LCD_Interface.h"
#include "../../../utils/stack/stack_macros.h"
#include "../../../utils/stack/stack.h"
#include "calc.h"
void CalcEval(uint8_t keyVal, uint8_t lastVal, lcd_t* lcd,
              keypad_t* k, charStack_t* operatorStack,
              sint32_tStack_t* numStack);
sint32_t num=0;
uint8_t keyVal, lastval;
sint16 operatorStackIterator=0, numStackIterator=0, iterator=0, count;
int main(void)
{lcd_t lcd;
keypad_t k;
CalcInit(&lcd, &k, kPORTC, kPORTD, kPORTA);
charStack_t operatorStack;
sint32_tStack_t  numStack;
while (1)
{lastval=keyVal;
    do
    {
     keyVal=Keypad_GetPressedButton(&k);
    }
    while (keyVal==NOT_PRESSED);
    iterator++;
CalcEval(keyVal, lastval, &lcd, &k, &operatorStack, &numStack);

}
return 0;
}
void CalcEval(uint8_t keyVal, uint8_t lastVal, lcd_t* lcd, keypad_t* k,
              charStack_t* operatorStack, sint32_tStack_t* numStack)
{
if (keyVal=='&')
{
    LCD_ClearScreen(lcd);
    num=0;
    iterator=0;
}
else if (keyVal!='=')
{
    if (iterator==16)
    {
    LCD_SetPosition(lcd, LCD_ROW_2, LCD_COL_1);
    }
    LCD_SendChar(lcd, keyVal);
    if (ISNUM(keyVal))
    {
        num=(num*10)+(keyVal-'0');
        count=0;
    }
    else if (ISNUM(lastVal)==0)
    {count++;
        if (lastVal==keyVal)
        {if (keyVal=='-')
            {
            charStack_Pop(operatorStack);
             charStack_Push(operatorStack, '+');
            }
        }
        else if (lastVal!=keyVal&&charStack_GetSize(operatorStack)!=1)
        {uint8_t arr[]="ERROR";
        LCD_ClearScreen(lcd);
            LCD_SendString(lcd, arr);
        }
        else if (charStack_GetSize(operatorStack)==1&&keyVal!='-')
        {
         uint8_t arr[]="ERROR";
        LCD_ClearScreen(lcd);
        LCD_SendString(lcd, arr);
        }
    }
    else
    {count++;
        if (charStack_GetTop(operatorStack)!='-')
        {
            sint32_tStack_Push(numStack, num);
        }
        else
        {
            charStack_Pop(operatorStack);
             charStack_Push(operatorStack, '+');
             num=-num;
             sint32_tStack_Push(numStack, num);
        }
        numStackIterator++;
        num=0;
        if (charStack_GetSize(operatorStack)==0)
        {
            charStack_Push(operatorStack, keyVal);
            operatorStackIterator++;
        }
        else
        {
            if (GetPrecedence(keyVal)<
                GetPrecedence(charStack_GetTop(operatorStack)))
            {sint32_t num1=sint32_tStack_Pop(numStack);
            sint32_t num2=sint32_tStack_Pop(numStack);
                sint32_t result=Operate(num2, num1,
                                       charStack_Pop(operatorStack));
                charStack_Push(operatorStack, keyVal);
                sint32_tStack_Push(numStack, result);
                numStackIterator--;
            }
            else
            {
                charStack_Push(operatorStack, keyVal);
                operatorStackIterator++;
            }
        }
    }
}
else
{
  sint32_tStack_Push(numStack, num);
  numStackIterator++;
  Evaluate(numStack, operatorStack, numStackIterator, operatorStackIterator);
  if (iterator==33)
  {
  LCD_ClearScreen(lcd);
  }
  LCD_SendChar(lcd, '=');
  LCD_SendNumber(lcd, sint32_tStack_GetTop(numStack));
}
}
