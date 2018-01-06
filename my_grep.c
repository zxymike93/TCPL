#include <stdio.h>

#define MAXLINE 1000;

char pattern[] = "ould";

int getline(char line[], int max_line);
int strindex(char search[], char pattern[]);


int readline(char line[], int max_line)
{
    int c;
    /* return int length of line */
    while (--max_line > 0 && (c=getchar() != EOF) && c != '\n') {
        line[i++] = c;
    }
    if (c == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return i;
}

int strindex(char s[], char p[])
{
    /* return first index of pattern in searched line */
    int i, j, k;
    for (i = 0; search[i] != '\0'; i++) {
        for (j=i, k=0; s[j] == p[k]; j++, k++)
            ;
        if (p[k] == '\0' && k > 0)
            return i;  /* j is last index */
    }
    return -1;
}


int main()
{
    /* return grepped number */
    char line[MAXLINE];
    int found;
    
    while (getline(line, MAXLINE) > 0) {
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    }
    return found;
}
