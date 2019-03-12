#include <stdio.h>

/*
    统计空格、制表、换行符的程序
*/

int main()
{
    int c, ns, nt, nl;
    ns = nt = nl = 0;
    while ((c = getchar()) != EOF) { 
        if (c == ' ')
            ++ns;
        else if (c == '\t')
            ++nt;
        else if (c == '\n')
            ++nl;
    }
    printf("The number of spaces is %d\n", ns);
    printf("The number of tables is %d\n", nt);
    printf("The number of lines is %d\n", nl);
}

