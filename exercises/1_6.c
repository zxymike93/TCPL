#include <stdio.h>


int main() {
    int result;
    result = getchar() != EOF;
    while (result) {
        printf("%d", result);
    }
    printf("%d", result);
}
