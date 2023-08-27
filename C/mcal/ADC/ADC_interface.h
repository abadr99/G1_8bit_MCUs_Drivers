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
#define ADCSRA_ADEN (7)
#define ADCSRA_ADIE (3)

error_t  ADC_Init ();
void ADC_ENABLE();
void ADC_DISABLE();
void ADC_INTERRUPT_ENABLE();
#endif //MCAL_ADC_INTERFACE_H_
