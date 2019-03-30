#include <stdio.h>

// delete all characters, that match one in c, of s.
void squeeze(char s[], char c[]);

int main()
{
    char s[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    char c[] = "helo";

    squeeze(s, c);
    printf("%s\n", s);
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
