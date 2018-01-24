#include <stdio.h>
#include "../exercises/3_5.c"

int main()
{
    int a = -100290;
    int b = 2980;
    int c = -2147483648;

    char sa[100];
    char sb[100];
    char sc[100];


    // itob(a, sa, 2);
    // printf("%s\n", sa);
    itob(b, sb, 8);
    printf("%s\n", sb);
    // itob(c, sc, 16);
    // printf("%s\n", sc);
}
