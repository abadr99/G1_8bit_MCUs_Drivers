#include "../../common/Types.h"
#include "../../common/Utils.h"
#include "../../common/Config.h"
#include "../../common/Registes.h"
#include "GPIOPrivate.h"
#include "GPIO.h"


error_t GPIO_SetPinDirection(port_t PortNumber , pin_t PinNumber , direction_t Direction)
{
	error_t Ret_ErrorState = kNoError ;
	/* Make sure that the Port number and Pin number are in the valid range */
	if(PortNumber <= kPORTD && PinNumber <= kPIN7 )
	{
		if(Direction == kOutput)
		{
			switch(PortNumber)
			{
				case kPORTA : SET_BIT(DDRA_REG , PinNumber); break;
				case kPORTB : SET_BIT(DDRB_REG , PinNumber); break;
				case kPORTC : SET_BIT(DDRC_REG , PinNumber); break;
				case kPORTD : SET_BIT(DDRD_REG , PinNumber); break;
			}
		}
		else if (Direction == kInput)
		{
			switch(PortNumber)
			{
				case kPORTA : CLR_BIT(DDRA_REG , PinNumber); break;
				case kPORTB : CLR_BIT(DDRB_REG , PinNumber); break;
				case kPORTC : CLR_BIT(DDRC_REG , PinNumber); break;
				case kPORTD : CLR_BIT(DDRD_REG , PinNumber); break;
			}
		}
	}else
	{
		Ret_ErrorState = kFunctioParameterError  ;
	}

	return Ret_ErrorState ;
}

error_t GPIO_SetPinValue(port_t PortNumber , pin_t PinNumber , state_t PintVoltageLevel)
{
	/* Make sure that the Port number and Pin number are in the valid range */
	error_t Ret_ErrorState = kNoError ;
	if(PortNumber <= kPORTD && PinNumber <= kPIN7 )
	{
		if(PintVoltageLevel ==kHigh)
		{
			switch(PortNumber)
			{
				case kPORTA : SET_BIT(PORTA_REG , PinNumber); break;
				case kPORTB : SET_BIT(PORTB_REG , PinNumber); break;
				case kPORTC : SET_BIT(PORTC_REG , PinNumber); break;
				case kPORTD : SET_BIT(PORTD_REG , PinNumber); break;
			}
		}
		else if (PintVoltageLevel ==kLow)
		{
			switch(PortNumber)
			{
				case kPORTA : CLR_BIT(PORTA_REG , PinNumber); break;
				case kPORTB : CLR_BIT(PORTB_REG , PinNumber); break;
				case kPORTC : CLR_BIT(PORTC_REG , PinNumber); break;
				case kPORTD : CLR_BIT(PORTD_REG , PinNumber); break;
			}
		}
	}else
	{
		Ret_ErrorState = kFunctioParameterError  ;
	}
	return Ret_ErrorState ;
}
error_t GPIO_GetPinValue(port_t PortNumber , pin_t PinNumber,state_t * state)
{

	error_t Ret_ErrorState = kNoError ;
			/* Make sure that the Port number and Pin number are in the valid range */
			if(PortNumber <= kPORTD  && PinNumber <= kPIN7 )
			{
				switch(PortNumber)
				{
					case kPORTA : *state= GET_BIT(PINA_REG , PinNumber); break;
					case kPORTB : *state= GET_BIT(PINB_REG , PinNumber); break;
					case kPORTC : *state= GET_BIT(PINC_REG , PinNumber); break;
					case kPORTD : *state =GET_BIT(PIND_REG , PinNumber); break;
				}
			}
			else
			{
					Ret_ErrorState = kFunctioParameterError  ;
			}

		return Ret_ErrorState ;

}

error_t GPIO_SetPortDirection(port_t PortNumber, uint8_t direction)
{
	error_t Ret_ErrorState = kNoError ;
		/* Make sure that the Port number is in the valid range */
		if(PortNumber <= kPORTD )
		{

				switch(PortNumber)
				{
					case kPORTA : DDRA_REG =direction; break;
					case kPORTB : DDRB_REG =direction; break;
					case kPORTC : DDRC_REG =direction; break;
					case kPORTD : DDRD_REG =direction; break;
				}

		}else
		{
			Ret_ErrorState = kFunctioParameterError  ;
		}

		return Ret_ErrorState ;
}
error_t GPIO_SetPortValue(port_t PortNumber, uint8_t PintVoltageLevel)
{
	/* Make sure that the Port number is in the valid range */
	error_t Ret_ErrorState = kNoError ;
	if(PortNumber <= kPORTD )
	{
			switch(PortNumber)
			{
				case kPORTA : PORTA_REG=PintVoltageLevel; break;
				case kPORTB : PORTB_REG=PintVoltageLevel; break;
				case kPORTC : PORTC_REG =PintVoltageLevel; break;
				case kPORTD : PORTD_REG =PintVoltageLevel;break;
			}

	}else
	{
		Ret_ErrorState = kFunctioParameterError  ;
	}
	return Ret_ErrorState ;
}
error_t GPIO_GetPortValue(port_t PortNumber ,uint8_t * state)
{

	/* Make sure that the Port number is in the valid range */
		error_t Ret_ErrorState = kNoError ;
		if(PortNumber <= kPORTD )
		{
				switch(PortNumber)
				{
					case kPORTA : *state=PINA_REG; break;
					case kPORTB : *state=PINB_REG; break;
					case kPORTC : *state=PINC_REG; break;
					case kPORTD : *state=PIND_REG;break;
				}

		}else
		{
			Ret_ErrorState = kFunctioParameterError  ;
		}
		return Ret_ErrorState ;
}
