#include <ctype.h>
#include <stdio.h>

#define BUFFSIZE 100

char BUF[BUFFSIZE];
int BUFP = 0;

int getch(void)
{
        return (BUFP > 0) ? BUF[--BUFP] : getchar();
}

void ungetch(int c)
{
        if (BUFP >= BUFFSIZE) {
                printf("ungetch: too many chars\n");
        } else {
                BUF[BUFP++] = c;
        }
}

int getfloat(float *pn)
{
        int c;
        int sign = 1;
        int i;

        c = getch();

        if (c == '+' || c == '-') {
                sign = (c == '-') ? -1 : 1;
                c = getch();
        }

        for (*pn = 0; isdigit(c); c = getch())
                *pn = 10 * *pn + (c - '0');

        if (c == '.')
                c = getch();

        for (i = 0; isdigit(c); c = getch()) {
                *pn = 10 * *pn + (c - '0');
                i++;
        }

        while (i > 0) {
                *pn = *pn / 10;
                i--;
        }

        *pn = *pn * sign;

        return c;
}

int main()
{
        float x = 0.0;
        int c;

        printf("Enter a float:");
        c = getfloat(&x);
        printf("float x: %f\n", x);
        printf("last character c: %d\n", c);

        return 0;
}