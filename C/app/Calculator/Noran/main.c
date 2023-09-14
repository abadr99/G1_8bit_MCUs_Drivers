#include "../../../common/Types.h"
#include "../../../common/Utils.h"
#include "../../../common/Config.h"
#include "../../../common/Registes.h"
#include "../../../mcal/GPIO/GPIOPrivate.h"
#include "../../../mcal/GPIO/GPIO.h"
#include "../../../hal/Keypad/Keypad_config_only_one.h"
#include "../../../hal/Keypad/Keypad_only_one.h"
#include "../../../hal/LCD/LCD_Interface.h"
#include "calc.h"
int main(void)
{lcd_t lcd;
lcd.kLcdMode=LCD_8Bit;
lcd.kLcdDataPort=kPORTC;
lcd.kLcdControlPort=kPORTD;
lcd.kRS_PinNum=kPIN0;
lcd.kRW_PinNum=kPIN1;
lcd.kEN_PinNum=kPIN2;
keypad_t k;
k.Keypad_RowArr[0].port=kPORTA;
k.Keypad_RowArr[1].port=kPORTA;
k.Keypad_RowArr[2].port=kPORTA;
k.Keypad_RowArr[3].port=kPORTA;
k.Keypad_COLArr[0].port=kPORTA;
k.Keypad_COLArr[1].port=kPORTA;
k.Keypad_COLArr[2].port=kPORTA;
k.Keypad_COLArr[3].port=kPORTA;
k.Keypad_RowArr[0].pin=kPIN0;
k.Keypad_RowArr[1].pin=kPIN1;
k.Keypad_RowArr[2].pin=kPIN2;
k.Keypad_RowArr[3].pin=kPIN3;
k.Keypad_COLArr[0].pin=kPIN4;
k.Keypad_COLArr[1].pin=kPIN5;
k.Keypad_COLArr[2].pin=kPIN6;
k.Keypad_COLArr[3].pin=kPIN7;
LCD_Init(&lcd);
Keypad_Init(&k);
uint8_t operatorStack[OPERATOR_SIZE];
sint32 numStack[NUMBER_SIZE];
sint16 operatorStackIterator=0, numStackIterator=0, iterator=0;
sint32 num=0;
while (1)
{
    uint8_t keyVal;
    do
    {
     keyVal=Keypad_GetPressedButton(&k);
    }
    while (keyVal==NOT_PRESSED);
    iterator++;
if (keyVal=='&')
{
    LCD_ClearScreen(&lcd);
    operatorStackIterator=0;
    numStackIterator=0;
    num=0;
    iterator=0;
}
else if (keyVal!='=')
{
    if (iterator==16)
    {
    LCD_SetPosition(&lcd, LCD_ROW_2, LCD_COL_1);
    }
    LCD_SendChar(&lcd, keyVal);
    if (ISNUM(keyVal))
    {
        num=(num*10)+(keyVal-'0');
    }
    else
    {
        if (operatorStack[operatorStackIterator-1]!='-')
        {
            numStack[numStackIterator]=num;
        }
        else
        {
             operatorStack[operatorStackIterator-1]='+';
             numStack[numStackIterator]=-num;
        }
        numStackIterator++;
        num=0;
        if (operatorStackIterator==0)
        {
            operatorStack[operatorStackIterator]=keyVal;
            operatorStackIterator++;
        }
        else
        {
            if (GetPrecedence(keyVal)<
                GetPrecedence(operatorStack[operatorStackIterator-1]))
            {
                sint32 result=Operate(numStack[numStackIterator-2],
                                      numStack[numStackIterator-1],
                                      operatorStack[operatorStackIterator-1]);
                operatorStack[operatorStackIterator-1]=keyVal;
                numStack[numStackIterator-2]=result;
                numStackIterator--;
            }
            else
            {
                operatorStack[operatorStackIterator]=keyVal;
                operatorStackIterator++;
            }
        }
    }
}
else
{
  numStack[numStackIterator]=num;
  numStackIterator++;
  Evaluate(numStack, operatorStack, numStackIterator, operatorStackIterator);
  LCD_ClearScreen(&lcd);
  LCD_SendChar(&lcd, '=');
  LCD_SendNumber(&lcd, numStack[0]);
break;
}
}
return 0;
}
