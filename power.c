#include <stdio.h>

int power(int m, int n);

main()
{
    int i;

    for (i = 0; i < 10; ++i) {
        printf("%1d %3d %6d\n", i, power(2, i), power(3, i));
    }
    return 0;
}

/* power(base, n) 求 base**n */
int power(int base, int n)
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i) {
        p = p * base;
    }
    return p;
}


