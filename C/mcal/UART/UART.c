#include "../../common/Config.h"
#include "../../common/Types.h"
#include "../../common/Utils.h"
#include "../../common/Registes.h"
#include "UART_Private.h"
#include "UART.h"

error_t UART_Init(void)
{
    error_t kErrorState = kNoError;
    #if MCU_TYPE == _PIC
    /*Asynchronous mode*/
    SET_BIT(RCSTA_REG, RCSTA_SPEN);
    CLR_BIT(TXSTA_REG, TXSTA_SYNC);
    /*Baud Rate*/
    SET_BIT(TXSTA_REG, TXSTA_BRGH);
    SPBRGH_REG = 51;
    /*TRIS Control*/
    SET_BIT(TRISC_REG, TRISC_TRISC7);
    /*Transmitter Enable*/
    SET_BIT(TXSTA_REG, TXSTA_TXEN);
    /*Receiver Enable*/
    SET_BIT(RCSTA_REG, RCSTA_CREN);
    #endif
    return kErrorState;
}
error_t UART_Transmit(uint8_t data)
{
    #if MCU_TYPE == _PIC
    error_t kErrorState = kNoError;
    while ((GET_BIT(TXSTA_REG, TXSTA_TRMT)) == 0)
    {

    }
    TXREG_REG = data;
    #endif
    return kErrorState;
}
error_t UART_Receive(uint8_t *data)
{
    error_t kErrorState = kNoError;
    #if MCU_TYPE == _PIC
    if (data != NULL)
    {
        while ((GET_BIT(PIR1_REG, PIR1_RCIF)) == 0)
        {

        }
        *data = RCREG_REG;
    }
    else
    {
        kErrorState = kFunctionParameterError;
    }
    #endif
    return kErrorState;
}
#if MCU_TYPE == _PIC
error_t ClearFlag(void)
{
    error_t kErrorState = kNoError;
    if ((GET_BIT(PIR1_REG, PIR1_RCIF)) == 1)
    {
      CLR_BIT(PIR1_REG, PIR1_RCIF);
    }
    return kErrorState;
}
#endif
