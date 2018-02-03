#include <stdio.h>
#include <ctype.h>

#include "readline.c"


#define MAXLINE 100


double atof(char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }
    /* 小数点后 */
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    return sign * val / power;
}

int atoi(char s[])
{
    double atof(char s[]);
    return (int) atof(s);
}


int main()
{
    double sum;
    // double sum, atof(char []);
    char line[MAXLINE];
    int readline(char line[], int max);

    sum = 0;
    while (readline(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
        printf("\t%g\n", sum += atoi(line));
    return 0;
}
