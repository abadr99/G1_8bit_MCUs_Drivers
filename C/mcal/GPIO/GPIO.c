#include "../../common/Types.h"
#include "../../common/Config.h"
#include "../../common/Registes.h"
#include "GPIOPrivate.h"
#include "GPIO.h"


Error_t GPIO_SetPinDirection(PORT_t PortNumber , PIN_t PinNumber , DIRECTION_t Direction)
{
	Error_t LocReturnError = NoError ;
	/* Make sure that the Port number and Pin nuber are in the valid range */
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
		LocReturnError = FunctioParameterError  ; 
	} 

	return LocReturnError ; 
}

Error_t GPIO_SetPinValue(PORT_t PortNumber , PIN_t PinNumber , STATE_t PintVoltageLevel)
{
	/* Make sure that the Port number and Pin nuber are in the valid range */
	Error_t LocReturnError = NoError ;
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
		LocReturnError = FunctioParameterError  ; 
	}
	return LocReturnError ; 
}