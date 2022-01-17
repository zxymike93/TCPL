#include <stdio.h>

int main()
{
        int x = 1, y = 2;
        int *p;

        p = &x;
        y = *p;
        printf("x: %d\n", x); // 1
        printf("y: %d\n", y); // 1

        *p = 0;
        printf("x: %d\n", x); // 0
        printf("y: %d\n", y); // 1

        return 0;
}