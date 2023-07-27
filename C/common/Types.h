#ifndef _types_H_
#define _types_H_

typedef unsigned char uint8_t;
typedef signed   char sint8_t;

typedef enum  {
    kPORTA,
    kPORTB,
    kPORTC,
    kPORTD,
    #if MCU_TYPE == _PIC
    kPORTE
   #endif
}port_t;

typedef enum  {
    kPIN0,
    kPIN1,
    kPIN2,
    kPIN3,
    kPIN4,
    kPIN5,
    kPIN6,
    kPIN7
}pin_t;

typedef enum  {
    kLow,
    kHigh
}state_t;

typedef enum  {
    kInput,
    kOutput
}direction_t;

// typedef unsigned short uint16_t;
// typedef signed   short sint16_t;

typedef enum
{ 
	kNoError ,
	kFunctioParameterError 
}error_t;


#endif //_types_H_