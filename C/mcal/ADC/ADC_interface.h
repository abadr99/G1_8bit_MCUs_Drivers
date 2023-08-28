#ifndef MCAL_ADC_INTERFACE_H_
#define MCAL_ADC_INTERFACE_H_

#define AREF (0)
#define AVCC (1)
#define INTERNAL (3)
#define ADMUX_REFS1 (7)
#define ADMUX_REFS0 (6)
#define ADMUX_ADLAR (5)
#define RIGHT_ADJUSMENT (0)
#define LEFT_ADJUSMENT (1)
#define ADCSRA_ADIE (3)
#define ADCSRA_ADIF (4)
#define ADCSRA_ADSC (6)
#define ADCSRA_ADEN (7)
#define ADC_PRE_MASK (0b1111000)
#define ADC_CH_MASK (0b1110000)
error_t  ADC_Init ();
void ADC_ENABLE();
void ADC_DISABLE();
void ADC_INTERRUPT_ENABLE();
error_t  ADC_Prescaler (uint8_t prescalerVal);
error_t GetResultSynch(uint8_t channel, uint16* result);
error_t StartConvASynch(uint8_t channel, uint16* result,
                                void (*function)(void));
#endif //MCAL_ADC_INTERFACE_H_
