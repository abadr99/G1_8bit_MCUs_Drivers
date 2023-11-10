#include "../../common/Config.h"
#include "../../common/Types.h"
#include "../../common/Utils.h"
#include "../../common/Registes.h"
#include "UART_Private.h"
#include "UART.h"

error_t UART_Init(void)
{
    error_t kErrorState = kNoError;
    #if MCU_TYPE == _AVR
    uint8_t ucsrcVal=0;
    /*Asynchronous mode*/
    CLR_BIT(UCSRC_REG, UMSEL_UCSRC);
    /*Parity Mode*/
     #if UART_PARITY_MODE == DISABLE
     CLR_BIT(UCSRC_REG, UPM0_UCSRC);
     CLR_BIT(UCSRC_REG, UPM1_UCSRC);
     #elif UART_PARITY_MODE == EVEN_PARITY
     CLR_BIT(UCSRC_REG, UPM0_UCSRC);
     SET_BIT(UCSRC_REG, UPM1_UCSRC);
     #elif UART_PARITY_MODE == ODD_PARITY
     SET_BIT(UCSRC_REG, UPM0_UCSRC);
     SET_BIT(UCSRC_REG, UPM1_UCSRC);
     #else
     kErrorState=kFunctionParameterError;
     #endif
     /*Transmitter Enable*/
     SET_BIT(UCSRB_REG, TXEN_UCSRB);
     /*Receiver Enable*/
     SET_BIT(UCSRB_REG, RXEN_UCSRB);
     /*Stop Bit*/
     CLR_BIT(UCSRC_REG, USBS_UCSRC);
     /*Data Size*/
     #if USART_DATA_SIZE == DATA_SIZE_5_BIT
     CLR_BIT(UCSRC_REG, UCSZ0_UCSRC);
     CLR_BIT(UCSRC_REG, UCSZ1_UCSRC);
     CLR_BIT(UCSRB_REG, UCSZ2_UCSRB);
     #elif USART_DATA_SIZE == DATA_SIZE_6_BIT
     SET_BIT(UCSRC_REG, UCSZ0_UCSRC);
     CLR_BIT(UCSRC_REG, UCSZ1_UCSRC);
     CLR_BIT(UCSRB_REG, UCSZ2_UCSRB);
     #elif USART_DATA_SIZE == DATA_SIZE_7_BIT
     CLR_BIT(UCSRC_REG, UCSZ0_UCSRC);
     SET_BIT(UCSRC_REG, UCSZ1_UCSRC);
     CLR_BIT(UCSRB_REG, UCSZ2_UCSRB);
     #elif USART_DATA_SIZE == DATA_SIZE_8_BIT
     SET_BIT(UCSRC_REG, UCSZ0_UCSRC);
     SET_BIT(UCSRC_REG, UCSZ1_UCSRC);
     CLR_BIT(UCSRB_REG, UCSZ2_UCSRB);
     #elif USART_DATA_SIZE == DATA_SIZE_5_BIT
     SET_BIT(UCSRC_REG, UCSZ0_UCSRC);
     SET_BIT(UCSRC_REG, UCSZ1_UCSRC);
     SET_BIT(UCSRB_REG, UCSZ2_UCSRB);
     #else
     kErrorState=kFunctionParameterError;
     #endif
     SET_BIT(UCSRC_REG, URSEL_UCSRC);
     UCSRC_REG=ucsrcVal;
     /*Baud Rate 9600*/
     UBRRL_REG=103;

    #elif MCU_TYPE == _PIC
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
    error_t kErrorState = kNoError;
    #if MCU_TYPE == _AVR
    while ((GET_BIT(UCSRA_REG, UDRE_UCSRA)) == 0)
    {

    }
    UDR_REG= data;
    #elif MCU_TYPE == _PIC
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
    #if MCU_TYPE == _AVR
    if (data != NULL)
    {
        while ((GET_BIT(UCSRA_REG, RXC_UCSRA)) == 0)
        {

        }
        *data = UDR_REG;
    }
    else
    {
        kErrorState = kFunctionParameterError;
    }
    #elif MCU_TYPE == _PIC
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
