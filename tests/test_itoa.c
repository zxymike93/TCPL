#include <stdio.h>
#include "../itoa.c"

int main()
{
    int a = -100290;
    int b = 2980;
    char sa[100];
    char sb[100];
    // signed int min
    int c = -2147483648;
    char sc[100];


    itoa(a, sa);
    itoa(b, sb);
    printf("%s\n", sa);
    printf("%s\n", sb);

    itoa(c, sc);
    printf("%s\n", sc);
}
