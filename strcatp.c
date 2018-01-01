#include <stdio.h>

void my_strcat(char *s, char *t);

int main()
{
    char s[] = "head";
    char c[] = {'a', 'b', 'c', 'd', 'e'};

    my_strcat(s, c);
    int i = 0;
    for ( ; i < 10; i++)
        printf("%c\n", s[i]);
    return 0;
}

void my_strcat(char *s, char *t)
{
    while (*s++)
        ;
    while ((*s++ = *t++))
        ;
}
