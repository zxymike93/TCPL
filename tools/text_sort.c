#include <stdio.h>
#include <stdlib.h>
// char *alloc(int);

// 输入: 字符指针,指向文本行首地址
// 输出: 行长
int readline(char s[])
{
        int c, i = 0;

        while ((c = getchar()) != EOF && c != '\n')
                s[i++] = c;

        if (c == '\n')
                s[i++] = c;

        s[i] = '\0';
        return i;
}

void copystring(char *dest, char *src)
{
        while (*src != '\0') {
                *dest = *src;
                dest++;
                src++;
        }
}

// 输出: 文本的总行数
int readlines(char *lines[])
{
        int i = 0, len;
        char line[100];
        char *s;

        while ((len = readline(line)) > 0) {
                copystring(s, line);
                lines[i] = s;
                s = malloc(len);
                printf("strcp~s: %s\n", s);
                printf("lines: 1%s 2%s\n", lines[0], lines[1]);
                i++;
        }

        return i;
}

void writelines(char *lines[], int n)
{
        while (n > 0) {
                printf("%s\n", *lines);
                n--;
                lines++;
        }
}

int main()
{
        char *text[100];

        int linum = readlines(text);
        if (linum > 0) {
                // sortlines(text, linum);
                writelines(text, linum);
        } else {
                printf("Nothing was input.\n");
        }

        return 1;
}