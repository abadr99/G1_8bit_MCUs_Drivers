#include "../../../common/Types.h"
#include "../../../common/Utils.h"
#include "../../../common/Config.h"
#include "../../../common/Registes.h"
#include "../../../mcal/GPIO/GPIOPrivate.h"
#include "../../../mcal/GPIO/GPIO.h"

#define SPECIAL_OUTPUT_PORT (*((volatile char *)0x20))
#define SPECIAL_INPUT_PORT  (*((volatile char *)0x22))

void print_str(const char *str)
{
    const char *c;
    for (c = str; *c != NULL ; c++)
    {
        SPECIAL_OUTPUT_PORT = *c;
    }
}

void print_num(int num)
{
    char str[15];
    int i = 0;
    while (num != 0)
    {
        str[i++] = (num % 10) + '0';
        num /= 10;
    }
    for (int j = i - 1 ; j >= 0 ; j--)
    {
        SPECIAL_OUTPUT_PORT = str[j];
    }
}

int main()
{
    GPIO_SetPinDirection(kPORTA, kPIN0, kOutput);
    print_str("DDRA_REG: ");
    print_num(DDRA_REG); 
    print_str("\n");

    GPIO_SetPinDirection(kPORTA, kPIN1, kInput);
    print_str("DDRA_REG: ");
    print_num(DDRA_REG); 
    print_str("\n");

    GPIO_SetPinDirection(kPORTA, kPIN2, kOutput);
    print_str("DDRA_REG: ");
    print_num(DDRA_REG); 
    print_str("\n");

    GPIO_SetPinDirection(kPORTA, kPIN3, kInput);
    print_str("DDRA_REG: ");
    print_num(DDRA_REG); 
    print_str("\n");

    GPIO_SetPinDirection(kPORTA, kPIN4, kOutput);
    print_str("DDRA_REG: ");
    print_num(DDRA_REG); 
    print_str("\n");

    GPIO_SetPinDirection(kPORTA, kPIN5, kInput);
    print_str("DDRA_REG: ");
    print_num(DDRA_REG); 
    print_str("\n");

    GPIO_SetPinDirection(kPORTA, kPIN6, kInput);
    print_str("DDRA_REG: ");
    print_num(DDRA_REG); 
    print_str("\n");

    GPIO_SetPinDirection(kPORTA, kPIN7, kOutput);
    print_str("DDRA_REG: ");
    print_num(DDRA_REG); 
    print_str("\n");

}
