#include <ctype.h>
#include <stdio.h>

// 将字符串形式的整数转化为整型
int atoi(char *s)
{
        int n;

        for (n = 0; *s >= '0' && *s <= '9'; s++) {
                n = 10 * n + (*s - '0');
        }

        return n;
}

int signed_atoi(char *s)
{
        int n, sign = 1;

        for (; isspace(*s); s++)
                ;

        sign = (*s == '-') ? -1 : 1;
        if (*s == '-' || *s == '+')
                s++;

        for (n = 0; *s >= '0' && *s <= '9'; s++)
                n = 10 * n + (*s - '0');

        return sign * n;
}

int main()
{
        int x;
        char *s1 = "64";
        char *s2 = "-64";

        printf("atoi: %d\n", atoi(s1));
        printf("signed_atoi: %d\n", signed_atoi(s2));

        return 0;
}