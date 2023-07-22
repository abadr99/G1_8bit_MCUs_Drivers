#ifndef _GPIO_PRIVATE_H_
#define _GPIO_PRIVATE_H_

#if MCU_TYPE == _AVR
/* -------------- DEFINE SOME HELPER FUNCTION SPECIFIC FOR AVR -------------- */
#define SET_DIR_OUTPUT(_Reg , _BitNum)  SET_BIT(_Reg , _BitNum)
#define  SET_DIR_INPUT(_Reg , _BitNum)  CLR_BIT(_Reg , _BitNum)

/* -------------- DEFINE SOME HELPER MACROS SPECIFIC FOR AVR -------------- */
#define GPIO_DIRECTION_REGA  (DDRA_REG)
#define GPIO_DIRECTION_REGB  (DDRB_REG)
#define GPIO_DIRECTION_REGC  (DDRD_REG)
#define GPIO_DIRECTION_REGD  (DDRC_REG)
#define GPIO_INPUT_REGA      (PINA_REG)
#define GPIO_INPUT_REGB      (PINB_REG)
#define GPIO_INPUT_REGC      (PINC_REG)
#define GPIO_INPUT_REGD      (PIND_REG)
#define GPIO_OUTPUT_REGA     (PORTA_REG)
#define GPIO_OUTPUT_REGB     (PORTB_REG)
#define GPIO_OUTPUT_REGC     (PORTC_REG)
#define GPIO_OUTPUT_REGD     (PORTD_REG)

#elif MCU_TTPE == _PIC

/* -------------- DEFINE SOME HELPER FUNCTION SPECIFIC FOR PIC -------------- */
#define SET_DIR_OUTPUT(_Reg , _BitNum)  CLR_BIT(_Reg , _BitNum)
#define  SET_DIR_INPUT(_Reg , _BitNum)  SET_BIT(_Reg , _BitNum)

/* -------------- DEFINE SOME HELPER MACROS SPECIFIC FOR PIC -------------- */
#define GPIO_DIRECTION_REGA  (ATRISA_REG)    
#define GPIO_DIRECTION_REGB  (ATRISB_REG)
#define GPIO_DIRECTION_REGC  (ATRISC_REG)
#define GPIO_DIRECTION_REGD  (ATRISD_REG)
#define GPIO_DIRECTION_REGE  (ATRISD_REG)
#define GPIO_INPUT_REGA      (PORTA_REG)
#define GPIO_INPUT_REGB      (PORTB_REG)
#define GPIO_INPUT_REGC      (PORTC_REG)
#define GPIO_INPUT_REGD      (PORTD_REG)
#define GPIO_INPUT_REGE      (PORTE_REG)
#define GPIO_OUTPUT_REGA     (LATA_REG)
#define GPIO_OUTPUT_REGB     (LATB_REG)
#define GPIO_OUTPUT_REGC     (LATC_REG)
#define GPIO_OUTPUT_REGD     (LATD_REG)
#define GPIO_OUTPUT_REGE     (LATE_REG)
#endif //MCU_TYPE


#endif //_GPIO_PRIVATE_H_