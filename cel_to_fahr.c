#include <stdio.h>

/*
    带标题
    摄氏转华氏温度对照表
*/
main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 200;
    step = 20;

    printf("==== This is the Title ====");
    celsius = lower;
    while (celsius <= upper) {
        fahr = 9.0 / 5.0 * celsius + 32;
        printf("%6.0f\t%6.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}

