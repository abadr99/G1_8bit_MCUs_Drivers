#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define USART_PARITY_MODE  (DISABLE)

#define TXSTA_TXEN          (5)
#define TXSTA_SYNC          (4)
#define TXSTA_BRGH          (2)
#define TXSTA_TRMT          (1)

#define RCSTA_SPEN          (7)
#define RCSTA_CREN          (4)

#define TRISC_TRISC7        (7)

#define PIR1_RCIF           (5)

#define DISABLE             (0)
#define EVEN_PARITY         (1)
#define ODD_PARITY          (2)
#define UDRE_UCSRA          (5)
#define RXC_UCSRA           (7)
#define UMSEL_UCSRC         (6)
#define UPM1_UCSRC          (5)
#define UPM0_UCSRC          (4)
#define TXEN_UCSRB          (3)
#define RXEN_UCSRB          (4)
#define USBS_UCSRC          (4)
#define UCSZ0_UCSRC         (1)
#define UCSZ1_UCSRC         (2)
#define UCSZ2_UCSRB         (2)
#define URSEL_UCSRC         (7)
#endif
