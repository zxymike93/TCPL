// strcat(s, t) - concatenate t at the end of s

#include <stdio.h>
#include <string.h>

void str_append(char *s, char *t)
{
        while (*s != '\0') {
                s++;
        }

        if (*s == '\0') {
                *s = *t;
                s++;
                t++;
        }

        while (*t != '\0') {
                *s = *t;
                s++;
                t++;
        }

        *s = '\0';
}

int main()
{
        // 需要足够大的空间
        char dest[100] = "string ";
        char *src = "functions are not features in C.";

        // strcat(head, tail);
        str_append(dest, src);
        printf("%s\n", dest);

        return 0;
}