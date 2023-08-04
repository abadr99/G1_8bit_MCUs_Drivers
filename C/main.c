#include <util/delay.h>
#include "common/Types.h"
#include "common/Utils.h"
#include "hal/LCD/LCD_Interface.h"
#include "hal/Buzzer/Buzzer.h"
uint8_t heart[] =
{
  0x00,
  0x00,
  0x0A,
  0x1F,
  0x1F,
  0x0E,
  0x04,
  0x00
};
uint8_t skull[8] =
{
0b00000,
0b01110,
0b10101,
0b11011,
0b01110,
0b01110,
0b00000,
0b00000
};
int main()
{
    LCD_Init();
    while (1)
    {

        uint8_t str[30]={"MOHAMED REFAT"};
        LCD_SendString(str);
        _delay_ms(2500);
        LCD_ClearScreen();

        LCD_SendFloat(79.9);
        _delay_ms(2500);
        LCD_ClearScreen();

        LCD_SendNumber(80);
        _delay_ms(2500);
        LCD_ClearScreen();

        LCD_SetPosition(LCD_ROW_2, LCD_COL_3);
        LCD_SendString(str);
        _delay_ms(2500);
        LCD_ClearScreen();

        uint8_t str1[30]={"TEST SHIFT"};
        LCD_SendString(str1);
        LCD_ShiftRight();
        LCD_ShiftRight();
        _delay_ms(2500);
        LCD_ShiftLeft();
        LCD_ShiftLeft();
        _delay_ms(2500);
        LCD_ClearScreen();

        uint8_t str2[30]={"TEST CURSOR"};
        LCD_SendString(str2);
        LCD_EnableCursor();
        _delay_ms(2500);
        LCD_DisableCursor();
        _delay_ms(2500);
        LCD_ClearScreen();

        uint8_t str3[30]={"DISPLAY ON/OFF"};
        LCD_SendString(str3);
        LCD_Display_Off();
        _delay_ms(2500);
        LCD_Display_On();
        _delay_ms(2500);
        LCD_ClearScreen();

        uint8_t str4[30]={"BLINK ON/OFF"};
        LCD_SendString(str4);
        LCD_Blink_On();
        _delay_ms(2500);
        LCD_Blink_Off();
        _delay_ms(2500);
        LCD_DisableCursor();
        LCD_ClearScreen();

        LCD_SetPosition(LCD_ROW_1, LCD_COL_3);
        uint8_t str5[30]={"CUSTOM CHAR"};
        LCD_SendString(str5);
        LCD_StoreCustomChar(heart, 5);
        LCD_StoreCustomChar(skull, 0);
        LCD_SendCustomChar(5, LCD_ROW_2, LCD_COL_8);
        LCD_SendCustomChar(0, LCD_ROW_2, LCD_COL_9);
        _delay_ms(3000);
        LCD_ClearScreen();

    }
}
