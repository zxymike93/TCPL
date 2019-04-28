#include <stdio.h>

static char daytab[2][13] = {
        // 平年
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        // 闰年
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int is_leap(int y)
{
        return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

// day_of_year(1, 3, 1988)
// 60
int day_of_year(int d, int m, int y)
{
        int i;
        for (i = 1; i < m; i++) {
                d += daytab[is_leap(y)][i];
        }

        return d;
}

// date_of_year(60, 1988, &day, &month)
void date_of_year(int d, int y, int *day, int *month)
{
        int i, leap;
        leap = is_leap(y);

        for (i = 1; d > daytab[leap][i]; i++) {
                d -= daytab[leap][i];
        }

        *month = i;
        *day = d;
}

int main()
{
        int d = day_of_year(1, 3, 1988);
        printf("March 1st is the %dth day of 1998.\n", d);

        int day;
        int month;
        date_of_year(60, 1988, &day, &month);
        printf("The 60th day of 1998 is %d %dth.\n", month, day);
}