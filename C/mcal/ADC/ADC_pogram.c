#include "../../common/Config.h"
#include "../../common/Types.h"
#include "../../common/Utils.h"
#include "../../common/Registes.h"
#include "ADC_config.h"
#include "ADC_interface.h"

static void (*ISRfunction)(void) =NULL;
static uint16* aSynchResult;
error_t  ADC_Init ()
{
    error_t kErrorState = kNoError;
    #if ADC_VREF == AREF
    CLR_BIT(ADMUX_REG, ADMUX_REFS0);
    CLR_BIT(ADMUX_REG, ADMUX_REFS1);
    #elif ADC_VREF == AVCC
    SET_BIT(ADMUX_REG, ADMUX_REFS0);
    CLR_BIT(ADMUX_REG, ADMUX_REFS1);
    #elif ADC_VREF== INTERNAL
    SET_BIT(ADMUX_REG, ADMUX_REFS0);
    SET_BIT(ADMUX_REG, ADMUX_REFS1);
    #else
    kErrorState = kFunctionParameterError;
    #endif
    #if ADC_ADJUSTMENT == LEFT_ADJUSMENT
     SET_BIT(ADMUX_REG, ADMUX_ADLAR);
    #elif ADC_ADJUSTMENT == RIGHT_ADJUSMENT
    CLR_BIT(ADMUX_REG, ADMUX_ADLAR);
    #else
    kErrorState = kFunctionParameterError;
    #endif
    return kErrorState;
}
void ADC_ENABLE()
{
    SET_BIT(ADCSRA_REG, ADCSRA_ADEN);
}
void ADC_DISABLE()
{
     CLR_BIT(ADCSRA_REG, ADCSRA_ADEN);
}
void ADC_INTERRUPT_ENABLE()
{
    SET_BIT(ADCSRA_REG, ADCSRA_ADIE);
}
void ADC_INTERRUPT_DISABLE()
{
    CLR_BIT(ADCSRA_REG, ADCSRA_ADIE);
}
error_t  ADC_Prescaler (uint8_t prescalerVal)
{
    error_t kErrorState = kNoError;
    if (prescalerVal<8)
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
error_t GetResultSynch(uint8_t channel, uint16* result)
{
    error_t kErrorState = kNoError;
    if (result!=NULL)
    {
        ADMUX_REG &=ADC_CH_MASK;
        ADMUX_REG =channel;
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
             SET_BIT(ADCSRA_REG, ADCSRA_ADIF);
             #if ADC_ADJUSTMENT == RIGHT_ADJUSMENT
             *result=ADCL_REG|(ADCH_REG<<8);
             #elif ADC_ADJUSTMENT == LEFT_ADJUSMENT
            *result =ADCL_REG;
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
error_t StartConvASynch(uint8_t channel, uint16* result, void (*function)(void))
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
                                                                                                                                                                                                            