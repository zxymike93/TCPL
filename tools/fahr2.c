#include <stdio.h>

/*
    倒序：从 300 到 0 的 fahr-to-celsius
*/

main()
{
    int fahr;

    /*
        在 for-loop 里面
        第一句：init;
        第二句：test;
        第三句：if True, do; if Falase, stop;
    */
    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%3d\t%6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
