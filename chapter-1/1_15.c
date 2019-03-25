#include <stdio.h>

float fahr_to_celsius(int fahr)
{
        return (5.0 / 9.0) * (fahr - 32);
}

int main()
{
        int f;
        int lower, upper, step;

        lower = 0;
        upper = 300;
        step = 20;

        f = lower;
        while (f <= upper) {
                printf("%3d\t%6.1f\n", f, fahr_to_celsius(f));
                f = f + step;
        }

        return 0;
}