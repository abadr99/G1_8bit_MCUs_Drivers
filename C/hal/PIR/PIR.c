#include "../common/Types.h"
#include "../../mcal/GPIO/GPIO.h"
#include "PIR.h"

error_t PIR_Init(PIR_t* pPIR)
{
    error_t Ret_ErrorState = kNoError;
    if (pPIR!=NULL)
    {
    GPIO_SetPinDirection(pPIR->Port, pPIR->Pin, kInput);
    }
    else
	{
		Ret_ErrorState = kFunctioParameterError;
	}
	return Ret_ErrorState;
}
error_t PIR_GetVal(PIR_t* pPIR, state_t * state)
{
    error_t Ret_ErrorState = kNoError;
    if (pPIR!=NULL)
    {
     GPIO_GetPinValue(pPIR->Port, pPIR->Pin, state);
    }
    else
	{
		Ret_ErrorState = kFunctioParameterError;
	}
	return Ret_ErrorState;
}
