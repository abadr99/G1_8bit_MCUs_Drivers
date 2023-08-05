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
    lcd_t _LCD =
        {LCD_4Bit, kPORTD, kPORTA, kPIN0, kPIN1, kPIN2, LCD_HIGH_NIBBLE };
    LCD_Init(&_LCD);
    while (1)
    {

        uint8_t str[30]={"<MOHAMED REFAT>"};
        LCD_SendString(&_LCD, str);
        _delay_ms(2500);
        LCD_ClearScreen(&_LCD);

        LCD_SendFloat(&_LCD, 79.9);
        _delay_ms(2500);
        LCD_ClearScreen(&_LCD);

        LCD_SendNumber(&_LCD, 80);
        _delay_ms(2500);
        LCD_ClearScreen(&_LCD);

        LCD_SetPosition(&_LCD, LCD_ROW_2, LCD_COL_3);
        LCD_SendString(&_LCD, str);
        _delay_ms(2500);
        LCD_ClearScreen(&_LCD);

        uint8_t str1[30]={"TEST SHIFT"};
        LCD_SendString(&_LCD, str1);
        LCD_ShiftRight(&_LCD);
        LCD_ShiftRight(&_LCD);
        _delay_ms(2500);
        LCD_ShiftLeft(&_LCD);
        LCD_ShiftLeft(&_LCD);
        _delay_ms(2500);
        LCD_ClearScreen(&_LCD);

        uint8_t str2[30]={"TEST CURSOR"};
        LCD_SendString(&_LCD, str2);
        LCD_EnableCursor(&_LCD);
        _delay_ms(2500);
        LCD_DisableCursor(&_LCD);
        _delay_ms(2500);
        LCD_ClearScreen(&_LCD);

        uint8_t str3[30]={"DISPLAY ON/OFF"};
        LCD_SendString(&_LCD, str3);
        LCD_Display_Off(&_LCD);
        _delay_ms(2500);
        LCD_Display_On(&_LCD);
        _delay_ms(2500);
        LCD_ClearScreen(&_LCD);

        uint8_t str4[30]={"BLINK ON/OFF"};
        LCD_SendString(&_LCD, str4);
        LCD_Blink_On(&_LCD);
        _delay_ms(2500);
        LCD_Blink_Off(&_LCD);
        _delay_ms(2500);
        LCD_DisableCursor(&_LCD);
        LCD_ClearScreen(&_LCD);

        LCD_SetPosition(&_LCD, LCD_ROW_1, LCD_COL_3);
        uint8_t str5[30]={"CUSTOM CHAR"};
        LCD_SendString(&_LCD, str5);
        LCD_StoreCustomChar(&_LCD, heart, 5);
        LCD_StoreCustomChar(&_LCD, skull, 0);
        LCD_SendCustomChar(&_LCD, 5, LCD_ROW_2, LCD_COL_8);
        LCD_SendCustomChar(&_LCD, 0, LCD_ROW_2, LCD_COL_9);
        _delay_ms(3000);
        LCD_ClearScreen(&_LCD);

    }
}
