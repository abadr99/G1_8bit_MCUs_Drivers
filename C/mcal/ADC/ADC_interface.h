#ifndef MCAL_ADC_INTERFACE_H_
#define MCAL_ADC_INTERFACE_H_

#define ADC_AREF (0)
#define ADC_AVCC (1)
#define ADC_INTERNAL_2_56 (3)

#define RIGHT_ADJUSTMENT (0)
#define LEFT_ADJUSTMENT  (1)

typedef enum
{
    ADC_CHANNEL0,
    ADC_CHANNEL1,
    ADC_CHANNEL2,
    ADC_CHANNEL3,
    ADC_CHANNEL4,
    ADC_CHANNEL5,
    ADC_CHANNEL6,
    ADC_CHANNEL7
}ADC_Channel_t;


error_t ADC_Init (void);
void ADC_ENABLE(void);
void ADC_DISABLE(void);
void ADC_INTERRUPT_ENABLE(void);
error_t ADC_Prescaler (uint8_t prescalerVal);
error_t ADC_GetResultSynch(uint8_t channel, uint16* result);
error_t ADC_StartConvASynch(uint8_t channel, uint16* result,
                                void (*function)(void));
#endif /* MCAL_ADC_INTERFACE_H_ */
