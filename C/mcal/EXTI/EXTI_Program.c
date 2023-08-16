/**
 * @file   :EXTI_Program.c
 * @author :
 * @brief  :This file contain the implementation of EXTI functions
 * @version:0.1
 * @date   :2023-08-16
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "../../common/Types.h"
#include "../../common/Utils.h"
#include "../../common/Registes.h"
#include "EXTI_Private.h"
#include "EXTI_Interface.h"


void (*EXTI_pCallBackFun[3]) (void) = {NULL_PTR};

error_t EXTI_InterruptEnable (uint8_t kInterruptSource)
{
    error_t kErrorState = kNoError;
    #if MCU_TYPE == _AVR
    switch (kInterruptSource)
    {
        case EXTI_INT0 : SET_BIT(GICR_REG, GICR_INT0); break;
        case EXTI_INT1 : SET_BIT(GICR_REG, GICR_INT1); break;
        case EXTI_INT2 : SET_BIT(GICR_REG, GICR_INT2); break;

        default: kErrorState = kFunctionParameterError;
    }
    #endif
    return kErrorState;
}
error_t EXTI_InterruptDisable(uint8_t kInterruptSource)
{
    error_t kErrorState = kNoError;
    #if MCU_TYPE == _AVR
    switch (kInterruptSource)
    {
        case EXTI_INT0 : CLR_BIT(GICR_REG, GICR_INT0); break;
        case EXTI_INT1 : CLR_BIT(GICR_REG, GICR_INT1); break;
        case EXTI_INT2 : CLR_BIT(GICR_REG, GICR_INT2); break;

        default: kErrorState = kFunctionParameterError;
    }
    #endif
    return kErrorState;
}

error_t EXTI_SetSenseControl (uint8_t kInterruptSource, uint8_t kSenseControl)
{
    error_t kErrorState = kNoError;
    #if MCU_TYPE ==_AVR
    if (kInterruptSource == EXTI_INT0  )
    {
        switch (kSenseControl)
        {
            case EXTI_LOW_LEVEL:
                CLR_BIT(MCUCR_REG, MCUCR_ISC00);
                CLR_BIT(MCUCR_REG, MCUCR_ISC01);
                break;

            case EXTI_ON_CHANGE:
                SET_BIT(MCUCR_REG, MCUCR_ISC00);
                CLR_BIT(MCUCR_REG, MCUCR_ISC01);
                break;

            case EXTI_FALLING_EDGE:
                CLR_BIT(MCUCR_REG, MCUCR_ISC00);
                SET_BIT(MCUCR_REG, MCUCR_ISC01);
                break;

            case EXTI_RISING_EDGE:
                SET_BIT(MCUCR_REG, MCUCR_ISC00);
                SET_BIT(MCUCR_REG, MCUCR_ISC01);
                break;

            default: kErrorState = kFunctionParameterError;
        }
    }else if (kInterruptSource == EXTI_INT1  )
    {
        switch (kSenseControl)
        {
            case EXTI_LOW_LEVEL:
                CLR_BIT(MCUCR_REG, MCUCR_ISC10);
                CLR_BIT(MCUCR_REG, MCUCR_ISC11);
                break;

            case EXTI_ON_CHANGE:
                SET_BIT(MCUCR_REG, MCUCR_ISC10);
                CLR_BIT(MCUCR_REG, MCUCR_ISC11);
                break;

            case EXTI_FALLING_EDGE:
                CLR_BIT(MCUCR_REG, MCUCR_ISC10);
                SET_BIT(MCUCR_REG, MCUCR_ISC11);
                break;

            case EXTI_RISING_EDGE:
                ET_BIT(MCUCR_REG, MCUCR_ISC10);
                SET_BIT(MCUCR_REG, MCUCR_ISC11);
                break;

            default: kErrorState = kFunctionParameterError;
        }
    }else if (kInterruptSource == EXTI_INT2  )
    {
        switch (kSenseControl)
        {
            case EXTI_FALLING_EDGE : CLR_BIT(MCUCSR_REG, MCUCSR_ISC2); break;
            case EXTI_RISING_EDGE  : SET_BIT(MCUCSR_REG, MCUCSR_ISC2); break;

            default: kErrorState = kFunctionParameterError;
        }
    }else
    {
        kErrorState = kFunctionParameterError;
    }
    #endif
    return kErrorState;
}
error_t EXTI_SetCallBackFun  (uint8_t kInterruptSource, void (*pFun)(void))
{
    error_t kErrorState = kNoError;
    #if MCU_TYPE ==_AVR
    if (pFun != NULL_PTR)
    {
        switch (kInterruptSource)
        {
            case EXTI_INT0 : EXTI_pCallBackFun[0] = pFun; break;
            case EXTI_INT1 : EXTI_pCallBackFun[1] = pFun; break;
            case EXTI_INT2 : EXTI_pCallBackFun[2] = pFun; break;

            default: kErrorState = kFunctionParameterError;
        }
    }else
    {
        kErrorState = kFunctionParameterError;
    }
    #endif
    return kErrorState;
}
/* ISR Implementation   */
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
    if (EXTI_pCallBackFun[0]!=NULL_PTR)
    {
        EXTI_pCallBackFun[0]();
    }
}
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
    if (EXTI_pCallBackFun[1]!=NULL_PTR)
    {
        EXTI_pCallBackFun[1]();
    }
}
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
    if (EXTI_pCallBackFun[2]!=NULL_PTR)
    {
        EXTI_pCallBackFun[2]();
    }
}
