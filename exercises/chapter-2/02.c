/* 在不使用 && || 的情况下实现下列 for 循环
 * int str_len(char s[], int lim)
 * {
 *      int i, c;
 * 
 *      for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
 *         s[i] = c;
 * 
 *      return i + 1;
 * }
 */

#include <stdio.h>

#define YES 1
#define NO 0

int main()
{
        int i, c;
        int len = 0;
        int state = YES;
        int lim = 10;
        char s[lim];

        for (i = 0; state == YES; ++i) {
                c = getchar();

                if (c == EOF) {
                        state = NO;
                } else if (c == '\n') {
                        state = NO;
                } else if (i > lim - 1) {
                        state = NO;
                } else {
                        s[i] = c;
                }

                if (state == NO) {
                        len = i;
                        printf("%d\n", len);
                        printf("%s\n", s);
                        return len;
                }
        }

        return 0;
}