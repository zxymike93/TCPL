// // fold line longer than 80
// // 1. 长度大于80
// // 2. 本身就换行
// 
// #include <stdio.h>
// 
// #define OUT     0
// #define IN      1
// 
// void fold(char s[]);
// 
// int main()
// {
//     char line[1000];
// 
//     fold(line);
//     printf("%s", line);
//     return 0;
// }
// 
// void fold(char s[])
// {
//     int c, i, j;
//     int state = OUT;
// 
//     for (i = j = 0; (c=getchar()) != EOF; ++i, ++j) {
//         if (c == ' ' || c == '\t') {
//             if (j >= 10) {
//                 s[i] = '\n';
//                 ++i;
//                 j = 0;
//             }
//         }
//         else if (c == '\n') {
//             j = 0;
//         }
//         else {
//         }
//         s[i] = c;
//     }
// }


#include <stdio.h>

#define MAXCOL      10
#define TABINC      8

char line[MAXCOL];

int exptab(int pos);
int findblank(int pos);
int newpos(int pos);
void printl(int pos);

int main()
{
    int c, pos;

    pos = 0;
    while ((c=getchar()) != EOF) {
        line[pos] = c;
        if (c == '\t')
            pos = exptab(pos);
        else if (c == '\n') {
            printl(pos);
            pos = 0;
        }
        else if (++pos >= MAXCOL) {
            pos = findblank(pos);
            printl(pos);
            pos = newpos(pos);
        }
    }
}


// 把TAB换成空格
int exptab(int pos)
{
    line[pos] = ' ';
    for (++pos; pos < MAXCOL && pos%TABINC != 0; ++pos)
        line[pos] = ' ';
    if (pos < MAXCOL)
        return pos;
    else {
        printl(pos);
        return 0;
    }
}

// 向前寻找空格
// 如果没有空格，按最大长度折叠
// 如果有空格，按空格后面一个坐标折叠
int findblank(int pos)
{
    while (pos > 0 && line[pos] != ' ')
        --pos;
    if (pos == 0)
        return MAXCOL;
    else
        return pos+1;
}

// 旧的一行折叠过后
// 余下的部分拼到下一行
// 并且长度计算在内
int newpos(int pos)
{
    if (pos <= 0 || pos >= MAXCOL)
        return 0;
    else {
        int i, j;
        i = 0;
        for (j = pos; j < MAXCOL; ++i, ++j)
            line[i] = line[j];
        return i;
    }
}

// 把存储在序列中的字符输出
void printl(int pos)
{
    int i;
    for (i = 0; i < pos; ++i)
        putchar(line[i]);
    if (pos > 0)
        putchar('\n');
}
