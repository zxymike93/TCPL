/* 统计输入的字符数 */

#include <stdio.h>
#include <ctype.h>

#define MAX 128

int main()
{
        int c, i;
        int charlist[MAX];

        for (i = 0; i < MAX; ++i)
                charlist[i] = 0;

        while ((c = getchar()) != EOF) {
                if (c < MAX)
                        ++charlist[c];
        }

        for (i = 0; i < MAX; ++i) {
                if (isprint(i))
                        printf("%5d.[%c] - %5d: ", i, i, charlist[i]);

                while (charlist[i] > 0) {
                        printf("*");
                        --charlist[i];
                }

                printf("\n");
        }
}