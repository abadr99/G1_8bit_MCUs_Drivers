#include <util/delay.h>
#include "../../../common/Types.h"
#include "../../../common/Utils.h"
#include "Stack_Config.h"
#include "Stack.h"
#include "../../../hal/Keypad/Keypad_config_only_one.h"
#include "../../../hal/Keypad/Keypad_only_one.h"
#include "../../../hal/LCD/LCD_Interface.h"
#include "Calculator.h"

int main() {
    keypad_t keypad1;
    keypad1.Keypad_RowArr[0].port =kPORTA;
    keypad1.Keypad_RowArr[1].port =kPORTA;
    keypad1.Keypad_RowArr[2].port =kPORTA;
    keypad1.Keypad_RowArr[3].port =kPORTA;
    keypad1.Keypad_COLArr[0].port =kPORTA;
    keypad1.Keypad_COLArr[1].port =kPORTA;
    keypad1.Keypad_COLArr[2].port =kPORTA;
    keypad1.Keypad_COLArr[3].port =kPORTA;

    keypad1.Keypad_RowArr[0].pin =kPIN0;
    keypad1.Keypad_RowArr[1].pin =kPIN1;
    keypad1.Keypad_RowArr[2].pin =kPIN2;
    keypad1.Keypad_RowArr[3].pin =kPIN3;
    keypad1.Keypad_COLArr[0].pin =kPIN4;
    keypad1.Keypad_COLArr[1].pin =kPIN5;
    keypad1.Keypad_COLArr[2].pin =kPIN6;
    keypad1.Keypad_COLArr[3].pin =kPIN7;
   
    Keypad_Init(&keypad1);
    lcd_t lcd1 ={LCD_8Bit, kPORTC, kPORTD, kPIN0, kPIN1, kPIN2};
    LCD_Init(&lcd1);
    uint8_t key =0;
    Stack_t numStack,opStack;
    Stack_Init(&numStack);
    Stack_Init(&opStack);
    while (1)
    {
        do
        {
            key = Keypad_GetPressedButton(&keypad1);
        } while (key == NOT_PRESSED);
        Calculator(&opStack,&numStack,&lcd1,key);
        /* 
        if((key >= '0') && (key <= '9'))
        {
            LCD_SendChar(&lcd1,key);
            num = (num * 10) + (key -'0');
            Stack_Push(&Num,num);
            num =0;
        }
        else if((key == '+') || (key == '-') || (key == '*') || (key == '/'))
        {
            LCD_SendChar(&lcd1,key);
            Stack_Push(&Op,key);
            num1 = num;
            num = 0;
            switch (key)
            {
            case '+': op_char =1;break;
            case '-': op_char =2;break;
            case '*': op_char =3;break;
            case '/': op_char =4;break;
            }
        }
        else if(key == '=')
        {
            while((!Is_Empty(&Num)) && (!Is_Empty(&Op)))
            {
                num2 = Stack_Pop(&Num);
                num1 = Stack_Pop(&Num);
                op_char = Stack_Pop(&Op);
                switch(op_char)
                {
                    case '+':Stack_Push(&Num,(num2 + num1));break;
                    case '-':Stack_Push(&Num,(num1 - num2));break;
                    case '/':Stack_Push(&Num,(num1 / num2));break;
                    case '*':Stack_Push(&Num,(num1 * num2));break;
                }
            }
            //Stack_Push(&Num,ans);
            LCD_SetPosition(&lcd1,LCD_ROW_2,LCD_COL_1);
            LCD_SendNumber(&lcd1,Stack_Pop(&Num));
            //LCD_SendNumber(&lcd1,(ans - (10*num2)));
            num2 = num;
            num = 0;
            switch (op_char)
            {
            case 1: ans = (num1) + (num2);break;
            case 2: ans = (num1 ) - (num2 );break;
            case 3: ans = (num1) * (num2);break;
            case 4: ans = (num1) / (num2);break;
            }
            LCD_SetPosition(&lcd1,LCD_ROW_2,LCD_COL_1);
            LCD_SendNumber(&lcd1,ans);
        }
        else if(key == 'C')
        {
            LCD_ClearScreen(&lcd1);
            key =0;
            num = 0,num1 = 0,num2 = 0;
            op_char = 0;
            //ans = 0;
        }
        */
    }
}