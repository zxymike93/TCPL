#include <stdio.h>

#define MAXLINE 1000

int readline(char line[]);
void copy(char to[], char from[]);

int main()
{
    int len, max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = readline(line)) > 0) {
        if (len > max) {
            max = len;
            printf("max is %d\n", max);
            copy(longest, line);
        }
    }
    if (max > 0)
        printf("%s", longest);
    return 0;
}

/* 接收一个字符数组
 * 返回它的长度
 */
int readline(char s[])
{
    int c, i;
    // 如果不赋值, i 会 overflow
    i = 0;

    while ((c=getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    printf("i is %d\n", i);
    return i;
}

void copy(char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0')
        ++i;
}
