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
				case kPORTA : SET_DIR_OUTPUT(GPIOA_DIR_REG , PinNumber); break;
				case kPORTB : SET_DIR_OUTPUT(GPIOB_DIR_REG , PinNumber); break;
				case kPORTC : SET_DIR_OUTPUT(GPIOC_DIR_REG , PinNumber); break;
				case kPORTD : SET_DIR_OUTPUT(GPIOD_DIR_REG , PinNumber); break;
				#if MCU_TYPE == _PIC
				case kPORTE : SET_DIR_OUTPUT(GPIO_DIRECTION_REGE , PinNumber); break;
				#endif
			}
		}
		else if (Direction == kInput)
		{
			switch(PortNumber)
			{
				case kPORTA : SET_DIR_INPUT(GPIOA_DIR_REG , PinNumber); break;
				case kPORTB : SET_DIR_INPUT(GPIOB_DIR_REG , PinNumber); break;
				case kPORTC : SET_DIR_INPUT(GPIOC_DIR_REG , PinNumber); break;
				case kPORTD : SET_DIR_INPUT(GPIOD_DIR_REG , PinNumber); break;
				#if MCU_TYPE == _PIC
				case kPORTE : SET_DIR_INPUT(GPIO_DIRECTION_REGE , PinNumber); break;
				#endif
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
				case kPORTA : SET_BIT(GPIOA_OUT_REG , PinNumber); break;
				case kPORTB : SET_BIT(GPIOB_OUT_REG , PinNumber); break;
				case kPORTC : SET_BIT(GPIOC_OUT_REG , PinNumber); break;
				case kPORTD : SET_BIT(GPIOD_OUT_REG , PinNumber); break;
				#if MCU_TYPE == _PIC
				case kPORTE : SET_BIT(GPIO_OUTPUT_REGE , PinNumber); break;
				#endif
			}
		}
		else if (PintVoltageLevel ==kLow)
		{
			switch(PortNumber)
			{
				case kPORTA : CLR_BIT(GPIOA_OUT_REG , PinNumber); break;
				case kPORTB : CLR_BIT(GPIOB_OUT_REG , PinNumber); break;
				case kPORTC : CLR_BIT(GPIOC_OUT_REG , PinNumber); break;
				case kPORTD : CLR_BIT(GPIOD_OUT_REG , PinNumber); break;
				#if MCU_TYPE == _PIC
				case kPORTE : CLR_BIT(GPIO_OUTPUT_REGE , PinNumber); break;
				#endif
			}
		}
	}else
	{
		Ret_ErrorState = kFunctioParameterError  ; 
	}
	return Ret_ErrorState ; 
}