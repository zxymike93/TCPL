#include <stdio.h>

int main()
{
    int s[] = {1, 2, -1};
    int n = 4;
    int i;

    if (n > 0)
        for (i = 0; i < n; i++) {
            if (s[i] > 0) {
                printf("...\n");
            }
        }
    else
        printf("error");
}
