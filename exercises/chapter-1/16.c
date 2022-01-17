/* 打印出最长的一行 */

#include <stdio.h>

#define MAXLINE 1000

/* OUT: length of inputed line. */
int readline(char s[])
{
        // 如果不赋值, i 会 overflow
        int c, i = 0;

        while ((c = getchar()) != EOF && c != '\n')
                s[i++] = c;

        if (c == '\n')
                s[i++] = c;

        s[i] = '\0';
        printf("The length of this line is %d.\n", i);
        return i;
}

void copy(char to[], char from[])
{
        int i = 0;

        while ((to[i] = from[i]) != '\0')
                ++i;
}

int main()
{
        int len, max = 0;
        char line[MAXLINE];
        char longest[MAXLINE];

        while ((len = readline(line)) > 0) {
                if (len > max) {
                        max = len;
                        printf("The max length of your inputed lines is %d.\n", max);
                        copy(longest, line);
                }
        }

        if (max > 0)
                printf("The longest line.\n%s", longest);

        return 0;
}