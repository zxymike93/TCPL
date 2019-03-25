#include <stdio.h>
#define MAXLINE 100

int readline(char s[])
{
        char c;
        int i = 0;

        while ((c = getchar()) != EOF && c != '\n')
                s[i++] = c;

        if (c == '\n')
                s[i] = c;

        return i;
}

/* Strip spaces on the right */
int rstrip(char s[], int len)
{
        int i = len - 1;

        while (i > 0 && (s[i] == ' ' ||  s[i] == '\t'))
                s[i--] = '\0';

        return i + 1;
}

int main()
{
        int len, new_len;
        char line[MAXLINE];

        while ((len = readline(line)) > 0) {
                if ((new_len = rstrip(line, len)) > 0)
                        printf("%s\n", line);
        }

        return 0;
}