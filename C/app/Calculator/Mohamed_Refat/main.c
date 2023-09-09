#include <util/delay.h>
#include "../../../common/Types.h"
#include "../../../common/Utils.h"
#include "../../../common/Config.h"
#include "../../../common/Registes.h"
#include "../../../mcal/GPIO/GPIOPrivate.h"
#include "../../../mcal/GPIO/GPIO.h"
#include "../../../hal/LCD/LCD_Interface.h"
#include "../../../hal/Keypad/Keypad_config_only_one.h"
#include "../../../hal/Keypad/Keypad_only_one.h"
#include "Calculator.h"


int main()
{
    lcd_t LCD = {LCD_4Bit, kPORTC, kPORTA, kPIN0, kPIN1, kPIN2,LCD_HIGH_NIBBLE };
    keypadPin_t row1 = {kPORTD, kPIN0};
    keypadPin_t row2 = {kPORTD, kPIN1};
    keypadPin_t row3 = {kPORTD, kPIN2};
    keypadPin_t row4 = {kPORTD, kPIN3};
    keypadPin_t col1 = {kPORTD, kPIN4};
    keypadPin_t col2 = {kPORTD, kPIN5};
    keypadPin_t col3 = {kPORTD, kPIN6};
    keypadPin_t col4 = {kPORTD, kPIN7};
    keypad_t Pad = 
    {
        .Keypad_RowArr[0] = row1,
        .Keypad_RowArr[1] = row2,
        .Keypad_RowArr[2] = row3,
        .Keypad_RowArr[3] = row4,
        .Keypad_COLArr[0] = col1,
        .Keypad_COLArr[1] = col2,
        .Keypad_COLArr[2] = col3,
        .Keypad_COLArr[3] = col4,
    };

	Calc_Error_t kErrorState = NoError;
	uint8_t infixExp[EXPRESSION_SIZE]={};
	uint8_t postfixExp[EXPRESSION_SIZE]={};
	uint8_t strResult[11] = "Result = ";
	uint8_t strSyntaxError[14] = "Syntax Error ";
	uint8_t strMathError[12] = "Math Error";
	uint8_t iterator = 0;
	f32_t result;
	uint8_t KP_PressedValue = NOT_PRESSED;

    LCD_Init(&LCD);
	Keypad_Init(&Pad);
	while (1)
	{
		iterator = 0;

		/* Take The infix expression From the user */
		while (iterator < EXPRESSION_SIZE ){
			/* Wait until the keypad is pressed */
			while (KP_PressedValue == NOT_PRESSED)
			{
				KP_PressedValue = Keypad_GetPressedButton(&Pad);
			}
			/* Case entered value is Number or operator not = or C 'Terminate' */
			if(KP_PressedValue != '=' && KP_PressedValue != 'C')
			{
				LCD_SendChar(&LCD, KP_PressedValue);
				infixExp[iterator++] = KP_PressedValue;
				KP_PressedValue = NOT_PRESSED;

			}
			/* Case entered value is  = or C 'Terminate' */
			else 
			{
				break;
			}
		}

		if ( KP_PressedValue == '=' ){

			kErrorState = GetPostfixExp(infixExp , postfixExp);
			kErrorState = EvaluatePostfixExp(postfixExp , &result, kErrorState);
			LCD_SetPosition(&LCD, LCD_ROW_2 , LCD_COL_1);

			/* iterator == 0 --> to handle case  that the  user doesn't entered eny expression
			  but he entered '=' so the previous result will appear  */
			if( (kErrorState == NoError || iterator == 0 ) ){
				LCD_SendString(&LCD, strResult);
				LCD_SendFloat(&LCD, result);

			}else if (kErrorState == SyntaxError){
				LCD_SendString(&LCD, strSyntaxError);
			}else if ( kErrorState == DivideByZero ){
				LCD_SendString(&LCD, strMathError);
			}

		}
		/* After user enter '=' or 'C' wait until he entered  new value to start again */
		KP_PressedValue = Keypad_GetPressedButton(&Pad);
		while (KP_PressedValue == NOT_PRESSED){
			KP_PressedValue = Keypad_GetPressedButton(&Pad);
		}

		/* restore the default value of Infix Expression array and Postfix Expression array 
		so that the dont affect on the next operation */
		iterator = 0 ;
		while(iterator < EXPRESSION_SIZE){
			infixExp[iterator] = '\0';
			postfixExp[iterator] = '\0';
			iterator++;
		}
		LCD_ClearScreen(&LCD);
	}

}
