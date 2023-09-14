#include "../../../common/Types.h"
#include "../../../common/Utils.h"
#include "../../../common/Config.h"
#include "../../../common/Registes.h"
#include "../../../mcal/GPIO/GPIOPrivate.h"
#include "../../../mcal/GPIO/GPIO.h"
#include "calc.h"
uint8_t ISNUM(uint8_t key)
{uint8_t state=OPERATOR;
    if (key>='0'&&key<='9')
    {
        state=NUMBER;
    }
    return state;
}
uint8_t GetPrecedence(uint8_t operator)
{uint8_t state;
    if (operator=='-'||operator=='+')
    {
        state=1;
    }
    else
    {
        state=2;
    }
    return state;
}
sint32 Operate(sint32 num1, sint32 num2, uint8_t operator)
{sint32 result=0;
    switch (operator)
    {
    case '+':
        result=num1+num2;
        break;
    case '-':
        result=num1-num2;
        break;
    case '*':
        result=num1*num2;
        break;
    case '/':
        result=num1/num2;
        break;
    }
    return result;
}
void Evaluate(sint32 *ar, uint8_t *arr, sint16 size1, sint16 size2)
{
while (size2>0)
{
    sint32 result=operatr(ar[size1-2], ar[size1-1], arr[size2-1]);
    ar[size1-2]=result;
    size1--;
    size2--;
}
}
