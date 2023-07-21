#ifndef _REGISTERS_H_
#define _REGISTERS_H_

#if MCU_TYPE == _AVR
    #define SREG       *((volatile uint8_t *)0x5F)
    
    #define DDRA_REG   *((volatile uint8_t *)0x3A)
    #define DDRB_REG   *((volatile uint8_t *)0x37)
    #define DDRD_REG   *((volatile uint8_t *)0x31)
    #define DDRC_REG   *((volatile uint8_t *)0x34)
    #define GPIO_DIRECTION_REGA  DDRA_REG    
    #define GPIO_DIRECTION_REGB  DDRB_REG
    #define GPIO_DIRECTION_REGC  DDRD_REG
    #define GPIO_DIRECTION_REGD  DDRC_REG

    #define PINA_REG   *((volatile uint8_t *)0x39)
    #define PINB_REG   *((volatile uint8_t *)0x36)
    #define PINC_REG   *((volatile uint8_t *)0x33)
    #define PIND_REG   *((volatile uint8_t *)0x30)
    #define GPIO_INPUT_REGA  PINA_REG
    #define GPIO_INPUT_REGB  PINB_REG
    #define GPIO_INPUT_REGC  PINC_REG
    #define GPIO_INPUT_REGD  PIND_REG



    #define PORTA_REG  *((volatile uint8_t *)0x3B)
    #define PORTB_REG  *((volatile uint8_t *)0x38)
    #define PORTC_REG  *((volatile uint8_t *)0x35)
    #define PORTD_REG  *((volatile uint8_t *)0x32)
    #define GPIO_OUTPUT_REGA  PORTA_REG  
    #define GPIO_OUTPUT_REGB  PORTB_REG  
    #define GPIO_OUTPUT_REGC  PORTC_REG  
    #define GPIO_OUTPUT_REGD  PORTD_REG 

#elif MCU_TYPE == _PIC
    #define TRISA_REG   *((volatile uint8_t *)0xF92)
    #define TRISB_REG   *((volatile uint8_t *)0xF93)
    #define TRISC_REG   *((volatile uint8_t *)0xF94)
    #define TRISD_REG   *((volatile uint8_t *)0xF95)
    #define TRISE_REG   *((volatile uint8_t *)0xF96)
    #define GPIO_DIRECTION_REGA  ATRISA_REG    
    #define GPIO_DIRECTION_REGB  ATRISB_REG
    #define GPIO_DIRECTION_REGC  ATRISC_REG
    #define GPIO_DIRECTION_REGD  ATRISD_REG
    #define GPIO_DIRECTION_REGE  ATRISD_REG



    #define PORTA_REG   *((volatile uint8_t *)0xF80)
    #define PORTB_REG   *((volatile uint8_t *)0xF81)
    #define PORTC_REG   *((volatile uint8_t *)0xF82)
    #define PORTD_REG   *((volatile uint8_t *)0xF83)
    #define PORTE_REG   *((volatile uint8_t *)0xF84)
    #define GPIO_INPUT_REGA  PORTA_REG
    #define GPIO_INPUT_REGB  PORTB_REG
    #define GPIO_INPUT_REGC  PORTC_REG
    #define GPIO_INPUT_REGD  PORTD_REG
    #define GPIO_INPUT_REGE  PORTE_REG


    #define LATA_REG    *((volatile uint8_t *)0xF89)
    #define LATB_REG    *((volatile uint8_t *)0xF8A)
    #define LATC_REG    *((volatile uint8_t *)0xF8B)
    #define LATD_REG    *((volatile uint8_t *)0xF8C)
    #define LATE_REG    *((volatile uint8_t *)0xF8D)
    #define GPIO_OUTPUT_REGA  LATA_REG
    #define GPIO_OUTPUT_REGB  LATB_REG
    #define GPIO_OUTPUT_REGC  LATC_REG
    #define GPIO_OUTPUT_REGD  LATD_REG
    #define GPIO_OUTPUT_REGE  LATE_REG






#endif  // MCU_TYPE

#endif //_REGISTERS_H_