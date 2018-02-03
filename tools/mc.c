#include <stdio.h>

#define dprint(expr) printf(#expr " = %g\n", expr)
/* 如果用函数则无法替换
 */

int main()
{
    double x = 1.0;
    double y = 1.0;
    dprint(x/y);
}
