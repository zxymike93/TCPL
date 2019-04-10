#include <stdio.h>
#include <string.h>

int length(char *str)
{
        int len;

        for (len = 0; *str != '\0'; str++, len++)
                ;
        
        return len;
}

void reverse(char *s)
{
        char *t;

        for (t = s + (length(s) - 1); s < t; s++, t--) {
                char c = *s;
                *s = *t;
                *t = c;
        }
}

int main()
{
        // Don't use char *
        // that's constant
        char s[] = "reverse";

        reverse(s);
        printf("%s\n", s);

        return 0;
}