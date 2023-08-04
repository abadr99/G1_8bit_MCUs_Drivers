#include "../../common/Types.h"
#include "../../common/Utils.h"
#include "../../common/Config.h"
#include "../../common/Registes.h"
#include "GPIOPrivate.h"
#include "GPIO.h"


error_t GPIO_SetPinDirection(port_t PortNumber, pin_t PinNumber,
							 direction_t Direction)
{
	error_t Ret_ErrorState = kNoError;
	/* Make sure that the Port number and Pin number are in the valid range */
	if (PortNumber <= GPIO_LAST_REG  && PinNumber <= GPIO_LAST_PIN )
	{
		if (Direction == kOutput)
		{
			switch (PortNumber)
			{
				case kPORTA : SET_DIR_OUTPUT(GPIOA_DIR_REG, PinNumber); break;
				case kPORTB : SET_DIR_OUTPUT(GPIOB_DIR_REG, PinNumber); break;
				case kPORTC : SET_DIR_OUTPUT(GPIOC_DIR_REG, PinNumber); break;
				case kPORTD : SET_DIR_OUTPUT(GPIOD_DIR_REG, PinNumber); break;
				#if MCU_TYPE == _PIC
				case kPORTE : SET_DIR_OUTPUT(GPIO_DIRECTION_REGE, PinNumber); break;
				#endif
			}
		}
		else if (Direction == kInput)
		{
			switch (PortNumber)
			{
				case kPORTA : SET_DIR_INPUT(GPIOA_DIR_REG, PinNumber); break;
				case kPORTB : SET_DIR_INPUT(GPIOB_DIR_REG, PinNumber); break;
				case kPORTC : SET_DIR_INPUT(GPIOC_DIR_REG, PinNumber); break;
				case kPORTD : SET_DIR_INPUT(GPIOD_DIR_REG, PinNumber); break;
				#if MCU_TYPE == _PIC
				case kPORTE : SET_DIR_INPUT(GPIO_DIRECTION_REGE, PinNumber); break;
				#endif
			}
		}
	}else
	{
		Ret_ErrorState = kFunctioParameterError;
	}

	return Ret_ErrorState;
}

error_t GPIO_SetPinValue(port_t PortNumber, pin_t PinNumber,
						 state_t PintVoltageLevel)
{
	/* Make sure that the Port number and Pin number are in the valid range */
	error_t Ret_ErrorState = kNoError;
	if (PortNumber <= GPIO_LAST_REG  && PinNumber <= GPIO_LAST_PIN )
	{
		if (PintVoltageLevel ==kHigh)
		{
			switch ( PortNumber)
			{
				case kPORTA : SET_BIT(GPIOA_OUT_REG, PinNumber); break;
				case kPORTB : SET_BIT(GPIOB_OUT_REG, PinNumber); break;
				case kPORTC : SET_BIT(GPIOC_OUT_REG, PinNumber); break;
				case kPORTD : SET_BIT(GPIOD_OUT_REG, PinNumber); break;
				#if MCU_TYPE == _PIC
				case kPORTE : SET_BIT(GPIO_OUTPUT_REGE, PinNumber); break;
				#endif
			}
		}
		else if (PintVoltageLevel ==kLow)
		{
			switch (PortNumber)
			{
				case kPORTA : CLR_BIT(GPIOA_OUT_REG, PinNumber); break;
				case kPORTB : CLR_BIT(GPIOB_OUT_REG, PinNumber); break;
				case kPORTC : CLR_BIT(GPIOC_OUT_REG, PinNumber); break;
				case kPORTD : CLR_BIT(GPIOD_OUT_REG, PinNumber); break;
				#if MCU_TYPE == _PIC
				case kPORTE : CLR_BIT(GPIO_OUTPUT_REGE, PinNumber); break;
				#endif
			}
		}
	}else
	{
		Ret_ErrorState = kFunctioParameterError;
	}
	return Ret_ErrorState;
}
error_t GPIO_GetPinValue(port_t PortNumber, pin_t PinNumber, state_t * state)
{
 error_t Ret_ErrorState = kNoError;
   /* Make sure that the Port number and Pin number are in the valid range */
   if (PortNumber <= GPIO_LAST_REG   && PinNumber <= GPIO_LAST_PIN )
   {
    switch (PortNumber)
    {
      case kPORTA : *state= GET_BIT(GPIOA_IN_REG, PinNumber); break;
      case kPORTB : *state= GET_BIT(GPIOB_IN_REG, PinNumber); break;
      case kPORTC : *state= GET_BIT(GPIOC_IN_REG, PinNumber); break;
      case kPORTD : *state =GET_BIT(GPIOD_IN_REG, PinNumber); break;
	  #if MCU_TYPE == _PIC
	  case kPORTE : *state =GET_BIT(GPIO_INPUT_REGE, PinNumber); break;
	  #endif
    }
   }
   else
   {
     Ret_ErrorState = kFunctioParameterError;
   }

    return Ret_ErrorState;

}
error_t GPIO_SetPortDirection(port_t PortNumber, uint8_t direction)
{
 error_t Ret_ErrorState = kNoError;
  /* Make sure that the Port number is in the valid range */
  if (PortNumber <= GPIO_LAST_REG  )
  {

    switch (PortNumber)
    {
     case kPORTA : GPIOA_DIR_REG =direction; break;
     case kPORTB : GPIOB_DIR_REG =direction; break;
     case kPORTC : GPIOC_DIR_REG =direction; break;
     case kPORTD : GPIOD_DIR_REG =direction; break;
	  #if MCU_TYPE == _PIC
	  case kPORTE : GPIO_DIRECTION_REGE =direction; break;
	  #endif
    }

  }else
  {
   Ret_ErrorState = kFunctioParameterError;
  }

  return Ret_ErrorState;
}
error_t GPIO_SetPortValue(port_t PortNumber, uint8_t PintVoltageLevel)
{
 /* Make sure that the Port number is in the valid range */
 error_t Ret_ErrorState = kNoError;
 if (PortNumber <= GPIO_LAST_REG  )
 {
   switch (PortNumber)
   {
    case kPORTA : GPIOA_OUT_REG =PintVoltageLevel; break;
    case kPORTB : GPIOB_OUT_REG =PintVoltageLevel; break;
    case kPORTC : GPIOC_OUT_REG =PintVoltageLevel; break;
    case kPORTD : GPIOD_OUT_REG =PintVoltageLevel; break;
	#if MCU_TYPE == _PIC
	case kPORTE : GPIO_DIRECTION_REGE =PintVoltageLevel; break;
	#endif
   }

 }else
 {
  Ret_ErrorState = kFunctioParameterError;
 }
 return Ret_ErrorState;
}
error_t GPIO_GetPortValue(port_t PortNumber, uint8_t * state)
{

 /* Make sure that the Port number is in the valid range */
  error_t Ret_ErrorState = kNoError;
  if (PortNumber <= GPIO_LAST_REG  )
  {
    switch (PortNumber)
    {
     case kPORTA : *state=GPIOA_IN_REG; break;
     case kPORTB : *state=GPIOB_IN_REG; break;
     case kPORTC : *state=GPIOC_IN_REG; break;
     case kPORTD : *state=GPIOD_IN_REG; break;
	 #if MCU_TYPE == _PIC
	 case kPORTE : *state =GPIO_INPUT_REGE; break;
	  #endif
    }

  }else
  {
   Ret_ErrorState = kFunctioParameterError;
  }
  return Ret_ErrorState;
}

error_t GPIO_SetLowNibbleValue(port_t PortNumber, uint8_t Value)
{
	error_t LocReturnError = kNoError;
	/* This line to make sure that the high nibble in port value will not change */
	Value &= 0X0F;
	switch (PortNumber)
	{
		case kPORTA : GPIOA_OUT_REG &= 0XF0; GPIOA_OUT_REG |= Value;  break;
		case kPORTB : GPIOB_OUT_REG &= 0XF0; GPIOB_OUT_REG |= Value;  break;
		case kPORTC : GPIOC_OUT_REG &= 0XF0; GPIOC_OUT_REG |= Value;  break;
		case kPORTD : GPIOD_OUT_REG &= 0XF0; GPIOD_OUT_REG |= Value;  break;
		default:      LocReturnError = kFunctioParameterError;  break;
	}
	return LocReturnError;
}
error_t GPIO_SetHighNibbleValue(port_t PortNumber, uint8_t Value)
{
	error_t LocReturnError = kNoError;
	/* This line to make sure that the Low nibble in port value will not change */
	Value &= 0XF0;
	switch (PortNumber)
	{
		case kPORTA : GPIOA_OUT_REG &= 0X0F; GPIOA_OUT_REG |= Value;  break;
		case kPORTB : GPIOB_OUT_REG &= 0X0F; GPIOB_OUT_REG |= Value;  break;
		case kPORTC : GPIOC_OUT_REG &= 0X0F; GPIOC_OUT_REG |= Value;  break;
		case kPORTD : GPIOD_OUT_REG &= 0X0F; GPIOD_OUT_REG |= Value;  break;
		default:      LocReturnError = kFunctioParameterError;  break;
	}
	return LocReturnError;
}

error_t GPIO_SetLowNibbleDirection(port_t PortNumber, uint8_t Direction)
{
	error_t LocReturnError = kNoError;
	/* This line to make sure that the high nibble in port value will not change */
	Direction &= 0X0F;
	switch (PortNumber)
	{
		case kPORTA : GPIOA_DIR_REG &= 0XF0; GPIOA_DIR_REG |= Direction;  break;
		case kPORTB : GPIOB_DIR_REG &= 0XF0; GPIOB_DIR_REG |= Direction;  break;
		case kPORTC : GPIOC_DIR_REG &= 0XF0; GPIOC_DIR_REG |= Direction;  break;
		case kPORTD : GPIOD_DIR_REG &= 0XF0; GPIOD_DIR_REG |= Direction;  break;
		default:      LocReturnError = kFunctioParameterError;  break;
	}
	return LocReturnError;
}
error_t GPIO_SetHighNibbleDirection(port_t PortNumber, uint8_t Direction)
{
	error_t LocReturnError = kNoError;
	/* This line to make sure that the high nibble in port value will not change */
	Direction &= 0XF0;
	switch (PortNumber)
	{
		case kPORTA : GPIOA_DIR_REG &= 0X0F; GPIOA_DIR_REG |= Direction;  break;
		case kPORTB : GPIOB_DIR_REG &= 0X0F; GPIOB_DIR_REG |= Direction;  break;
		case kPORTC : GPIOC_DIR_REG &= 0X0F; GPIOC_DIR_REG |= Direction;  break;
		case kPORTD : GPIOD_DIR_REG &= 0X0F; GPIOD_DIR_REG |= Direction;  break;
		default:      LocReturnError = kFunctioParameterError;  break;
	}
	return LocReturnError;
}
