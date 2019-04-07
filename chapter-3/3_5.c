#include <stdio.h>
#include "../reverse.c"
#define abs(x)  ((x) < 0 ? -(x) : (x))

void itob(int n, char s[], int b)
{
    int i, j, sign;
    i = 0;
    sign = n;

    do {
        j = abs(n % b);
        if (j < 10)
            s[i++] = j + '0';
        else
            s[i++] = j - 10 + 'a';
        printf("s[%d] = %c\n", i, s[i-1]);
    } while ((n /= b) != 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';

    // printf("%s\n", s);
    reverse(s);
}
