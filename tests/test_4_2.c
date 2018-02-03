#include <stdio.h>
#include "../exercises/4_2.c"


double atof(char s[]);


int main(void)
{
    // 指针数组
    int i;
    char *ps[8] = {"0.0", ".2", "1234.9990", "-1234.9990", 
        "-1234.9909e", "-1234.9909e-2", "-1234.9909E-2", "-1234.9909E10"};

    for (i = 0; i < 8; i++) {
        printf("char: %s\n", ps[i]);
        printf("float: %.2f\n", atof(ps[i]));
    }
    return 0;
}
