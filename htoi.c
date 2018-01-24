// heximal to decimal

#include <stdio.h>

#define VALID   1
#define INVALID 0

int htoi(char s[]) {
    int i, n, h;
    int state;
    i = n = h = 0;
    if (s[i] == '0') {
        ++i;
        if (s[i] == 'x' || s[i] == 'X')
            ++i;
    }
    state = VALID;
    for ( ; state == VALID; ++i) {
        if (s[i] >= '0' && s[i] <= '9')
            h = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            h = s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            h = s[i] - 'A' + 10;
        else
            state = INVALID;
        if (state == VALID)
            n = n * 16 + h;
    }
    printf("%d\n", n);
    return n;
}

