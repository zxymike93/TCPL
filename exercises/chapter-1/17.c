/* 打印长度大于80的行 */

#include <stdio.h>

#define MAXLINE 1000

int readline(char line[])
{
        int i = 0, c;

        while ((c = getchar()) != EOF && c != '\n')
                line[i++] = c;

        return i;
}

int main()
{
        int len;
        char line[MAXLINE];

        while ((len = readline(line)) > 0) {
                if (len > 80)
                        printf("%s\n", line);
        }

        return 0;
}