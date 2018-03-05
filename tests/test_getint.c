#include <stdio.h>
#include <tools/calculator/calc.h>
#include <tools/getint.c>

int main()
{
    int i;
    for (;;) {
        getint(&i);
        printf("%d\n", i);
    }
}
