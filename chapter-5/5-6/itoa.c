#include <string.h>
#include <stdio.h>

void reverse(char *s)
{
        char c;
        char *t;

        for (t = s + (strlen(s) - 1); s < t; s++, t--) {
                c = *s;
                *s = *t;
                *t = c;
        }
}

void itoa(int n, char *s)
{
        int i = 0, sign = n;
        char *bs = s;

        if (sign < 0)
                n = -n;

        do {
                *s = n % 10 + '0';
                s++;
        } while ((n /= 10) > 0);

        if (sign < 0) {
                *s = '-';
                s++;
        }

        *s = '\0';

        reverse(bs);
}

int main()
{
        int x = -64;
        int y = 100;
        char s[10];
        char t[10];

        itoa(x, s);
        itoa(y, t);

        printf("x: %s\n", s);
        printf("t: %s\n", t);
}