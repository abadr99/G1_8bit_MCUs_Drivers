#include "../../common/Types.h"
#include "../../common/Utils.h"
#include "../../common/Config.h"
#include "../../common/Registes.h"
#include "GPIOPrivate.h"
#include "GPIO.h"


error_t GPIO_SetPinDirection(port_t portNumber, pin_t pinNumber,
							 direction_t direction)
{
	error_t retErrorState = kNoError;
	/* Make sure that the Port number and Pin number are in the valid range */
	if (portNumber <= GPIO_LAST_REG  && pinNumber <= GPIO_LAST_PIN )
	{
		if (direction == kOutput)
		{
			switch (portNumber)
			{
				case kPORTA : SET_DIR_OUTPUT(GPIOA_DIR_REG, pinNumber); break;
				case kPORTB : SET_DIR_OUTPUT(GPIOB_DIR_REG, pinNumber); break;
				case kPORTC : SET_DIR_OUTPUT(GPIOC_DIR_REG, pinNumber); break;
				case kPORTD : SET_DIR_OUTPUT(GPIOD_DIR_REG, pinNumber); break;
				#if MCU_TYPE == _PIC
				case kPORTE : SET_DIR_OUTPUT(GPIO_DIRECTION_REGE, pinNumber); break;
				#endif
			}
		}
		else if (direction == kInput)
		{
			switch (portNumber)
			{
				case kPORTA : SET_DIR_INPUT(GPIOA_DIR_REG, pinNumber); break;
				case kPORTB : SET_DIR_INPUT(GPIOB_DIR_REG, pinNumber); break;
				case kPORTC : SET_DIR_INPUT(GPIOC_DIR_REG, pinNumber); break;
				case kPORTD : SET_DIR_INPUT(GPIOD_DIR_REG, pinNumber); break;
				#if MCU_TYPE == _PIC
				case kPORTE : SET_DIR_INPUT(GPIO_DIRECTION_REGE, pinNumber); break;
				#endif
			}
		}
	}else
	{
		retErrorState = kFunctionParameterError;
	}

	return retErrorState;
}

error_t GPIO_SetPinValue(port_t portNumber, pin_t pinNumber,
						 state_t pintVoltageLevel)
{
	/* Make sure that the Port number and Pin number are in the valid range */
	error_t retErrorState = kNoError;
	if (portNumber <= GPIO_LAST_REG  && pinNumber <= GPIO_LAST_PIN )
	{
		if (pintVoltageLevel ==kHigh)
		{
			switch ( portNumber)
			{
				case kPORTA : SET_BIT(GPIOA_OUT_REG, pinNumber); break;
				case kPORTB : SET_BIT(GPIOB_OUT_REG, pinNumber); break;
				case kPORTC : SET_BIT(GPIOC_OUT_REG, pinNumber); break;
				case kPORTD : SET_BIT(GPIOD_OUT_REG, pinNumber); break;
				#if MCU_TYPE == _PIC
				case kPORTE : SET_BIT(GPIO_OUTPUT_REGE, pinNumber); break;
				#endif
			}
		}
		else if (pintVoltageLevel ==kLow)
		{
			switch (portNumber)
			{
				case kPORTA : CLR_BIT(GPIOA_OUT_REG, pinNumber); break;
				case kPORTB : CLR_BIT(GPIOB_OUT_REG, pinNumber); break;
				case kPORTC : CLR_BIT(GPIOC_OUT_REG, pinNumber); break;
				case kPORTD : CLR_BIT(GPIOD_OUT_REG, pinNumber); break;
				#if MCU_TYPE == _PIC
				case kPORTE : CLR_BIT(GPIO_OUTPUT_REGE, pinNumber); break;
				#endif
			}
		}
	}else
	{
		retErrorState = kFunctionParameterError;
	}
	return retErrorState;
}
error_t GPIO_GetPinValue(port_t portNumber, pin_t pinNumber, state_t * state)
{
 error_t retErrorState = kNoError;
   /* Make sure that the Port number and Pin number are in the valid range */
   if (portNumber <= GPIO_LAST_REG   && pinNumber <= GPIO_LAST_PIN )
   {
    switch (portNumber)
    {
      case kPORTA : *state= GET_BIT(GPIOA_IN_REG, pinNumber); break;
      case kPORTB : *state= GET_BIT(GPIOB_IN_REG, pinNumber); break;
      case kPORTC : *state= GET_BIT(GPIOC_IN_REG, pinNumber); break;
      case kPORTD : *state =GET_BIT(GPIOD_IN_REG, pinNumber); break;
	  #if MCU_TYPE == _PIC
	  case kPORTE : *state =GET_BIT(GPIO_INPUT_REGE, pinNumber); break;
	  #endif
    }
   }
   else
   {
     retErrorState = kFunctionParameterError;
   }

    return retErrorState;

}
error_t GPIO_SetPortDirection(port_t portNumber, uint8_t direction)
{
 error_t retErrorState = kNoError;
  /* Make sure that the Port number is in the valid range */
  if (portNumber <= GPIO_LAST_REG  )
  {

    switch (portNumber)
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
   retErrorState = kFunctionParameterError;
  }

  return retErrorState;
}
error_t GPIO_SetPortValue(port_t portNumber, uint8_t pintVoltageLevel)
{
 /* Make sure that the Port number is in the valid range */
 error_t retErrorState = kNoError;
 if (portNumber <= GPIO_LAST_REG  )
 {
   switch (portNumber)
   {
    case kPORTA : GPIOA_OUT_REG =pintVoltageLevel; break;
    case kPORTB : GPIOB_OUT_REG =pintVoltageLevel; break;
    case kPORTC : GPIOC_OUT_REG =pintVoltageLevel; break;
    case kPORTD : GPIOD_OUT_REG =pintVoltageLevel; break;
	#if MCU_TYPE == _PIC
	case kPORTE : GPIO_DIRECTION_REGE =pintVoltageLevel; break;
	#endif
   }

 }else
 {
  retErrorState = kFunctionParameterError;
 }
 return retErrorState;
}
error_t GPIO_GetPortValue(port_t portNumber, uint8_t * state)
{

 /* Make sure that the Port number is in the valid range */
  error_t retErrorState = kNoError;
  if (portNumber <= GPIO_LAST_REG  )
  {
    switch (portNumber)
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
   retErrorState = kFunctionParameterError;
  }
  return retErrorState;
}
