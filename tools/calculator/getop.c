#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "calc.h"

// get next num / op from stack
int getop(char s[])
{
    int i, c;
    i = 0;

    // space
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    // math funcs
    if (islower(c)) {
        while (isalpha(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);
        if (strlen(s) > 1)
            return NAME;
        else
            return c;
    }
    // not number
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    // negative
    if (c == '-') {
        if (isdigit((c = getch())) || c == '.')
            s[++i] = c;
        else {
            if (c != EOF)
                ungetch(c);
            return '-';
        }
    }
    // positive
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    if (c == '.') {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}
