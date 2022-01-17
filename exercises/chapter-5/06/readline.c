#include <stdio.h>

void readline(char *s, int n)
{
        int c;

        for (; n - 1 > 0 && (c = getchar()) != EOF; n--) {
                *s = c;
                s++;

                if (c == '\n')
                        break;
        }

        *s = '\0';
}

int main()
{
        char s[100];

        readline(s, 100);
        printf("Read a line: %s\n", s);

        return 0;
}