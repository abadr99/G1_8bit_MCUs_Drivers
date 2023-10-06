#ifndef TEST_H_
#define TEST_H_

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
    if (num == 0)
    {
        SPECIAL_OUTPUT_PORT = '0';
    }
    else 
    {
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

}

void print_char(char C)
{
    SPECIAL_OUTPUT_PORT = C;
}

#endif // TEST_H_