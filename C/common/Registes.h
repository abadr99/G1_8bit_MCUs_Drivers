#if MCU_TYPE == AVR
    #define SREG    (*((uint8_t *)0x5F))
#elif MCU_TYPE == PIC
    #define TRISA   (*((uint8_t *)0xF92))
#endif  // MCU_TYPE