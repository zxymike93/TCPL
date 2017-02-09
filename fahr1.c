#include <stdio.h>

main()
{
    int fahr;

    /*
        fahr is kept int during the loop,
        but use float in 'celsius' which is not stated here.
    */
    /*
        init fahr to 0;
        while fahr <= 300;
        do fahr = fahr + 20;
    */
    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
        printf("%3d\t%6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
