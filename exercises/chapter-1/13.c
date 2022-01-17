#include <stdio.h>

#define MAXHIST 15
#define MAXWORD 11
#define IN 1
#define OUT 0

int main()
{
        int c, i, nc, state;
        int len;
        int maxvalue;  /*直方图中的最大值*/
        int ovflow;
        int wl[MAXWORD];  /*存储单词长度的数组，词长: 次数*/

        state = OUT;
        nc = 0;
        ovflow = 0;

        for (i = 0; i <= MAXWORD; ++i)
                wl[i] = 0;

        /* 统计不同长度单词的数量 */
        while ((c=getchar()) != EOF) {
                if (c == ' ' || c == '\t' || c == '\n') {
                        state = OUT;
                        if (nc > 0) {
                                if (nc < MAXWORD)
                                        ++wl[nc];
                                else
                                        ++ovflow;
                        }
                        nc = 0;
                } else if (state == OUT) {
                        state = IN;
                        nc = 1;
                } else {
                        ++nc;
                }
        }

        /* 确定直方图最大数值 */
        maxvalue = 0;
        for (i = 0; i <= MAXWORD; ++i) {
                if (wl[i] > maxvalue)
                        maxvalue = wl[i];
        }

        /* 画直方图 */
        for (i = 0; i <= MAXWORD; ++i) {
                printf("%d - %d: ", i, wl[i]);
                if (wl[i] > 0) {
                        if ((len = wl[i] * MAXHIST / maxvalue) <= 1)
                                len = 1;
                } else {
                        len = 0;
                }

                while (len > 0) {
                        putchar('*');
                        --len;
                }

                putchar('\n');
        }

        printf("There %d words >= %d", ovflow, MAXWORD);
}
