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
uint8_t arr[OPERATOR_SIZE];
sint16 ar[NUMBER_SIZE];
sint16 i=0,j=0;
sint16 num=0;
while(1){ 
    uint8_t keyVal;
    do{
     keyVal=Keypad_GetPressedButton(&k);}
    while(keyVal==NOT_PRESSED);
LCD_SendChar(&lcd,keyVal);
if(keyVal!='='){ 
    if(ISNUM(keyVal)) 
    { 
        num=(num*10)+(keyVal-'0'); 
    } 
    else 
    {if(arr[i-1]!='-'){ 
        ar[j]=num;} 
        else 
        { 
             arr[i-1]='+'; 
             ar[j]=-num; 
        } 
    j++; 
    num=0; 
        if(i==0) 
        { 
            arr[i]=keyVal; 
            i++; 
        } 
        else 
        { 
            if(getPrecedence(keyVal)<getPrecedence(arr[i-1])) 
            { 
                int result=operatr(ar[j-2],ar[j-1],arr[i-1]); 
                arr[i-1]=keyVal; 
                ar[j-2]=result; 
                j--; 
            } 
            else 
            { 
                arr[i]=keyVal; 
                i++; 
            } 
 
        } 
    } 
 
} 
else{ 
ar[j]=num; 
j++; 

while(i>0) 
{ 
    int result=operatr(ar[j-2],ar[j-1],arr[i-1]); 
                ar[j-2]=result; 
                j--; 
                i--; 
} 
LCD_SendNumber(&lcd,ar[0]);
break;}}
return 0;}