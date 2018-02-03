#include <stdio.h>

int bitcount1(unsigned x);
int bitcount2(unsigned x);


int main()
{
    unsigned x = 1000;
    printf("bitcount1: %d\n", bitcount1(x));
    printf("bitcount2: %d\n", bitcount2(x));
}


int bitcount1(unsigned x)
{
    int b;
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}


int bitcount2(unsigned x)
{
    int b;
    for (b = 0; x != 0; x &= (x-1))
        b++;
    return b;
}
