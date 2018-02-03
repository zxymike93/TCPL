#include <stdio.h>

/* declair a function */
void squeeze(char s[], char c);


int main()
{
    char s[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    squeeze(s, 'c');

    int i;
    for (i = 0; i < 10; ++i)
        printf("%c\n", s[i]);

    return 0;
}


void squeeze(char s[], char c)
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; ++i) {
        if (s[i] != 'c') {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}
