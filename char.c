#include <stdio.h>

main()
{
    int c;

    /*
        读一个字符;
        while (不是文本结束符)
            输出该字符;
            读下一个字符;
    */
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
}

