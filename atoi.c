#include <ctype.h>


/* 转换字符到 int */
int atoi(char s[])
{
    int i, n;
    n = 0;

    /* 每向右一位，相当于增加一个十进位 */
    for (i = 0; s[i] >= '0' && s[i] <= '9'; i++) {
        n = 10 * n + (s[i] - '0');
    }
    return n;
}

/* 转换字符到 int 
 * 处理空格和正负号 */
int atoi2(char s[])
{
    /* int 声明默认 0 */
    int i, n, sign;
    n = 0;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for (n = 0; s[i] >= '0' && s[i] <= '9'; i++)
        n = 10 * n + (s[i] - '0');
    return n;
}

int main() {}
