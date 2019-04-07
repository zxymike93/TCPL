#include "../reverse.c"

#define abs(x)  ((x) < 0 ? -(x) : (x))

void itoa(int n, char s[], int min)
{
    int i=0, sign=n;
    
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    while (i < min)
        s[i++] = ' ';
    s[i] = '\0';

    reverse(s);
}
