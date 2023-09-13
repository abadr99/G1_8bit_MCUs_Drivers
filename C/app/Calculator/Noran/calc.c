#include "../../../common/Types.h"
#include "../../../common/Utils.h"
#include "../../../common/Config.h"
#include "../../../common/Registes.h"
#include "../../../mcal/GPIO/GPIOPrivate.h"
#include "../../../mcal/GPIO/GPIO.h"
#include "calc.h"
uint8_t ISNUM(uint8_t num)
{uint8_t state=0;
    if(num>='0'&&num<='9')
    {
        state=1;
    }
    return state;
}
uint8_t getPrecedence(uint8_t operator)
{uint8_t state;
    if(operator=='-'||operator=='+')
    {
        state=1;
    }
    else
    {
        state=2;
    }
    return state;
}
sint16 operatr(sint16 x,sint16 y,uint8_t operator)
{sint16 result=0;
    switch (operator)
    {
    case '+':
        result=x+y;
        break;
    case '-':
        result=x-y;
        break;
    case '*':
        result=x*y;
        break;
    case '/':
        result=x/y;
        break;
    }
    return result;
}