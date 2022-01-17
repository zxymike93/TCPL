#include <stdio.h>

#define MAXLINE     100

char pattern[] = "ould";
int readline(char line[], int max_line);
int strindex(char search[], char pattern[]);
int len(char line[]);


/* return grepped number */
int main()
{
    char line[MAXLINE];
    int found = 0;
    
    while (readline(line, MAXLINE) > 0) {
        printf("strindex %d\n", strindex(line, pattern));
        printf("len %d\n", len(pattern));
        if (strindex(line, pattern) >= len(pattern)-1) {
            printf("%s", line);
            found++;
        }
    }
    printf("grep: %d\n", found);
    return found;
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

/* return first index of pattern in searched line */
int strindex(char s[], char p[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; p[k]!='\0' && s[j]==p[k]; j++, k++)
            ;
        if (p[k] == '\0' && k > 0)
            return --j;
    }
    return -1;
}

int len(char s[])
{
    int i;

    i = 0;
    while (s[i++] != '\0')
        ;
    // not include '\0'
    return --i;
}
