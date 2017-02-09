#include <stdio.h>

main()
{
    printf("The value of EOF is %d\n\n", EOF);
    printf("Enter a character: \n");
    printf("The expression 'getchar() != EOF' evaluates to %d\n", getchar() != EOF);
}

