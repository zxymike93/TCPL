#include <stdio.h>

int i = 0;
int j;

int main()
{
    if (i < j)
        printf("%d is greater than %d\n", j, i);
    else if (i > j)
        printf("%d is greater than %d\n", i, j);
    else
        printf("%d is equal to %d\n", i, j);
}
