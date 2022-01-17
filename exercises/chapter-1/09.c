/* 将输入中的多个空格输出为一个空格 */

#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
        int c, state;
        state = IN;

        while ((c = getchar()) != EOF) {
                if ( c != ' ') {
                        state = IN;
                        putchar(c);
                } else if (c == ' ' && state == IN) {
                        putchar(c);
                        state = OUT;
                }
        }

        return 0;
}