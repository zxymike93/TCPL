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

int day_of_year(int d, int m, int y)
{
        int leap = is_leap(y);
        int *pm = daytab[leap];

        while (--m) {
                d += *pm;
                pm++;
        }

        return d;
}

void date_of_year(int d, int y, int *day, int *month)
{
        int leap = is_leap(y);
        int *pm = daytab[leap];

        while (d > *pm) {
                d -= *pm;
                pm++;
        }

        *month = pm - *(daytab + leap) ;
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
}