/* 
 * 将输入中的 \t \b \
 * 输出为 \\t \\b \\
 */

#include <stdio.h>

int main()
{
        char c;

        while ((c = getchar()) != EOF) {
                if (c == '\t')
                        printf("\\t");
                else if (c == '\n')
                        printf("\\n");
                else if (c == '\\')
                        printf("\\\\");
                else
                        putchar(c);
        }
}