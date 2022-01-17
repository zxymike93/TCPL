# 指针与数组

指针是保存变量地址的变量.

## 目录

- 指针与地址
- 指针与函数参数
- 指针与数组
- 地址算数运算
- 字符指针与函数
- 指针数组以及指向指针的指针
- 多位数组
- 指针数组的初始化
- 指针与多位数组
- 命令行参数
- 指向函数的指针
- 复杂声明

## 指针与地址


程序的变量是存储在连续的存储单元中的(虚拟地址), 比如: char 1 bytes, short 2 bytes,
long 4 bytes.  指针也是变量, 它一般是 2 | 4 bytes.

```c
    int x = 1, y = 2, z[10];
    int *ip;    // 声明指针 ip, *ip 的返回值是 int
    ip = &x;    // &x 对 x 取地址
    y = *ip;    // 指针 ip 取值 *ip
    *ip = 0;    // x == 0
    ip = &z[0]; // &z[0] 数组的第一个元素取地址
```

每个指针都必须指定一种类型, 该类型可以出现的任何上下文都可以出现该指针:

```c

    *ip = *ip + 10;
    y = *ip + 1;
    *ip += 1;
    ++*ip;
    (*ip)++;    // 从右到左计算, 所以要加括号
```

## 指针与函数参数

*指针参数使被调函数能修改主调函数中对象的值.*

下面来说明这一点, 假设有如下情况 --
我们要实现一个函数 ``swap(a, b)``, 把 a, b 的值调换:

```c
    void swap(int a, int b)
    {
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
``

这是之前程序写过也很直接的想法. 但是 C 是通过 copy 的方式传参的, 也就是说以上如果:

```c
    int x = 1, y = 2;
    swap(x, y);
```

会产生 a = x, b = y; 不影响 x, y 的值.
那么如果要达到原来的目的, 我们使用指针作为行参定义 swap:

```c
    void swap(int *a, int *b)
    {
        int tmp;
        tmp = *a;
        *a = *b;
        *b = tmp;
    }
```

再通过传入地址实参调用:

```c
    swap(&x, &y);
    // a = &x, b = &y;
```

就可以影响到实参本身.

.. todo::
    getint / getfloat

## 指针与数组

C 语言中, 指针几乎可以当数组下标使用. 但是对于编程新手, 或者没接触过指针的程序员来说,
指针很绕.

```c
    #include <stdio.h>

    int main() {
        int x;
        int a[5] = {0, 1, 2, 3, 4};
        int i;

        i = 0;
        x = a[i];
        printf("x = %d = a[0]\n", x);

        i = 3;
        x = a[i];
        printf("x = %d = a[3]\n", x);

        i++;
        x = a[i];
        printf("x = %d = a[4]\n", x);
    }

    >>> x = 0 = a[0]
    >>> x = 3 = a[3]
    >>> x = 4 = a[4]
```

类似地, 我们再下一个例子:

```c
    #include <stdio.h>

    int main() {
        int x;
        int a[5] = {0, 1, 2, 3, 4};
        int *pa;

        pa = a;
        x = *pa;
        printf("x = %d = a[0]\n", x);

        pa = &a[3];
        x = *pa;
        printf("x = %d = a[3]\n", x);

        pa++;
        x = *pa;
        printf("x = %d = a[4]\n", x);
    }
```

对应的我们可以看到:

- ``<pointer> = &array[index]`` 相当于 ``i = index``
- ``x = *<pointer>`` 相当于 ``x = array[index]``
- ``<pointer>++`` 相当于 ``<index>++``
- ``<pointer> = array`` 相当于 ``<pointer> = &array[0]``

这样不难发现, 当指针指向数组(因为缺省值为 0 (所以严格来说是指向数组中的元素)), 指针很显然
可以当下标来使用. 因此我们可以看下面操作:

```c
    #include <stdio.h>

    int main() {
        int i;
        int a[5];
        int *pa;

        pa = a;
        for (i = 0; i < 5; i++, pa++)
            *pa = i;

        for (i = 0; i < 5; i++)
            printf("%d\n", a[i]);
    }
```

直接使用 ``*<pointer> = ...`` 赋值, 相当于 ``array[index] = ...`` .
