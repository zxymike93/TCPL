#include <stdio.h>


/* 
 * swap 用于交换两个 int 的值
 *
 * 比较直观的想法如下，但只是交换了函数内部的变量，而不会影响调用者
 * 比如：swap(a, b) => a, b 的值保持不变
 * 因为 x, y 是 a, b 的副本
 *
 */

void swap_1(int x, int y)
{
    int temp;

    temp = x;
    x = y;
    y = temp;
}

/*
 * 下面这个 swap 使用指针
 * 当 swap(&a, &b) => 指针 *x, *y 指向 a, b 的地址
 * 可以替换 a, b 的值
 */
void swap_2(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void swap_3(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
