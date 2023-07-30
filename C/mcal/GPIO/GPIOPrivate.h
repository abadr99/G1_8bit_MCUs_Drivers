#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#define GPIO_LAST_PIN        (kPIN7)
#if MCU_TYPE == AVR
/* ----------- DEFINE SOME HELPER FUNCTION SPECIFIC FOR _AVR ------------ */
#define SET_DIR_OUTPUT(_Reg, _BitNum)  SET_BIT(_Reg, _BitNum)
#define SET_DIR_INPUT(_Reg, _BitNum)   CLR_BIT(_Reg, _BitNum)

/* ---------- DEFINE SOME HELPER MACROS SPECIFIC FOR _AVR ----------- */
#define GPIOA_DIR_REG        (DDRA_REG)
#define GPIOB_DIR_REG        (DDRB_REG)
#define GPIOC_DIR_REG        (DDRC_REG)
#define GPIOD_DIR_REG        (DDRD_REG)
#define GPIOA_IN_REG         (PINA_REG)
#define GPIOB_IN_REG         (PINB_REG)
#define GPIOC_IN_REG         (PINC_REG)
#define GPIOD_IN_REG         (PIND_REG)
#define GPIOA_OUT_REG        (PORTA_REG)
#define GPIOB_OUT_REG        (PORTB_REG)
#define GPIOC_OUT_REG        (PORTC_REG)
#define GPIOD_OUT_REG        (PORTD_REG)
#define GPIO_LAST_REG        (kPORTD)

#elif MCU_TTPE == PIC

/* ----------- DEFINE SOME HELPER FUNCTION SPECIFIC FOR _PIC ---------- */
#define SET_DIR_OUTPUT(_Reg, _BitNum)  CLR_BIT(_Reg, _BitNum)
#define  SET_DIR_INPUT(_Reg, _BitNum)  SET_BIT(_Reg, _BitNum)

/* ----------- DEFINE SOME HELPER MACROS SPECIFIC FOR _PIC ------------ */
#define GPIOA_DIR_REG  (ATRISA_REG)
#define GPIOB_DIR_REG  (ATRISB_REG)
#define GPIOC_DIR_REG  (ATRISC_REG)
#define GPIOD_DIR_REG  (ATRISD_REG)
#define GPIO_DIRECTION_REGE  (ATRISD_REG)
#define GPIOA_IN_REG      (PORTA_REG)
#define GPIOB_IN_REG      (PORTB_REG)
#define GPIOC_IN_REG      (PORTC_REG)
#define GPIOD_IN_REG      (PORTD_REG)
#define GPIO_INPUT_REGE   (PORTE_REG)
#define GPIOA_OUT_REG     (LATA_REG)
#define GPIOB_OUT_REG     (LATB_REG)
#define GPIOC_OUT_REG     (LATC_REG)
#define GPIOD_OUT_REG     (LATD_REG)
#define GPIO_OUTPUT_REGE  (LATE_REG)
#define GPIO_LAST_REG      (kPORTE)
#endif //MCU_TYPE

#endif //_GPIO_PRIVATE_H_
