// Imply strncpy, strncat, strncmp

#include <stdio.h>

void string_ncpy(char *cpy, char *src, int n)
{
        for (; n > 0 && *src != '\0'; n--) {
                *cpy++ = *src++;
        }

        // 如果src的长度小于n, 余下的都用null填充
        for (; n > 0; n--) {
                *cpy++ = '\0';
        }
}

void string_ncat(char *dest, char *src, int n)
{
        while (*dest != '\0') {
                dest++;
        }

        for (; n > 0 && *src != '\0'; n--)
                *dest++ = *src++;

        if (n == 0)
                *dest = '\0';
}

// return >0 if x > y, 0 if x = y, -1 if x < y
int string_ncmp(char *x, char *y, int n)
{
        for (; n > 0 && *x != '\0' && *y != '\0'; n--) {
                if (*x != *y)
                        break;

                x++;
                y++;
        }

        if (n == 0)
                return 0;

        return *x - *y;
}

int main()
{
        int n;
        char s[100];
        char *t = "chips";

        string_ncpy(s, t, 10);
        printf("strncpy: %s\n", s);

        string_ncat(s, t, 10);
        printf("strncat: %s\n", s);

        n = string_ncmp(s, t, 10);
        printf("strncmp: %d\n", n);
        n = string_ncmp("abc", "abd", 2);
        printf("strncmp: %d\n", n);
        n = string_ncmp("abc", "abd", 5);
        printf("strncmp: %d\n", n);


        return 0;
}