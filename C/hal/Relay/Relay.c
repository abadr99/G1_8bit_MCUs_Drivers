#include "../../common/Types.h"
#include "../../mcal/GPIO/GPIO.h"
#include "Relay.h"

error_t Relay_Init(Relay_t* pRelay)
{
    error_t Ret_ErrorState = kNoError;
    if (pRelay != NULL_ptr)
    {
        GPIO_SetPinDirection(pRelay->Port, pRelay->Pin, kOutput);
    }
    else
    {
        Ret_ErrorState = kFunctioParameterError;
    }
    return Ret_ErrorState;
}
error_t Relay_TurnOn(Relay_t* pRelay)
{
    error_t Ret_ErrorState = kNoError;
    if (pRelay != NULL_ptr)
    {
        GPIO_SetPinValue(pRelay->Port, pRelay->Pin, kHigh);
    }
    else
    {
        Ret_ErrorState = kFunctioParameterError;
    }
    return Ret_ErrorState;
}
error_t Relay_TurnOff(Relay_t* pRelay)
{
    error_t Ret_ErrorState = kNoError;
    if (pRelay != NULL_ptr)
    {
        GPIO_SetPinValue(pRelay->Port, pRelay->Pin, kLow);
    }
    else
    {
        Ret_ErrorState = kFunctioParameterError;
    }
    return Ret_ErrorState;
}
