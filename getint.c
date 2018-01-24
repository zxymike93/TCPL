#include <ctype.h>
#include "getch.c"

int getint(int *pn)
{
    int c, sign;
    // skip space
    while (isspace(c=getch()))
        ;
    // starts with not number
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    // positive or negative
    sign = (c == '-') ? -1 : 1;
    if (c == '-' || c == '+')
        c = getch();
    // digits
    for (*pn = 0; isdigit(c); c = getch())
        *pn = *pn * 10 + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}
