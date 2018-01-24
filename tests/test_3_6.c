#include <stdio.h>
#include "../exercises/3_6.c"

int main()
{
    int a = -100290;
    int b = 2980;
    char sa[100];
    char sb[100];
    // signed int min
    int c = -2147483648;
    char sc[100];


    itoa(a, sa, 6);
    itoa(b, sb, 6);
    printf("%s\n", sa);
    printf("%s\n", sb);

    itoa(c, sc, 6);
    printf("%s\n", sc);
}
