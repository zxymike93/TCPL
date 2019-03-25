#include <stdio.h>
#include "../reverse.c"
#include "../readline.c"
#define MAXLINE 100

int main()
{
    char line[MAXLINE];
    while (readline(line, MAXLINE) > 0) {
        reverse(line);
        printf("%s", line);
    }
}
