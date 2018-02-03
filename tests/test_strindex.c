#include <stdio.h>
#include "../strlindex.c"
#include "../strrindex.c"


#define MAXLINE     100


char pattern[] = "ould";
int readline(char line[], int max_line);


/* return grepped number */
int main()
{
    char line[MAXLINE];
    int lindex, rindex;
    
    while (readline(line, MAXLINE) > 0) {
        if ((lindex=strlindex(line, pattern)) >= 0)
            printf("strlindex: %d\n", lindex);
        if ((rindex=strrindex(line, pattern)) >= 0)
            printf("strrindex: %d\n", rindex);
    }
    return 0;
}


/* return int length of line */
int readline(char line[], int max_line)
{
    int c, i;
    i = 0;
    while (--max_line > 0 && (c=getchar()) != EOF && c != '\n')
        line[i++] = c;
    if (c == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return i;
}
