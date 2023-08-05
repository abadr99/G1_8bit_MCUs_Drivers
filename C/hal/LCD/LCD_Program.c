#include <stdio.h>
#include <util/delay.h>
#include "../../common/Types.h"
#include "../../mcal/GPIO/GPIO.h"
#include "LCD_Interface.h"
#include "LCD_Private.h"


error_t LCD_Init(lcd_t *pLcdConfig)
{
	error_t kErrorState = kNoError;
	if (pLcdConfig != NULL_ptr)
	{
		/* SET Direction for LCD control  pins --> OUTPUT */
		GPIO_SetPinDirection(pLcdConfig->kLcdControlPort,
										pLcdConfig->KRS_PinNum, kOutput );

		GPIO_SetPinDirection(pLcdConfig->kLcdControlPort,
										pLcdConfig->KRW_PinNum, kOutput );

		GPIO_SetPinDirection(pLcdConfig->kLcdControlPort,
										pLcdConfig->KEN_PinNum, kOutput );

		if (pLcdConfig->kLcdMode == LCD_8Bit)
		{
			/* SET Direction for LCD Data  pins --> OUTPUT */
			GPIO_SetPortDirection(pLcdConfig->kLcdDataPort, kOutput_PORT);

			_delay_ms(50);
			/* Function Set */
			LCD_SendCommand(pLcdConfig, LCD_FUNCTION_SET_8_BIT);
			_delay_ms(1);
			/*   Display ON/OFF Control */
			LCD_SendCommand(pLcdConfig, LCD_DISPLAY_ON_CURSOR_OFF);
			_delay_ms(1);
			/*  Clear Screen */
			LCD_SendCommand(pLcdConfig, LCD_CLEAR_SCREEN);
			_delay_ms(5);
			/* Entry mode set */
			LCD_SendCommand(pLcdConfig, LCD_ENTRY_MODE_INC_SHIFT_OFF);
			_delay_ms(1);
		}
		else if (pLcdConfig->kLcdMode == LCD_4Bit)
		{
			/* SET Direction for LCD Data  pins --> OUTPUT */
			if (pLcdConfig->kLcd_4bitDataPin == LCD_HIGH_NIBBLE )
			{
				GPIO_SetHighNibbleDirection(pLcdConfig->kLcdDataPort, kOutput_PORT);
			}
			else if (pLcdConfig->kLcd_4bitDataPin == LCD_LOW_NIBBLE )
			{
				GPIO_SetLowNibbleDirection(pLcdConfig->kLcdDataPort, kOutput_PORT);

			}
			LCD_SendCommand(pLcdConfig, LCD_RETURN_HOME);
			_delay_ms(50);
			/* Function Set */
			LCD_SendCommand(pLcdConfig, LCD_FUNCTION_SET_4_BIT);
			_delay_ms(1);
			/*   Display ON/OFF Control */
			LCD_SendCommand(pLcdConfig, LCD_DISPLAY_ON_CURSOR_OFF);
			_delay_ms(1);
			/*  Clear Screen */
			LCD_SendCommand(pLcdConfig, LCD_CLEAR_SCREEN);
			_delay_ms(5);
			/* Entry mode set */
			LCD_SendCommand(pLcdConfig, LCD_ENTRY_MODE_INC_SHIFT_OFF);
			_delay_ms(5);
		}

	}else
	{
		kErrorState = kFunctioParameterError;
	}
	return kErrorState;

}


static error_t LCD_SendData(lcd_t *pLcdConfig, uint8_t Data)
{
	error_t kErrorState = kNoError;
	if (pLcdConfig != NULL_ptr)
	{
		/* Set RS to 1 and RW to 0  */
		GPIO_SetPinValue(pLcdConfig->kLcdControlPort, pLcdConfig->KRS_PinNum, kHigh );
		GPIO_SetPinValue(pLcdConfig->kLcdControlPort, pLcdConfig->KRW_PinNum, kLow  );

		if (pLcdConfig->kLcdMode == LCD_8Bit)
		{
			/* Send Data to the LCD Port */
			GPIO_SetPortValue(pLcdConfig->kLcdDataPort, Data);
			LCD_SendFallingEndgPulse(pLcdConfig);
		}
		else if (pLcdConfig->kLcdMode == LCD_4Bit)
		{
			if (pLcdConfig->kLcd_4bitDataPin == LCD_HIGH_NIBBLE )
			{
				GPIO_SetHighNibbleValue(pLcdConfig->kLcdDataPort, Data);
				LCD_SendFallingEndgPulse(pLcdConfig);
				GPIO_SetHighNibbleValue(pLcdConfig->kLcdDataPort, (Data<<4) );
				LCD_SendFallingEndgPulse(pLcdConfig);
			}
			else if (pLcdConfig->kLcd_4bitDataPin == LCD_LOW_NIBBLE )
			{
				GPIO_SetLowNibbleValue(pLcdConfig->kLcdDataPort, (Data>>4) );
				LCD_SendFallingEndgPulse(pLcdConfig);
				GPIO_SetLowNibbleValue(pLcdConfig->kLcdDataPort, Data);
				LCD_SendFallingEndgPulse(pLcdConfig);
			}
		}

	}else
	{
		kErrorState = kFunctioParameterError;
	}
	return kErrorState;
}
static error_t LCD_SendCommand(lcd_t *pLcdConfig, uint8_t Command)
{
	error_t kErrorState = kNoError;
	if (pLcdConfig != NULL_ptr)
	{
		/* Set RS to 0 and RW to 0  */
		GPIO_SetPinValue(pLcdConfig->kLcdControlPort, pLcdConfig->KRS_PinNum, kLow );
		GPIO_SetPinValue(pLcdConfig->kLcdControlPort, pLcdConfig->KRW_PinNum, kLow );

		if (pLcdConfig->kLcdMode == LCD_8Bit)
		{
			/* Send Command to the LCD Port */
			GPIO_SetPortValue(pLcdConfig->kLcdDataPort, Command);
			LCD_SendFallingEndgPulse(pLcdConfig);
		}
		else if (pLcdConfig->kLcdMode == LCD_4Bit)
		{
			if (pLcdConfig->kLcd_4bitDataPin == LCD_HIGH_NIBBLE )
			{
				GPIO_SetHighNibbleValue(pLcdConfig->kLcdDataPort, Command);
				LCD_SendFallingEndgPulse(pLcdConfig);
				GPIO_SetHighNibbleValue(pLcdConfig->kLcdDataPort, (Command<<4));
				LCD_SendFallingEndgPulse(pLcdConfig);
			}
			else if (pLcdConfig->kLcd_4bitDataPin == LCD_LOW_NIBBLE )
			{
				GPIO_SetLowNibbleValue(pLcdConfig->kLcdDataPort, (Command>>4) );
				LCD_SendFallingEndgPulse(pLcdConfig);
				GPIO_SetLowNibbleValue(pLcdConfig->kLcdDataPort, Command);
				LCD_SendFallingEndgPulse(pLcdConfig);
			}
		}
		
	}
	else
	{
		kErrorState = kFunctioParameterError;
	}
	return kErrorState;
	
}
static error_t LCD_SendFallingEndgPulse(lcd_t *pLcdConfig)
{
	error_t kErrorState = kNoError;
	if (pLcdConfig != NULL_ptr)
	{
		GPIO_SetPinValue(pLcdConfig->kLcdControlPort, pLcdConfig->KEN_PinNum, kHigh );
		_delay_ms(1);
		GPIO_SetPinValue(pLcdConfig->kLcdControlPort, pLcdConfig->KEN_PinNum, kLow );
		_delay_ms(1);

	}else
	{
		kErrorState = kFunctioParameterError;
	}
	return kErrorState;

}
error_t LCD_ClearScreen(lcd_t *pLcdConfig)
{
	error_t kErrorState = kNoError;
	if (pLcdConfig != NULL_ptr)
	{
		LCD_SendCommand(pLcdConfig, LCD_CLEAR_SCREEN);
		_delay_ms(1);

	}else
	{
		kErrorState = kFunctioParameterError;
	}
	return kErrorState;
}

error_t LCD_SendtChar(lcd_t *pLcdConfig, uint8_t Ch)
{
	error_t kErrorState = kNoError;
	if (pLcdConfig != NULL_ptr)
	{
		LCD_SendData(pLcdConfig, Ch);
	}else
	{
		kErrorState = kFunctioParameterError;
	}
	return kErrorState;
}

error_t LCD_SendString(lcd_t *pLcdConfig, uint8_t str[])
{
	error_t kErrorState = kNoError;
	if (pLcdConfig != NULL_ptr)
	{
		uint8_t Iterator =  0;
		while (str[Iterator]!= '\0')
		{
			LCD_SendData(pLcdConfig, str[Iterator++]);
		}
		
	}else
	{
		kErrorState = kFunctioParameterError;
	}
	return kErrorState;
}

error_t LCD_SetPosition(lcd_t *pLcdConfig, uint8_t Row_Num, uint8_t Column_Num)
{
	error_t kErrorState = kNoError;
	if (pLcdConfig != NULL_ptr)
	{
		uint8_t LocCommand;
		/* if the user enter invaled location AC will point to
			the first place in DDRAM (0, 0 )  */
		if (Row_Num>LCD_ROW_2 || Row_Num<LCD_ROW_1||
										Column_Num>LCD_COL_16 || Column_Num<LCD_COL_1)
		{
			LocCommand =  LCD_DDRAM_START;
		}
		else if (Row_Num == LCD_ROW_1 )
		{
			LocCommand = LCD_DDRAM_START + Column_Num -1;
		}
		else if (Row_Num == LCD_ROW_2 )
		{
			LocCommand = LCD_DDRAM_START + 64 +  Column_Num -1;
		}
		LCD_SendCommand(pLcdConfig, LocCommand);
		_delay_ms(1);
	}else
	{
		kErrorState = kFunctioParameterError;
	}
	return kErrorState;
}
error_t LCD_SendNumber(lcd_t *pLcdConfig, sint16 Num)
{
	error_t kErrorState = kNoError;
	if (pLcdConfig != NULL_ptr)
	{
	
		sint16 Loc_Temp = Num;
		uint8_t Iterator = 0;
		uint8_t Iterator_2 = 0;
		uint8_t Negative_Flag = 0;
		char numArr[5] = {0};
		/* Store Number in numArr as a string
			but the number will be stored in reverse order in the array
				so we need to reverse this array again
		 */
		if (Num==0)
		{
			LCD_SendtChar(pLcdConfig, '0');

		}
		if (Num<0)
		{
			Num = Num * (-1);
			Negative_Flag = 1;
		}
		while (Num != 0 )
		{
			Loc_Temp = Num % 10;
			numArr[Iterator++] = ( Loc_Temp + '0' );
			Num = Num / 10;
		}
		/* Revers numArr */
		for (Iterator_2 = 0; Iterator_2 < Iterator/2; Iterator_2++)
		{
			char temp = numArr[Iterator_2];
			numArr[Iterator_2 ] = numArr[Iterator-Iterator_2-1];
			numArr[Iterator-Iterator_2-1] = temp;
		}

		for (Iterator_2 = 0; Iterator_2 < Iterator; Iterator_2++ )
		{
			if (Negative_Flag)
			{
				LCD_SendtChar(pLcdConfig, '-');
				Negative_Flag = 0;
			}
			LCD_SendtChar(pLcdConfig, numArr[Iterator_2]);
		}
	}else
	{
		kErrorState = kFunctioParameterError;
	}
	return kErrorState;
}
error_t LCD_SendFloat(lcd_t *pLcdConfig, f32_t Num)
{
	error_t kErrorState = kNoError;
	if (pLcdConfig != NULL_ptr)
	{
		float Fraction_Part = Num - (uint32_t)Num;
		uint16 Real_Part = Num;
		Fraction_Part *=1000;
		LCD_SendNumber(pLcdConfig, Real_Part);
		LCD_SendtChar(pLcdConfig, '.');
		LCD_SendNumber(pLcdConfig, (uint16)Fraction_Part);
		
	}else
	{
		kErrorState = kFunctioParameterError;
	}
	return kErrorState;
}
error_t LCD_StoreCustomChar(lcd_t *pLcdConfig, uint8_t pChar_Arr[],
														uint8_t Location)
{
	error_t kErrorState = kNoError;
	if (pLcdConfig != NULL_ptr)
	{
		uint8_t Iterator;

		/* 1- Make AC point to CGRAM */
		LCD_SendCommand(pLcdConfig, LCD_CGRAM_START + Location*8 );

		/* 2- Copy Character from byte 0 to byte 7
		   To CGRAM and it Automatically will be copied to the DDRAM */
		for (Iterator = 0; Iterator<8; Iterator++)
		{
			LCD_SendData(pLcdConfig, pChar_Arr[Iterator]);
		}

		/* 2- Back To DDRAM */
		LCD_SendCommand(pLcdConfig, LCD_DDRAM_START);
	}
	else
	{
		kErrorState = kFunctioParameterError;
	}
	return kErrorState;
}
error_t LCD_SendCustomChar(lcd_t *pLcdConfig, uint8_t Location,
											uint8_t Row_Num, uint8_t Col_Num)
{
	error_t kErrorState = kNoError;
	if (pLcdConfig != NULL_ptr)
	{
		LCD_SetPosition(pLcdConfig, Row_Num, Col_Num);
		LCD_SendData(pLcdConfig, Location);
	}else
	{
		kErrorState = kFunctioParameterError;
	}
	return kErrorState;

}


error_t LCD_EnableCursor(lcd_t *pLcdConfig)
{
	error_t kErrorState = kNoError;
	if (pLcdConfig != NULL_ptr)
	{
		LCD_SendCommand(pLcdConfig, LCD_DISPLAY_ON_CURSOR_ON);
	}else
	{
		kErrorState = kFunctioParameterError;
	}
	return kErrorState;
}

error_t LCD_DisableCursor(lcd_t *pLcdConfig)
{
	error_t kErrorState = kNoError;
	if (pLcdConfig != NULL_ptr)
	{
		LCD_SendCommand(pLcdConfig, LCD_DISPLAY_ON_CURSOR_OFF);
	}else
	{
		kErrorState = kFunctioParameterError;
	}
	return kErrorState;
	
}

error_t LCD_ShiftRight(lcd_t *pLcdConfig)
{
	error_t kErrorState = kNoError;
	if (pLcdConfig != NULL_ptr)
	{
		LCD_SendCommand(pLcdConfig, LCD_SHIFT_RIGHT);
	}else
	{
		kErrorState = kFunctioParameterError;
	}
	return kErrorState;
	
}
error_t LCD_ShiftLeft(lcd_t *pLcdConfig)
{
	error_t kErrorState = kNoError;
	if (pLcdConfig != NULL_ptr)
	{
		LCD_SendCommand(pLcdConfig, LCD_SHIFT_LEFT);
	}else
	{
		kErrorState = kFunctioParameterError;
	}
	return kErrorState;
}


error_t LCD_Display_On(lcd_t *pLcdConfig)
{
	error_t kErrorState = kNoError;
	if (pLcdConfig != NULL_ptr)
	{
		LCD_SendCommand(pLcdConfig, LCD_DISPLAY_ON_CURSOR_OFF);
	}else
	{
		kErrorState = kFunctioParameterError;
	}
	return kErrorState;
}
error_t LCD_Display_Off(lcd_t *pLcdConfig)
{
	error_t kErrorState = kNoError;
	if (pLcdConfig != NULL_ptr)
	{
		LCD_SendCommand(pLcdConfig, LCD_DISPLAY_OFF_CURSOR_OFF);
	}else
	{
		kErrorState = kFunctioParameterError;
	}
	return kErrorState;
}

error_t LCD_Blink_On(lcd_t *pLcdConfig)
{
	error_t kErrorState = kNoError;
	if (pLcdConfig != NULL_ptr)
	{
		LCD_SendCommand(pLcdConfig, LCD_BLINK_ON);
		
	}else
	{
		kErrorState = kFunctioParameterError;
	}
	return kErrorState;
}

error_t LCD_Blink_Off(lcd_t *pLcdConfig)
{
	error_t kErrorState = kNoError;
	if (pLcdConfig != NULL_ptr)
	{
		LCD_SendCommand(pLcdConfig, LCD_BLINK_OFF);
	}else
	{
		kErrorState = kFunctioParameterError;
	}
	return kErrorState;
	
}
