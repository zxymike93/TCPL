#include <stdio.h>
#include <string.h>

#define MAX 100

int getaline(char *line, int maxline)
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

int getlines(char *lines[], int maxlines)
{
        int len, i;
        char *s, line[MAX];

        len = i = 0;
        while (i < maxlines) {
                len = getaline(line, MAX);
                if (len > 0) {
                        strcpy(s, line);
                        lines[i] = s;
                        i++;
                        s += len;
                } else if (len == 0) {
                        return i;
                } else {
                        return -1;
                }
        }

        return i;
}

void printlines(char *lines[], int n)
{
        int i;
        for (i = 0; i < n; i++) {
                printf("[%d] %s\n", i, lines[i]);
        }
}

int getpart(int x, int y)
{
        return (x + y) / 2;
}

// char *create_empty_lines(char *l, int max)
// {
//         int i;
//         for (i = 0; i < max; i++)
//                 l[i] = "";
// }

void sortlines(char *lines[], int start, int end)
{
        if (start >= end)
                return;

        char *smaller[MAX];
        int ps;
        for (ps = 0; ps < MAX; ps++)
                smaller[ps] = "";

        char *larger[MAX];
        int pl;
        for (pl = 0; pl < MAX; pl++)
                larger[pl] = "";

        int mid = (start + end) / 2;
        char *partition = lines[mid];
        int i, r;
        for (ps = pl = 0, i = start; i <= end; i++) {
                r = strcmp(lines[i], lines[mid]);
                if (r < 0) {
                        smaller[ps] = lines[i];
                        ps++;
                } else if (r > 0) {
                        larger[pl] = lines[i];
                        pl++;
                } else {
                        ;
                }
        }

        for (i = start, ps = 0; smaller[ps] != ""; ps++, i++)
                lines[i] = smaller[ps];

        lines[i] = partition;
        int p = i;
        i++;

for (pl = 0; larger[pl] != ""; pl++, i++)
                lines[i] = larger[pl];

        printf("start end: %d %d\n", start, end);
        sortlines(lines, start, p - 1);
        sortlines(lines, p, end);
}

int main()
{
        // char *lines[MAX];

        // int nlines = getlines(lines, MAX);
        // if (nlines > 0) {
        //         // sortlines(lines, nlines);
        //         printlines(lines, nlines);
        //         return 1;
        // } else {
        //         return -1;
        // }
        int test_sort();
        test_sort();
        return 0;
}

int test_sort()
{
        char *s[] = {"10", "80", "30", "90", "40", "50", "70"};
        sortlines(s, 0, 6);

        int i;
        for (i = 0; i < 7; i++) {
                printf("%s\n", s[i]);
        }
        return 0;
}