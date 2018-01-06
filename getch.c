#include <stdio.h>

#define BUFFSIZE 100

char buf[BUFFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

int ungetch(int c)
{
    if (bufp >= BUFFSIZE)
        printf("ungetch: 太多字符了\n");
    else
        buf[bufp++] = c;
}
