// strend - if there's a t at the end of s, return 1; otherwise, return 0.

#include <stdio.h>

int strend(char *s, char *t)
{
        char *tmp;
        tmp = t;

        while (*s++)
                ;
        
        while (*tmp++)
                ;
        
        while (tmp > t) {
                if (*tmp != *s) {
                        return 0;
                } else {
                        tmp--;
                        s--;
                }
        }

        return 1;
}

int main()
{
        char *s = "string";
        char *t = "ing";
        
        printf("%d\n", strend(s, t));
        return 1;
}