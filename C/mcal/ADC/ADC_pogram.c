#include "../../common/Types.h"
#include "../../common/Utils.h"
#include "../../common/Registes.h"
#include "ADC_config.h"
#include "ADC_interface.h"

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
    #elif ADC_ADJUSTMENT == LEFT_ADJUSMENT
    CLR_BIT(ADMUX_REG, ADMUX_ADLAR);
    #else
    kErrorState = kFunctionParameterError;
    #endif   
    return  kErrorState ;
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