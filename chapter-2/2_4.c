#include <stdio.h>

// 将 s 中包含了 c 中字母的字母去除.
// 不返回值，修改原 s
void squeeze(char s[], char c[])
{
        int i, j, k;

        for (i = j = 0; s[i] != '\0'; i++) {
                // Try to match s[i] with every char in string c.
                for (k = 0; c[k] != '\0' && s[i] != c[k]; k++)
                        ;

                if (c[k] == '\0') {
                        s[j] = s[i];
                        j++;
                }
        }

        // 截掉后面的字符
        s[j] = '\0';
}

int main()
{
        char s[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
        char c[] = "helo";

        squeeze(s, c);
        printf("%s\n", s);
        return 0;
}