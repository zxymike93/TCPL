#include <stdio.h>

main()
{
    int c, nl;

    nl = 0;
    while ((c = getchar()) != EOF) {
        /*
            要把 getchar() 存在变量 c 中
            如果 if (getchar() != '\n')
            会循环调用 getchar()
       */
        if (c != '\n')
            ++nl;
    }
    printf("%d\n", nl);
}

