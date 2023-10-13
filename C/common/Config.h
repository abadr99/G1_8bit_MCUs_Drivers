#ifndef CONFIG_H
#define CONFIG_H

#define _AVR     (1)
#define _PIC     (2)

//#define MCU_TYPE  (_AVR)

#if (MCU_TYPE != _AVR) 
#if (MCU_TYPE != _PIC) 
#error "Wrong Value For `MCU_TYPE` Macro. Expected _AVR, _PIC"
#endif
#endif 

#endif // CONFIG_H_H
