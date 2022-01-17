#include <stdio.h>

int main()
{
        float fahr, celsius;
        int low=0, high=300, step=20;

        celsius = low;
        printf("Celsius to Fahr\n");
        printf("===============\n");

        while (celsius <= high) {
                fahr = celsius / (5.0/9.0) + 32.0;
                printf("%3.0f %6.1f\n", fahr, celsius);
                celsius += step;
        }
}