4.4 作用域规则
------------

declairation 用于说明变量的属性(主要是 type)
definition 则引起存储器分配, 以及实现函数等

在一个程序中, 一个外部变量只能**定义一次**, 变量也只能在定义中初始化.
如果从另一个源文件中引用一个**定义**, 就需要用到 ``extern``.

4.5 头文件
---------

4.6 静态变量
-----------
静态变量声明::
    static int i;

用于把外部变量/函数的作用域限定在该文件中.
*static 也可以声明内部变量，但该变量会一只存在，无论函数被调用与否*

4.7 寄存器变量
------------

`register` 声明某个变量，目的在于：认为它的使用频次较高，告诉编译器保存在寄存器中

只允许两种使用方式::
    int func(register y)    // 声明函数行参
    {
        register int x;     // 声明自动变量
    }

4.8 程序块结构
------------

4.9 初始化
---------

不显式初始化的情况下：
    - 外部变量 == 0
    - static == 0
    - 自动变量 (undefined)
    - register (undefined)

**造成本人多次得到 `segmenfaultation` 的报错，debug 半天无法定位。**
**因此建议：声明自动变量(也许还有 register)的时候，自觉初始化。**

初始化 外部变量 / 静态变量 必须使用常量表达式，程序执行前被初始化::
    int num = 1;    // true
    int num = n + 1;    // false

自动变量 / 寄存器变量 支持常量或者表达式初始化，每次函数或程序块的时候都将初始化。

数组的初始化::
    int days[] = {1, 2, 3, 4, 5, 6, 7};     // 隐含 days[7]
    int days[10] = {1, 2, 3};       // 余下的元素为 0

字符数组的初始化::
    char name[] = "mike";
    char name[] = {'m', 'i', 'k', 'e', '\0'};       // name[5]

4.10 递归
--------

function 可以调用自身。
::
    void printd(int n)
    {
        if (n < 0) {
            putchar('-');
            n = -n;
        }
        if (n / 10)
            printd(n / 10);
        putchar(n % 10 + '0');
    }

4.11 C 预处理器
--------------

.. preprocessor
先看 compile 一个 C source file 的步骤::
    hello.c -[preprocessor]-> hello.i -[compiler]-> hello.s (asm) -[assembler]-> hello.o (binary) + printf.o -[link director]-> hello (executable)

其中 preprocessor 就是处理 c source file 开头的那些 # 命令

4.11.1 文件包含
~~~~~~~~~~~~~~

::
    #include <filename>     // 使用编译器 include 的路径
    #include "filename"     // 使用源文件的相对路径

如果用 gcc 的话，可以自定义 include 的路径::
    gcc -v include_path hello.c

这样就可以使用代码根目录组织头文件::
    #include <utils/log.h>
    #include <data/whatever.h>

4.11.2 宏替换
~~~~~~~~~~~~

宏替换实际是文本替换
::
    #define NUM 1
    #define forver for(;;)
    #define max(A, B) ((A) > (B) ? (A) : (B))

取消宏替换
::
    #undef getchar
    int getchar(void) {...}

宏替换还有一个用途就是替换行参，考虑下面这种情况
::
    printf("x/y = %g\n", x/y);
如果不是表达式 `x/y` 而是 `x * y`，整个 `printf` 就要修改。如果使用宏的方式，可以这样做
::
    #define dprintf(expr) printf(#expr " = %g\n", expr)

    dprintf(x/y);
    >> printf("x/y" " = %g\n", x/y);
    >> printf("x/y = %g\n", x/y);

    dprintf(x * y);
    >> printf("x/y" " = %g\n", x*y);
    >> printf("x/y = %g\n", x*y);
这里面的 `#expr` 被替换为 `"expr"`。

另外宏还可以连接两个实参
::
    #define paste(front, back)  front ## back

    paste(1, 2);
    >> 12

4.11.3 条件包含
~~~~~~~~~~~~~~

指针与数组
=========

指针是保存变量地址的变量

指针与地址
---------

程序的变量是存储在连续的存储单元中的(虚拟地址), 比如: char 1 bytes, short 2 bytes, long 4 bytes.
指针也是变量, 它一般是 2 | 4 bytes.

::
    int x = 1, y = 2, z[10];
    int *ip;    // 声明指针 ip, *ip 的返回值是 int
    ip = &x;    // &x 对 x 取地址
    y = *ip;    // 指针 ip 取值 *ip
    *ip = 0;    // x == 0
    ip = &z[0]; // &z[0] 数组的第一个元素取地址

每个指针都必须指定一种类型, 该类型可以出现的任何上下文都可以出现该指针::
    *ip = *ip + 10;
    y = *ip + 1;
    *ip += 1;
    ++*ip;
    (*ip)++;    // 从右到左计算, 所以要加括号

指针与函数参数
------------

为了对指针能做什么有一个简单的认知, 试想这样一个情况:
我们要实现一个函数 `swap(a, b)`, 把 a, b 的值调换::
    void swap(int a, int b)
    {
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
这是之前程序写过也很直接的想法. 但是 C 是通过 copy 的方式传参的, 也就是说以上如果::
    int x = 1, y = 2;
    swap(x, y);
会产生 a = x, b = y; 不影响 x, y 的值.
那么如果要达到原来的目的, 我们使用指针作为行参定义 swap::
    void swap(int *a, int *b)
    {
        int tmp;
        tmp = *a;
        *a = *b;
        *b = tmp;
    }
再通过传入地址实参调用::
    swap(&x, &y);
    // a = &x, b = &y;
就可以影响到实参本身.