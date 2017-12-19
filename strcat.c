#include <stdio.h>

void my_strcat(char head[], char tail[]);
int read_line(char s[]);


int main()
{
    char s[100];
    char c[100] = {'a', 'b', 'c', 'd', 'e'};

    read_line(s);
    my_strcat(s, c);
    int i;
    for (i = 0; i < 100; ++i)
        printf("%c", s[i]);
    return 0;
}


int read_line(char s[])
{
    int c, i;
    for (i = 0; i < 100 && (c=getchar()) != EOF; ++i)
        s[i] = c;
    s[i] = '\0';
    return 0;
}


void my_strcat(char s[], char t[])
{
    int i, j;

    i = j = 0;
    while (s[i] != '\0')
        i++;
    while ((s[i++] = t[j++]) != '\0')
        ;
}
