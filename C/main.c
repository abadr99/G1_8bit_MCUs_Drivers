#include "../../common/Types.h"
#include "../../common/Utils.h"
#include "../../common/Config.h"
#include "../../common/Registes.h"
#include "GPIOPrivate.h"
#include "GPIO.h"


/* This port corresponds to the "-W 0x20,-" command line option. */
#define SPECIAL_OP_PORT (*((volatile unsigned char *)0x12))

/* This port corresponds to the "-R 0x22,-" command line option. */
#define SPECIAL_IP_PORT  (*((volatile unsigned char *)0x12))

/* Poll the specified string out the debug port. */
void debug_puts(unsigned char val)
{
    SPECIAL_OP_PORT = val;
}

int main()
{
    //stdout = &simavr_stdout;
    // printf("Test Begin ---\n");
    GPIO_SetPinDirection(kPORTA, kPIN0, kOutput);
    GPIO_SetPinDirection(kPORTA, kPIN1, kInput);
    GPIO_SetPinDirection(kPORTA, kPIN2, kOutput);
    GPIO_SetPinDirection(kPORTA, kPIN3, kInput);
    GPIO_SetPinDirection(kPORTA, kPIN4, kOutput);
    GPIO_SetPinDirection(kPORTA, kPIN5, kInput);
    SPECIAL_OP_PORT = 0xca;
    //SPECIAL_IP_PORT = DDRA_REG;
    //printf("DDRA value: %02X\n", DDRA_REG);
}
