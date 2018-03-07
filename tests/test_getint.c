#include <stdio.h>
#include <tools/calculator/calc.h>
#include <tools/getint.c>

#define SIZE    100

int main()
{
    int i, n, s[SIZE], getint(int *);

    for (n = 0; n < SIZE && getint(&s[n]) != EOF; n++)
        ;
    for (; n >= 0; n--) {
        printf("%d\n", s[n]);
    }
}
