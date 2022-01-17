/* 以每行一个单词的格式, 拆分一句话 */

#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
        char c;
        int state;

        while ((c = getchar()) != EOF) {
                if (c != ' ' && c != '\t' && c != '\n') {
                        state = IN;
                        putchar(c);
                } else if (state == IN) {
                        state = OUT;
                        putchar('\n');
                }
        }
}