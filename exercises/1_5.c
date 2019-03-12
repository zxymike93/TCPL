#include <stdio.h>


int main() {
    float fahr, celsius;
    int low=0, high=300, step=20;

    fahr = high;
    printf("Fahr to Celsius\n");
    printf("===============\n");
    while (fahr >= low) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr -= step;
    }
}
