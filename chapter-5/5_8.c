#include <stdio.h>

static int daytab[2][12] = {
        // 平年
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        // 闰年
        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
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
        int leap = is_leap(y);

        if (m < 0 || m > 11)
                return -1;

        if (d < 1 || d > daytab[leap][m - 1])
                return -1;

        for (i = 0; i < m - 1; i++)
                d += daytab[leap][i];

        return d;
}

// date_of_year(60, 1988, &day, &month)
void date_of_year(int d, int y, int *day, int *month)
{
        int i, leap, sumday;

        leap = is_leap(y);

        for (i = 0, sumday = 0; i < 12; i++)
                sumday += daytab[leap][i];

        if (y < 1) {
                *day = -1;
                *month = -1;
                return;
        }

        if (d < 1 || d > sumday) {
                *day = -1;
                *month = -1;
                return;
        }

        for (i = 0; d > daytab[leap][i]; i++)
                d -= daytab[leap][i];

        *month = i;
        *day = d;
        return;
}

int main()
{
        int d = day_of_year(1, 3, 1988);
        printf("March 1st is the %dth day of 1998.\n", d);

        int day, month;
        date_of_year(60, 1988, &day, &month);
        printf("The 60th day of 1998 is %d %dth.\n", month, day);

        // error test
        int errd = day_of_year(29, 2, 1993);
        printf("errd: %d\n", errd);

        int errday, errmonth;
        date_of_year(366, 1993, &errday, &errmonth);
        printf("errday: %d, errmonth: %d\n", errday, errmonth);
}