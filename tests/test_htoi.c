#include <stdio.h>
#include "../htoi.c"

int main() {
    char s1[] = {'F', 'D'};
    char s2[] = "0x9d";
    char s3[] = "00";
    htoi(s1);
    htoi(s2);
    htoi(s3);
}
