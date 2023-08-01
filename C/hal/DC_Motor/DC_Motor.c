#include "../../common/Types.h"
#include "../../mcal/GPIO/GPIO.h"
#include "DC_Motor.h"


error_t DcMotor_Init(DcMotor_t * pDcMotor)
{
    error_t Ret_ErrorState = kNoError;
    if (pDcMotor != NULL)
    {
        GPIO_SetPinDirection(pDcMotor->port, pDcMotor->IN1, kOutput);
        GPIO_SetPinDirection(pDcMotor->port, pDcMotor->IN2, kOutput);
    }
    else
    {
        Ret_ErrorState = kFunctioParameterError;
    }
    return Ret_ErrorState;
}
error_t DcMotor_ClockWise(DcMotor_t * pDcMotor)
{
    error_t Ret_ErrorState = kNoError;
    if (pDcMotor != NULL)
    {
        GPIO_SetPinValue(pDcMotor->port, pDcMotor->IN1, kHigh);
        GPIO_SetPinValue(pDcMotor->port, pDcMotor->IN2, kLow);
    }
    else
    {
        Ret_ErrorState = kFunctioParameterError;
    }
    return Ret_ErrorState;
}
error_t DcMotor_AntiClockWise(DcMotor_t * pDcMotor)
{
    error_t Ret_ErrorState = kNoError;
    if (pDcMotor != NULL)
    {
        GPIO_SetPinValue(pDcMotor->port, pDcMotor->IN1, kLow);
        GPIO_SetPinValue(pDcMotor->port, pDcMotor->IN2, kHigh);
    }
    else
    {
        Ret_ErrorState = kFunctioParameterError;
    }
    return Ret_ErrorState;
}
error_t DcMotor_Stop(DcMotor_t * pDcMotor)
{
    error_t Ret_ErrorState = kNoError;
    if (pDcMotor != NULL)
    {
        GPIO_SetPinValue(pDcMotor->port, pDcMotor->IN1, kLow);
        GPIO_SetPinValue(pDcMotor->port, pDcMotor->IN2, kLow);
    }
    else
    {
        Ret_ErrorState = kFunctioParameterError;
    }
    return Ret_ErrorState;
}
