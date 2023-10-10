#ifndef REGISTERS_H
#define REGISTERS_H

#if MCU_TYPE == _AVR
    #define DDRA_REG   *((volatile uint8_t *)0x3A)
    #define DDRB_REG   *((volatile uint8_t *)0x37)
    #define DDRD_REG   *((volatile uint8_t *)0x31)
    #define DDRC_REG   *((volatile uint8_t *)0x34)
    #define PINA_REG   *((volatile uint8_t *)0x39)
    #define PINB_REG   *((volatile uint8_t *)0x36)
    #define PINC_REG   *((volatile uint8_t *)0x33)
    #define PIND_REG   *((volatile uint8_t *)0x30)
    #define PORTA_REG  *((volatile uint8_t *)0x3B)
    #define PORTB_REG  *((volatile uint8_t *)0x38)
    #define PORTC_REG  *((volatile uint8_t *)0x35)
    #define PORTD_REG  *((volatile uint8_t *)0x32)
    #define SREG_REG   *((volatile uint8_t* )0x5F)
    #define GICR_REG   *((volatile uint8_t *)0X5B)
    #define GIFR_REG   *((volatile uint8_t *)0X5A)
    #define MCUCR_REG  *((volatile uint8_t *)0X55)
    #define MCUCSR_REG *((volatile uint8_t *)0X54)
    #define ADCSRA_REG *((volatile uint8_t *)0X26)
    #define ADMUX_REG  *((volatile uint8_t *)0X27)
    #define ADCH_REG   *((volatile uint8_t *)0X25)
    #define ADCL_REG   *((volatile uint8_t *)0X24)
    #define SFIOR_REG  *((volatile uint8_t *)0X50)
    #define ADC_DATA_REG *((volatile uint16 *)0X24)


#elif MCU_TYPE == _PIC
    #define ADRESH      *((volatile uint8_t *)0xFC4)
    #define ADRESL      *((volatile uint8_t *)0xFC3)
    #define ADC_DATA_REG *((volatile uint16 *)0XFC3)
    #define ADCON0      *((volatile uint8_t *)0xFC2)
    #define ADCON1      *((volatile uint8_t *)0xFC1)
    #define ADCON0      *((volatile uint8_t *)0xFC0)
    #define TRISA_REG    *((volatile uint8_t *)0xF92)
    #define TRISB_REG    *((volatile uint8_t *)0xF93)
    #define TRISC_REG    *((volatile uint8_t *)0xF94)
    #define TRISD_REG    *((volatile uint8_t *)0xF95)
    #define TRISE_REG    *((volatile uint8_t *)0xF96)
    #define PORTA_REG    *((volatile uint8_t *)0xF80)
    #define PORTB_REG    *((volatile uint8_t *)0xF81)
    #define PORTC_REG    *((volatile uint8_t *)0xF82)
    #define PORTD_REG    *((volatile uint8_t *)0xF83)
    #define PORTE_REG    *((volatile uint8_t *)0xF84)
    #define LATA_REG     *((volatile uint8_t *)0xF89)
    #define LATB_REG     *((volatile uint8_t *)0xF8A)
    #define LATC_REG     *((volatile uint8_t *)0xF8B)
    #define LATD_REG     *((volatile uint8_t *)0xF8C)
    #define LATE_REG     *((volatile uint8_t *)0xF8D)
    #define RCON_REG     *((volatile uint8_t *)0xFD0)
    #define INTCON_REG   *((volatile uint8_t *)0xFF2)
    #define INTCON2_REG  *((volatile uint8_t *)0xFF1)
    #define INTCON3_REG  *((volatile uint8_t *)0xFF0)
    #define PIE1_REG    *((volatile uint8_t *)0xF9D)


#endif  // MCU_TYPE

#endif //_REGISTERS_H_
