#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char *pline[MAX];

int read_line(char *line, int maxline)
{
        int c, len = 0;
        while (len < maxline) {
                c = getchar();
                if (c == EOF) {
                        return len;
                } else if (c == '\n') {
                        *line = '\0';
                        len++;
                        return len;
                } else {
                        *line = c;
                        line++;
                        len++;
                }
        }

        return len;
}

//char *alloc(int);

int read_lines(char *p[], int max)
{
        int len, n;
        char *tmp, line[MAX];

        while ((len = read_line(line, max)) > 0) {
                if (n > max || (tmp = malloc(len)) == NULL) {
                        return -1;
                } else {
                        line[len - 1] = '\0';
                        strcpy(tmp, line);
                        p[n] = tmp;
                        n++;
                }
        }

        return n;
}

void write_lines(char *p[], int n)
{
        while (n > 0) {
                printf("%s\n", *p);
                n--;
                p++;
        }
}

void swap(void *v[], int i, int j)
{
    void *tmp;

    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

// quick_sort(序列, 第一个元素下标, 最后一个元素下标, 指向排序算法的指针)
void quick_sort(void *p[], int start, int end, int (*cmp)(void *, void *))
{
        int i, pivot;

        if (start >= end)
                return;

        swap(p, start, (start + end) / 2);
        pivot = start;

        for (i = start + 1; i <= end; i++) {
                if ((*cmp)(p[i], p[start]) < 0) {
                        pivot++;
                        swap(p, pivot, i);
                }
        }

        swap(p, start, pivot);
        quick_sort(p, start, pivot - 1, cmp);
        quick_sort(p, pivot + 1, end, cmp);
}

int main(int argc, char *argv[])
{
        int opt_n = 0;
        int nlines = 0;

        if (argc > 1 && strcmp(argv[1], "-n") == 0)
                opt_n = 1;

        if ((nlines = read_lines(pline, MAX)) >= 0) {
                // 两个类型转换
                quick_sort((void **)pline, 0, nlines - 1,
                      (int (*)(void *, void *))strcmp);
                write_lines(pline, nlines);
                return 0;
        } else {
                printf("Input too big to sort.\n");
                return 1;
        }
}