#include <stdio.h>
#include "getint.c"

int main()
{
    int i;
    for (;;) {
        getint(&i);
        printf("%d\n", i);
    }
}
