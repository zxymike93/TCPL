#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
#define STORAGE 500

int readline(char line[], int max)
{
        int len;
        char c;

        for (len = 0; (c = getchar()) != EOF;) {
                if (len > max) {
                        printf("READLINE: too long.\n");
                } else {
                        line[len] = c;
                        len++;
                        if (c == '\n') {
                                break;
                        }
                }
        }

        return len;
}

// 从 stdin 读取句子, 每句以 \n 结尾
// 并保存在参数 lines 中, 且最多不超过 max 行
int readlines(char *lines[], int maxline, char *store, int maxstore)
{
        int len, n;
        char line[MAX];
        char *tmp = store;
        char *endstore = store + maxstore;

        len = n = 0;
        while ((len = readline(line, MAX)) > 0) {
                // if (n > max || (tmp = malloc(len)) == NULL) {
                //         return -1;
                // } else {
                //         line[len-1] = '\0';
                //         strcpy(tmp, line);
                //         lines[n] = tmp;
                //         n++;
                // }
                if (n > maxline || tmp + len > endstore) {
                        return -1;
                } else {
                        line[len-1] = '\0';
                        strcpy(tmp, line);
                        lines[n] = tmp;
                        n++;
                        tmp += len;
                }

        }

        return n;
}

void writelines(char *lines[], int n)
{
        int i;
        for (i = 0; i < n; i++)
                printf("[%d] %s\n", i, lines[i]);
}

void swap(char *v[], int n, int m)
{
        char *tmp;

        tmp = v[n];
        v[n] = v[m];
        v[m] = tmp;
}

void sortlines(char *lines[], int left, int right)
{
        if (left >= right)
                return;
        
        swap(lines, left, (left + right) / 2);
        // 记录一个点 pivot, 该点就是 mid 排序后的正确下标
        int p = left;

        int i;
        for (i = left + 1; i <= right; i++) {
                if (strcmp(lines[i], lines[left]) < 0) {
                        p++;
                        swap(lines, p, i);
                }
        }
        swap(lines, left, p);

        sortlines(lines, left, p - 1);
        sortlines(lines, p + 1, right);
}

int main()
{
        char *lines[MAX];
        char addr[MAX];

        //int nlines = readlines(lines, MAX);
        int nlines = readlines(lines, MAX, addr, MAX);
        if (nlines >= 0) {
                sortlines(lines, 0, nlines-1);
                writelines(lines, nlines);
                return 0;
        } else {
                return 1;
        }

        // Tests
        // int test_readline();
        // test_readline();
        // int test_readlines();
        // test_readlines();
        // int test_sortlines();
        // test_sortlines();
}

int test_readline() {
        char s[100];
        printf("TEST READLINE: %d", readline(s, 100));
        return 0;
}

int test_readlines() {
        char *s[100];
        //printf("TEST READLINES: %d\n", readlines(s, 100));
        return 0;
}

int test_sortlines()
{
        char *s[] = {"10", "80", "30", "90", "40", "50", "70"};
        sortlines(s, 0, 6);

        int i;
        for (i = 0; i < 7; i++) {
                printf("TEST SORTLINES: %s\n", s[i]);
        }
        return 0;
}