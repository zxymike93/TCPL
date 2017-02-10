#include <stdio.h>

/*
    统计空格、制表、换行符的程序
*/

main()
{
    int c, ns, nt, nl;

    ns = 0;
    nt = 0;
    nl = 0;
    /*
        记住用 {}
        否则只有第一个 if 语句会被包含在
        while-loop 里面
    */
    while ((c = getchar()) != EOF) { 
        if (c == ' ')
            ++ns;
        if (c == '\t')
            ++nt;
        if (c == '\n')
            ++nl;
    }
    printf("The number of spaces is %d\n", ns);
    printf("The number of tables is %d\n", nt);
    printf("The number of lines is %d\n", nl);
}

