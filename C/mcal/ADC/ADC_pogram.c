#include "../../common/Config.h"
#include "../../common/Types.h"
#include "../../common/Utils.h"
#include "../../common/Registes.h"
#include "ADC_interface.h"
#include "ADC_Private.h"
#include "ADC_config.h"

static void (*ISRfunction)(void) =NULL;
static uint16* aSynchResult;
error_t ADC_Init (void)
{
    error_t kErrorState = kNoError;
    /* Select ADC Voltage Reference */
    #if ADC_VREF == ADC_AREF
        CLR_BIT(ADMUX_REG, ADMUX_REFS0);
        CLR_BIT(ADMUX_REG, ADMUX_REFS1);
    #elif ADC_VREF == ADC_AVCC
        SET_BIT(ADMUX_REG, ADMUX_REFS0);
        CLR_BIT(ADMUX_REG, ADMUX_REFS1);
    #elif ADC_VREF == ADC_INTERNAL_2_56
        SET_BIT(ADMUX_REG, ADMUX_REFS0);
        SET_BIT(ADMUX_REG, ADMUX_REFS1);
    
    #else 
        kErrorState = kFunctionParameterError;
    #endif   

    /* Select ADC Right/Left Adjust */
    #if ADC_ADJUSTMENT == LEFT_ADJUSTMENT
        SET_BIT(ADMUX_REG, ADMUX_ADLAR);
    #elif ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
        CLR_BIT(ADMUX_REG, ADMUX_ADLAR);
    #else
        kErrorState = kFunctionParameterError;
    #endif

    /* Select Prescaler */
    ADCSRA_REG &= ADC_PRE_MASK;
    ADCSRA_REG |= ADC_PRESCALER;

    return kErrorState;
}

void ADC_ENABLE(void)
{
    SET_BIT(ADCSRA_REG, ADCSRA_ADEN);
}

void ADC_DISABLE(void)
{
     CLR_BIT(ADCSRA_REG, ADCSRA_ADEN);
}

void ADC_INTERRUPT_ENABLE(void)
{
    SET_BIT(ADCSRA_REG, ADCSRA_ADIE);
}

void ADC_INTERRUPT_DISABLE(void)
{
    CLR_BIT(ADCSRA_REG, ADCSRA_ADIE);
}

error_t  ADC_Prescaler (uint8_t prescalerVal)
{
    error_t kErrorState = kNoError;
    if (prescalerVal<ADC_PRESCALER_128)
    {
        ADCSRA_REG&=ADC_PRE_MASK;
        ADCSRA_REG|=prescalerVal;
    }
    else
    {
        kErrorState = kFunctionParameterError;
    }
    return kErrorState;
}
error_t ADC_GetResultSynch(uint8_t channel, uint16* result)
{
    error_t kErrorState = kNoError;
    if (result!=NULL)
    {
        /* Select Channel */
        ADMUX_REG &=ADC_CH_MASK;
        ADMUX_REG |=channel;

        /* Start Conversion */
        SET_BIT(ADCSRA_REG, ADCSRA_ADSC);

        uint8_t timer=0;
        while ((GET_BIT(ADCSRA_REG, ADCSRA_ADIF)==0)&&(timer<TIMEOUT))
        {
            timer++;
        }
        if (timer==TIMEOUT)
        {
            kErrorState =kTimeoutError;
        }
        else
        {
            /* Clear ADC Interrupt Flag */
            SET_BIT(ADCSRA_REG, ADCSRA_ADIF);

            #if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
                *result = ADCL_REG | (ADCH_REG<<8);

            #elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
                *result = (ADCL_REG>>6) | (ADCH_REG<<2);

            #else
                kErrorState = kFunctionParameterError;
            #endif
        }
    }
    else
    {
        kErrorState = kFunctionParameterError;
    }
    return kErrorState;
}
error_t ADC_StartConvASynch(uint8_t channel, uint16* result, void (*function)(void))
{
    error_t kErrorState = kNoError;
    if (result!=NULL)
    {
        aSynchResult=result;
        ISRfunction=function;
        ADMUX_REG &=ADC_CH_MASK;
        ADMUX_REG =channel;
        SET_BIT(ADCSRA_REG, ADCSRA_ADSC);
        ADC_INTERRUPT_ENABLE();
    }
    else
    {
        kErrorState = kFunctionParameterError;
    }
    return kErrorState;
}
