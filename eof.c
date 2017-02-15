#include <stdio.h>

main()
{
    /* -1 */
    printf("The value of EOF is %d\n\n", EOF);
    /* press control+D */
    printf("Enter a character: \n");
    printf("The expression 'getchar() != EOF' evaluates to %d\n", getchar() != EOF);
}

