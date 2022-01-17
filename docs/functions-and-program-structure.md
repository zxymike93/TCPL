函数与程序结构
============


目录
----
- 函数的基本知识
- 返回非整型值的函数
- 外部变量
- 作用域规则
- 头文件
- 静态变量
- 寄存器变量
- 程序块结构
- 初始化
- 递归
- C预处理器
    - 文件包含
    - 宏替换
    - 条件包含


4.4 作用域规则
------------

declairation 用于说明变量的属性(主要是 type).
definition 则引起存储器分配, 以及实现函数等.

在一个程序中, 一个外部变量只能**定义一次**, 变量也只能在定义中初始化.
如果从另一个源文件中引用一个**定义**, 就需要用到 ``extern``.


4.5 头文件
---------

该节例子中的程序要同时编译多文件:

    $ clang main.c mathfn.c stack.c getch.c getop.c


4.6 静态变量
-----------

静态变量声明

    static int i;

用于把外部变量/函数的作用域限定在该文件中.
*static 也可以声明内部变量，但该变量会一只存在，无论函数被调用与否*


4.7 寄存器变量
------------

``register`` 声明某个变量，目的在于：认为它的使用频次较高，告诉编译器保存在寄存器中, 只允许两种使用方式:

    int func(register y)    // 声明函数行参
    {
        register int x;     // 声明自动变量
    }


4.8 程序块结构[TODO]
------------


4.9 初始化
---------

不显式初始化的情况下：

    - 外部变量 == 0
    - static == 0
    - 自动变量 (undefined)
    - register (undefined)

造成本人多次得到 ``segmenfaultation`` 的报错，debug 半天无法定位。  因此建议:
*声明自动变量(也许还有 register)的时候，自觉初始化.*

初始化 外部变量 / 静态变量 必须使用常量表达式，程序执行前被初始化:

    int num = 1;    // true
    int num = n + 1;    // false

自动变量 / 寄存器变量 支持常量或者表达式初始化，每次函数或程序块的时候都将初始化.

数组的初始化:

    int days[] = {1, 2, 3, 4, 5, 6, 7};     // 隐含 days[7]
    int days[10] = {1, 2, 3};       // 余下的元素为 0

字符数组的初始化:

    char name[] = "mike";
    char name[] = {'m', 'i', 'k', 'e', '\0'};       // name[5]


4.10 递归
--------

function 可以调用自身:

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

先看 compile 一个 C source file 的步骤:

    hello.c -[preprocessor]->
    hello.i -[compiler]->
    hello.s (asm) -[assembler]->
    hello.o (binary) + printf.o -[link director]->
    hello (executable)

其中 preprocessor 就是处理 c source file 开头的那些 # 命令.

4.11.1 文件包含
~~~~~~~~~~~~~~

``#include`` 有两种用法:

    #include <filename>     // 使用编译器 include 的路径
    #include "../filename"     // 使用源文件的相对路径

一般 C 的标准库头文件都是用 ``<>`` 引入, 因为它们在编译器默认的 include 路径中, 比如:

    /usr/include/stdio.h

我们可以通过编译器选项添加路径, 比如下面几个源代码:

    // test_getint.c
    #include <tools/calculator/calc.h>
    #include <tools/getint.c>

添加项目根目录 ``~/TCPL/``, 使用如下命令编译:

    $ clang -I ./ -v -o outputs/test_getint tests/test_getint.c tools/calculator/getch.c

4.11.2 宏替换
~~~~~~~~~~~~

宏替换实际是文本替换:

    #define NUM 1
    #define forver for(;;)
    #define max(A, B) ((A) > (B) ? (A) : (B))

取消宏替换:

    #undef getchar
    int getchar(void) {...}

宏替换还有一个用途就是替换行参，考虑下面这种情况:

    printf("x/y = %g\n", x/y);

如果不是表达式 ``x / y`` 而是 ``x * y``，整个 ``printf`` 就要修改。如果使用宏的方式，可以这样做:

    #define dprintf(expr) printf(#expr " = %g\n", expr)

    dprintf(x/y);
    >>> printf("x/y" " = %g\n", x/y);
    >>> printf("x/y = %g\n", x/y);

    dprintf(x * y);
    >>> printf("x/y" " = %g\n", x*y);
    >>> printf("x/y = %g\n", x*y);

这里面的 ``#expr`` 被替换为 ``"expr"`` 。

另外宏还可以连接两个实参:

    #define paste(front, back)  front ## back

    paste(1, 2);
    >>> 12

4.11.3 条件包含[TODO]
~~~~~~~~~~~~~~
