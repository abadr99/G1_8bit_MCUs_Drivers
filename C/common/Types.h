#ifndef _types_H_
#define _types_H_

typedef unsigned char uint8_t;
typedef signed   char sint8_t;

typedef enum
{ 
	NoError ,
	FunctioParameterError 
}Error_t;

#define SET_BIT(_Reg , _BitNum) ( _Reg |=  (1<<_BitNum))
#define CLR_BIT(_Reg , _BitNum) ( _Reg &= ~(1<<_BitNum))

#endif //_types_H_