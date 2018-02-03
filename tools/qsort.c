#include <stdio.h>
#include "swap.c"

void qsort(int v[], int left, int right)
{
    int i, mark;
    void swap_3(int v[], int i, int j);

    if (left >= right)
        return ;
    swap_3(v, left, (left+right)/2);
    mark = left;
    for (i = left+1; i <= right; i++)
        if (v[i] < v[left])
            swap_3(v, ++mark, i);
            // swap_3(v, mark++, i);
    swap_3(v, left, mark);
    qsort(v, left, mark-1);
    qsort(v, mark+1, right);
}

int main()
{
    int i;
    int v[] = {3, 4, 6, 1, 12, 2, 5, 0, 2, 13, 15, 55, 22};

    qsort(v, v[0], v[12]);
    for (i = 0; i <= 12; i++)
        printf("%d\t", v[i]);
}
