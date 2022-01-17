// detab
// 每隔 TAB 行就会有一个 tab 终止位
// 确保 tab 不是硬空格
// 比如说，TAB = 4
// abc\t 的长度是 4
// a\t 的长度也是4
// \t 的长度也是4

#include <stdio.h>

#define TAB 4

int main()
{
        int c, nblank, pos;

        nblank = 0;
        // 光标位置，比字符数多1
        pos = 1;

        while ((c = getchar()) != EOF) {
                if (c == '\t') {
                        // smart detab
                        nblank = TAB - ((pos - 1) % TAB);
                        while (nblank > 0) {
                                // replace "space" with _
                                putchar('_');
                                ++pos;
                                --nblank;
                        }
                } else if (c == '\n') {
                        // 换行、重置光标位置
                        putchar(c);
                        pos = 1; 
                } else {
                        // 输出、移动光标
                        putchar(c);
                        ++pos;
                }
        }

        return 0;
}
