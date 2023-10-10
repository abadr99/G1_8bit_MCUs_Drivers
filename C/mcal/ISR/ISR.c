#include "../../common/Types.h"
#include "../../common/Utils.h"
#include "../../common/Registes.h"
#include "ISR_private.h"
#include "ISR.h"

static void (*EXTI_pCallBackFun[3]) (void) = {NULL_PTR};
static void (*ADC_pCallBackFun) (void) = NULL_PTR;

error_t ISR_Init(uint8_t kInterruptSource, void (*pFun)(void))
{
    error_t retErrorState = kNoError;
    if (pFun != NULL_PTR)
    {
        switch (kInterruptSource)
        {
           case EXTI_INT0 : EXTI_pCallBackFun[0] = pFun; break;
           case EXTI_INT1 : EXTI_pCallBackFun[1] = pFun; break;
           case EXTI_INT2 : EXTI_pCallBackFun[2] = pFun; break;
           case ADC_INT   : ADC_pCallBackFun = pFun;     break;
        }
    }
    else
    {
        retErrorState = kFunctionParameterError;
    }
    return retErrorState;
}
#if MCU_TYPE ==_AVR
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
#elif MCU_TYPE == _PIC
void __interrupt() ISR()
{
    if ((GET_BIT(INTCON_REG, INTCON_INT0F)) == kHigh)
    {
        EXTI_pCallBackFun[0]();
    }
    else if ((GET_BIT(INTCON3_REG, INTCON3_INT1IF)) == kHigh)
    {
        EXTI_pCallBackFun[1]();
    }
    else if ((GET_BIT(INTCON3_REG, INTCON3_INT2IF)) == kHigh)
    {
        EXTI_pCallBackFun[2]();
    }
   /* else if (ADIF == kHigh)
   {
        ADC_pCallBackFun();
   }
   */
}
#endif
