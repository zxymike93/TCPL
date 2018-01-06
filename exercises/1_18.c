#include <stdio.h>
#define MAXLINE 100

int readline(char s[]);
int rstrip(char s[], int len);

int main()
{
    int len, new_len;
    char line[MAXLINE];
    while ((len=readline(line)) > 0) {
        printf("before rstrip: %d\n", len);
        if ((new_len = rstrip(line, len)) > 0)
            printf("after rstrip: %d\n", new_len);
            printf("%s\n", line);        
    }
    return 0;
}

int readline(char s[])
{
    char c;
    int i = 0;
    while ((c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i] = c;
    return i;
}

int rstrip(char s[], int len)
{
    int i = len - 1;
    while (i > 0 && (s[i] == ' ' ||  s[i] == '\t'))
        s[i--] = (char) 0;
    return i+1;
}
