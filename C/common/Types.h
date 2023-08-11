#ifndef Types_H_
#define Types_H_


typedef unsigned char uint8_t;                  //IGNORE-STYLE-CHECK[B004]
typedef signed   char sint8_t;                  //IGNORE-STYLE-CHECK[B004]
typedef float f32_t;                            //IGNORE-STYLE-CHECK[B004]
typedef unsigned short int  uint16;
typedef signed short int    sint16;

#define NULL_ptr ((void*)0)

#ifndef NULL
#define NULL ((void*)0)
#endif
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
    kFunctionParameterError
}error_t;


#endif //_types_H_
