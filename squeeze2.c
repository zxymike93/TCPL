#include <stdio.h>

/* declair a function */
void squeeze(char s[], char c[]);


int main()
{
    char s[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    char c[4] = "helo";
    squeeze(s, c);

    int i;
    for (i = 0; s[i] != '\0'; ++i)
        printf("%c\n", s[i]);

    return 0;
}


void squeeze(char s[], char c[])
{
    int i, j, k;

    for (i = j = 0; s[i] != '\0'; i++) {
        for (k = 0; c[k] != '\0' && s[i] != c[k]; k++)
            ;
        if (c[k] == '\0')
            s[j++] = s[i];
    }
    s[j] = '\0';
}
