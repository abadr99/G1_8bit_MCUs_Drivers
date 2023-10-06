/**
 * @file   EXTI_Program.c
 * @author :Mohamed Refat
 * @brief  :This file contain the implementation of EXTI functions
 * @version:0.1
 * @date   :2023-08-16
 */
#include "../../common/Config.h"
#include "../../common/Types.h"
#include "../../common/Utils.h"
#include "../../common/Registes.h"
#include "EXTI_Private.h"
#include "EXTI_Interface.h"
#include "../ISR/ISR.h"

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
    #if MCU_TYPE == _PIC
    switch (kInterruptSource)
    {
        case EXTI_INT0 : SET_BIT(INTCON_REG, INTCON_INT0E);    break;
        case EXTI_INT1 : SET_BIT(INTCON3_REG, INTCON3_INT1IE); break;
        case EXTI_INT2 : SET_BIT(INTCON3_REG, INTCON3_INT2IE); break;
        case EXTI_RB   : SET_BIT(INTCON_REG, INTCON_RBIE);     break;
        default: kErrorState = kFunctionParameterError;        break;
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
    #if MCU_TYPE == _PIC
    switch (kInterruptSource)
    {
        case EXTI_INT0 : CLR_BIT(INTCON_REG, INTCON_INT0E);    break;
        case EXTI_INT1 : CLR_BIT(INTCON3_REG, INTCON3_INT1IE); break;
        case EXTI_INT2 : CLR_BIT(INTCON3_REG, INTCON3_INT2IE); break;
        case EXTI_RB   : SET_BIT(INTCON_REG, INTCON_RBIE);     break;
        default: kErrorState = kFunctionParameterError;        break;
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
                SET_BIT(MCUCR_REG, MCUCR_ISC10);
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
    #if MCU_TYPE == _PIC
    if (kInterruptSource == EXTI_INT0)
    {
        switch (kSenseControl)
        {
            case EXTI_FALLING_EDGE : CLR_BIT(INTCON2, INTCON2_INTEDG0); break;
            case EXTI_RISING_EDGE  : SET_BIT(INTCON2, INTCON2_INTEDG0); break;
            default: kErrorState = kFunctionParameterError;             break;
        }
    }
    else if (kInterruptSource == EXTI_INT1)
    {
        switch (kSenseControl)
        {
            case EXTI_FALLING_EDGE : CLR_BIT(INTCON2, INTCON2_INTEDG1); break;
            case EXTI_RISING_EDGE  : SET_BIT(INTCON2, INTCON2_INTEDG1); break;
            default: kErrorState = kFunctionParameterError;             break;
        }
    }
    else if (kInterruptSource == EXTI_INT2)
    {
        switch (kSenseControl)
        {
            case EXTI_FALLING_EDGE : CLR_BIT(INTCON2, INTCON2_INTEDG2); break;
            case EXTI_RISING_EDGE  : SET_BIT(INTCON2, INTCON2_INTEDG2); break;
            default: kErrorState = kFunctionParameterError;             break;
        }
    }

    #endif

    return kErrorState;
}
#if MCU_TYPE == _PIC
error_t EXTI_ClearFlag(uint8_t kInterruptSource)
{
    error_t kErrorState = kNoError;
    switch (kInterruptSource)
    {
    case EXTI_INT0 : CLR_BIT(INTCON_REG, INTCON_INT0F);     break;
    case EXTI_INT1 : CLR_BIT(INTCON3_REG, INTCON3_INT1IF);  break;
    case EXTI_INT2 : CLR_BIT(INTCON3_REG, INTCON3_INT2IF);  break;
    default: kErrorState = kFunctionParameterError;         break;
    }
    return kErrorState;
}
error_t EXTI_SetPriority(uint8_t kInterruptSource, uint8_t kInterruptPriority)
{
    error_t kErrorState = kNoError;
    if (kInterruptPriority == EXIT_HIGH_PRIORITY)
    {
        switch (kInterruptSource)
        {
        case EXTI_INT1 : SET_BIT(INTCON3_REG, INTCON3_INT1IP);  break;
        case EXTI_INT2 : SET_BIT(INTCON3_REG, INTCON3_INT2IP);  break;
        default: kErrorState = kFunctionParameterError;         break;
        }
    }
    else if (kInterruptPriority == EXIT_LOW_PRIORITY)
    {
        switch (kInterruptSource)
        {
        case EXTI_INT1 : CLR_BIT(INTCON3_REG, INTCON3_INT1IP);  break;
        case EXTI_INT2 : CLR_BIT(INTCON3_REG, INTCON3_INT2IP);  break;
        default: kErrorState = kFunctionParameterError;         break;
        }
    }
    return kErrorState;
}
#endif
error_t EXTI_SetCallBackFun  (uint8_t kInterruptSource, void (*pFun)(void))
{
    error_t kErrorState = kNoError;
    if (pFun != NULL_PTR)
    {
        switch (kInterruptSource)
        {
            case EXTI_INT0 : ISR_Init(EXTI_INT0, pFun); break;
            case EXTI_INT1 : ISR_Init(EXTI_INT1, pFun); break;
            case EXTI_INT2 : ISR_Init(EXTI_INT2, pFun); break;

            default: kErrorState = kFunctionParameterError;
        }
    }else
    {
        kErrorState = kFunctionParameterError;
    }
    return kErrorState;
}
