#ifndef Types_H_
#define Types_H_

typedef unsigned char uint8_t;                  //IGNORE-STYLE-CHECK[B004]
typedef signed   char sint8_t;                  //IGNORE-STYLE-CHECK[B004]
typedef float f32_t;                            //IGNORE-STYLE-CHECK[B004]
typedef unsigned short int  uint16;
typedef signed short int    sint16;

typedef unsigned long uint32_t;                  //IGNORE-STYLE-CHECK[B004]
typedef signed   long sint32_t;                  //IGNORE-STYLE-CHECK[B004]

#define NULL_PTR ((void*)0)

#ifndef NULL
#define NULL ((void*)0)
#endif

typedef enum
{
    kLow,
    kHigh
}state_t;
typedef enum
{
    kPORTA,
    kPORTB,
    kPORTC,
    kPORTD,
    #if MCU_TYPE == PIC
    kPORTE
   #endif
}port_t;

typedef enum
{
    kPIN0,
    kPIN1,
    kPIN2,
    kPIN3,
    kPIN4,
    kPIN5,
    kPIN6,
    kPIN7
}pin_t;

// typedef unsigned short uint16_t;
// typedef signed   short sint16_t;

typedef enum
{
	kNoError,
    kFunctionParameterError,
    kTimeoutError
}error_t;


#endif //_types_H_
