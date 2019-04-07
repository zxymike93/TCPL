// int to char
// signed int min: -2147483648	 max: 2147483647

#include "../reverse.c"

#define abs(x)  ((x) < 0 ? -(x) : (x))

void itoa(int n, char s[])
{
    int i=0, sign=n;
    
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';

    reverse(s);
}
