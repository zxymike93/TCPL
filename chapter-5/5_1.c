#include <ctype.h>
#include <stdio.h>

#define BUFFSIZE 100

char buf[BUFFSIZE];
int bufp = 0;

int getch(void)
{
        return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
        if (bufp >= BUFFSIZE)
                printf("ungetch: too many chars\n");
        else
                buf[bufp++] = c;
}

// 将输入中的下一个值赋给 *pn
int getint(int *pn)
{
        int c, sign;

        while (isspace(c = getch()))
                ;

        if (c != EOF && c != '+' && c != '-' && !isdigit(c)) {
                ungetch(c);
                return 0;
        }

        sign = (c == '-') ? -1 : 1;
        if (c == '+' || c == '-') {
                c = getch();
                if (!isdigit(c) && c != EOF) {
                        *pn = 0;
                        ungetch(c);
                        return c;
                }
        }

        for (*pn = 0; isdigit(c); c = getch())
                *pn = 10 * *pn + (c - '0');

        // 改变了主调函数中x的值
        *pn *= sign;
        if (c != EOF)
                ungetch(c);

        // 返回最后一个字符的值
        return c;
}

int main()
{
        int x = 0;
        int c;

        c = getint(&x);
        printf("x = %d\n", x);
        printf("c = %d\n", c);
        return 0;
}