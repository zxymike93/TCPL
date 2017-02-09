#include <stdio.h>

#define    LOWER 0      /* 类似于 lower = 0 */
#define    UPPER 300    /* 但 LOWER 是常量，lower 是变量 */
#define    STEP 20

main()
{
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d\t%6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}

/*
    Question?

    如果误写为 %3.0d, 则不输出 0，其余数值均能输出，
    如果误写为 %3.0f，则因 int fahr，类型错误 expect argument of type 'double'.
*/
