#include <stdio.h>

float fahr(int);

main()
{
    int f;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    f = lower;
    while (f <= upper) {
        printf("%3d\t%6.1f\n", f, fahr(f));
	f = f + step;
    }
    return 0;
}

float fahr(int fahr)
{
    float celsius;

    celsius = (5.0/9.0) * (fahr-32);
    return celsius;
}	

