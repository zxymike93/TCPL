#include <stdio.h>

// version 1
// arguments: counter, valuables[]
// int main(int argc, char *argv[])
// {
//         int i;
//         for (i = 1; i < argc; i++) {
//                 printf("%s%s", argv[i], (i == argc) ? "" : " ");
//         }
//         printf("\n");
//         return 0;
// }

// version 2
int main(int argc, char *argv[])
{
        while (--argc > 0)
                // first argument is the name of this file
                // printf("%s%s", *(++argv), (argc > 1) ? " " : "");
                printf((argc > 1) ? "%s " : "%s", *++argv);
        
        printf("\n");
        return 0;
}