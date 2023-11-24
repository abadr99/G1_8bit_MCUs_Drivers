#include "../../common/Config.h"
#include "../../common/Types.h"
#include "../../common/Registes.h"
#include "../../common/Utils.h"
#include "../GIC/GIC_Interface.h"
#include "TIMER_Private.h"
#include "TIMER_Config.h"
#include "TIMER_Interface.h"

#if MCU_TYPE == _PIC
static uint16 preload_value = 0;
static void ( * Interrupt_Action) (void)=NULL_PTR;
error_t TIMER0_Init()
{
    error_t retErrorState = kNoError;
    /*Display Timer0*/
    CLR_BIT(T0CON_REG, TIMER0_TMR0ON);

    /*Configure Prescaler*/
    #if TIMER0_PRESCALER_SET == ENABLED
        CLR_BIT(T0CON_REG, TIMER0_PSA);
        T0CON_REG &=TIMER0_PRESCALER_MASK;
        T0CON_REG |=TIMER0_PRESCALER_VALUE;
    #elif TIMER0_PRESCALER_SET == DISABLED
        SET_BIT(T0CON_REG, TIMER0_PSA);
    #endif

    /*Configure Timer Mode */
    #if TIMER0_MODE == TIMER_MODE
        CLR_BIT(T0CON_REG, TIMER0_T0CS);
    #elif TIMER0_MODE == COUNTER_MODE
        SET_BIT(T0CON_REG, TIMER0_T0CS);
        #if TIMER0_COUNTER_EDGE == RAISING_EDGE
            CLR_BIT(T0CON_REG, TIMER0_T0SE);
        #elif TIMER0_COUNTER_EDGE == FALING_EDGE
            SET_BIT(T0CON_REG, TIMER0_T0SE);
        #else
            retErrorState = kFunctionParameterError;
        #endif
    #else
        retErrorState = kFunctionParameterError;
    #endif

    /*Configure TIMER0 Register Size*/
    #if TIMER0_REG_SIZE == TIMER_8BIT
        SET_BIT(T0CON_REG, TIMER0_T08BIT);
    #elif TIMER0_REG_SIZE == TIMER_16BIT
        CLR_BIT(T0CON_REG, TIMER0_T08BIT);
    #endif

    TMR0L_REG = 0;
    TMR0H_REG = 0;

    #if TIMER0_INTERRUPT == ENABLED
        SET_BIT(INTCON_REG, INTCON_TMR0IE);
        CLR_BIT(INTCON_REG, INTCON_TMR0IF);
        GIC_voidGlobalInterruptControl(GLOBAL_INTERRUPT_ENABLE);
        SET_BIT(INTCON_REG, INTCON_PEIE);
    #elif TIMER0_INTERRUPT == DISABLED

    #endif

    /*Display Timer0*/
    SET_BIT(T0CON_REG, TIMER0_TMR0ON);

    return retErrorState;
}
error_t TIMER0_Preload(uint16 value)
{
    error_t retErrorState = kNoError;
    TMR0L_REG = (uint8_t)value;
    TMR0H_REG = (value>>8);
    preload_value = value;
    return retErrorState;
}
error_t TIMER0_Handle_ISR(void ( * pFunction) (void))
{
    error_t retErrorState = kNoError;
    if (pFunction != NULL_PTR)
    {
        Interrupt_Action = pFunction;
    }
    else
    {
        retErrorState = kFunctionParameterError;
    }
    return retErrorState;
}
void TIMER0_WriteValue(uint16 value)
{
    TMR0L_REG = (uint8_t)value;
    TMR0H_REG = (value >> 8);
}
error_t TIMER0_ReadValue(uint16 * value)
{
    error_t retErrorState = kNoError;
    if (value != NULL_PTR)
    {
        *value = (uint16)(TMR0L_REG + (TMR0H_REG << 8));
    }
    else
    {
        retErrorState = kFunctionParameterError;
    }
    return retErrorState;
}
void __interrupt() ISR(void)
{
    if (INTCON_TMR0IF)
    {
        CLR_BIT(INTCON_REG, INTCON_TMR0IF);
        TMR0L_REG = (uint8_t)preload_value;
        TMR0H_REG = (preload_value>>8);
        Interrupt_Action();
    }
}
#endif
