// int to char

#include "reverse.c"

void itoa(int n, char s[])
{
    int i, sign;
    
    i = 0;
    if ((sign = n) < 0)
        n = -n;
    // sign = (n < 0) ? -1 : 1;
    // n = (n < 0) ? -n : n;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';

    reverse(s);
}
