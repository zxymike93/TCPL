/* detab */

#include <stdlib.h>
#include <stdio.h>

#define MAX 100

/* settab: 设置制表符停止位
 * given: argc, argv
 * expect: 制表符停止位
 */
int settab(int argc, char *argv[])
{
        int n;

        if (argc == 1)
                n = 4;
        else
                n = atoi(argv[1]);
        
        return n;
}

/* detab: 每隔 n 列就有一个制表符停止位，将输入中的 \t 转化为空格符
 * given: "Hello\tWorld", out, 4
 * expect: NULL
 * side effect: out 将指向 detab 处理后的字符串
 */
void detab(char *in, char *out, int n)
{
        int pos, space;

        for (pos = space = 0; *in != '\0'; in++) {
                if (*in == '\t') {
                        space = n - pos % n;
                        while (space > 0) {
                                *out = '*';
                                out++;
                                pos++;
                                space--;
                        }
                } else {
                        *out = *in;
                        out++;
                        pos++;
                }
        }
}

int main(int argc, char *argv[])
{
        // test settab
        int n = settab(argc, argv);
        printf("settab: %d\n", n);

        // test detab
        char *s = "Hello\tWorld";
        char t[MAX];

        detab(s, t, n);
        printf("From: %s\nTo: %s\n", s, t);

        return 0;
}