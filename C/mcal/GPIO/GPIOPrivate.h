#ifndef _GPIO_PRIVATE_H_
#define _GPIO_PRIVATE_H_

#if MCU_TYPE == _AVR
#define SET_DIR_OUTPUT(_Reg , _BitNum)  SET_BIT(_Reg , _BitNum)
#define  SET_DIR_INPUT(_Reg , _BitNum)  CLR_BIT(_Reg , _BitNum)
#elif MCU_TTPE == _PIC
#define SET_DIR_OUTPUT(_Reg , _BitNum)  CLR_BIT(_Reg , _BitNum)
#define  SET_DIR_INPUT(_Reg , _BitNum)  SET_BIT(_Reg , _BitNum)
#endif


#endif //_GPIO_PRIVATE_H_