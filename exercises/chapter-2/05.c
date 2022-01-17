#include <stdio.h>

int any(char s1[], char s2[])
{
        int i, j;

        for (j = 0; s2[j] != '\0'; ++j) {
                for (i = 0; s1[i] != '\0'; ++i) {
                        if (s1[i] == s2[j]) {
                                return i;
                        }
                }
        }

        return -1;
}

int main()
{
        char s1[] = "abcdefg";
        char s2[] = "helo";

        printf("%d\n", any(s1, s2));
}