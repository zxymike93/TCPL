#include <stdio.h>

#define IN 1
#define OUT 0


main()
{
    int c, state;
    state = IN;

    while ((c = getchar()) != EOF) {
        if ( c != ' ') {
            state = IN;
            putchar(c);
        }
        else if (c == ' ' && state == IN) {
            putchar(c);
            state = OUT;
        }
        else if (state == OUT) {
            ;
        }
    }
    return 0;
}

