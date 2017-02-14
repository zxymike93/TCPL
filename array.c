#include <stdio.h>

/* 统计 数字、空白符、其他字符 的数量 */
main()
{
    int c, i, nwhite, nother;
    /* 声明数组 */
    int ndigit[10];

    nwhite = nother = 0;
    /* 给数组中的每个元素赋值为 0 */
    for (i = 0; i < 10; ++i) {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
	/* '0' 是字符常量, ASCII码 48 */
        if (c >= '0' && c <= '9') {
            ++ndigit[c-'0'];
        }
	else if (c == ' ' || c == '\n' || c == '\t') {
            ++nwhite;
	}
	else {
            ++nother;
        }
    }

    printf("digits =");
    for (i = 0; i < 10; ++i) {
        printf(" %d", ndigit[i]);
    }
    printf(", white space = %d, other = %d\n",
        nwhite, nother);
}

