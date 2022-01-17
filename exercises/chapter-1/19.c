#include <stdio.h>

#define MAXLINE 100

int readline(char s[], int lim)
{
        int c, i = 0;

        while (i < lim - 1 && (c = getchar()) != EOF && c != '\n')
                s[i++] = c;

        if (c == '\n')
                s[i++] = c;

        s[i] = '\0';
        return i;
}

void reverse(char s[])
{
        int i, j;
        char temp;
        i = j = 0;

        while (s[i] != '\0')
                ++i;

        --i;
        if (s[i] == '\n')
                --i;

        while (j < i) {
                temp = s[j];
                s[j] = s[i];
                s[i] = temp;
                --i;
                ++j;
        }
}

int main()
{
        char line[MAXLINE];

        while (readline(line, MAXLINE) > 0) {
            reverse(line);
            printf("%s", line);
        }
}