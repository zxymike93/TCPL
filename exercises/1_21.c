// entab

#include <stdio.h>
#define TAB 4

int main()
{
    int c, space, ntab, nblank;
    space = ntab = nblank = 0;

    while ((c=getchar()) != EOF) {
        if (c == ' ') {
            ++space;
        }
        else {
            ntab = space / TAB;
            nblank = space % TAB;
            while (ntab > 0) {
                putchar('\t');
                --ntab;
            }
            while (nblank > 0) {
                putchar(' ');
                --nblank;
            }
            if (c == '\n') {
                space = 0;
                putchar(c);
            }
            else if (c == '\t') {
                space = 0;
                putchar(c);
            }
            else
                putchar(c);
        }
    }
}


//     while ((c=getchar()) != EOF) {
//         if (c == ' ') {
//             ++pos;
//             space = pos - endword;
//             ntab = space / TAB;
//             nblank = space % TAB;
//             while (ntab > 0) {
//                 putchar('\t');
//                 --ntab;
//             }
//             while (nblank > 0) {
//                 putchar(' ');
//                 --nblank;
//             }
//         }
//         else if (c == '\t') {
//             pos += TAB;
//             putchar(c);
//         }
//         else if (c == '\n') {
//             endword = pos = 1;
//             putchar(c);
//         }
//         else {
//             ++endword;
//             ++pos;
//             putchar(c);
//         }
//     }
// }
