#include <stdio.h>

#define MAXLINE 1000

int readline(char line[]);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = readline(line)) > 0) {
        if (len > 80)
            printf("%s", line);
    }
    return 0;
}

int readline(char line[])
{
    int i, c;

    i = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        line[i] = c;
        ++i;
    }
    return i;
}
