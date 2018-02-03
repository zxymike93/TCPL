#include <ctype.h>


double atof(char s[])
{
    double val, power, scientific;
    int i, sign, notation, num;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = val * 10.0 + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = val * 10.0 + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        notation = (s[i] == '-') ? -1 : 1;
        if (s[i] == '-' || s[i] == '+')
            i++;
        for (num = 0; isdigit(s[i]); i++)
            num = num * 10 + (s[i] - '0');
        for (scientific = 1.0; num > 0; --num)
            scientific *= 10.0;
        if (notation < 0)
            return sign * val / power / scientific;
        else
            return sign * val / power * scientific;
    }
    return sign * val / power;
}
