#include <stdio.h>
#include <limits.h>


int main()
{
    printf("signed char min: %d\t max: %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("signed short min: %d\t max: %d\n", SHRT_MIN, SHRT_MAX);
    printf("signed int min: %d\t max: %d\n", INT_MIN, INT_MAX);
    printf("signed long min: %ld\t max: %ld\n", LONG_MIN, LONG_MAX);

    printf("unsigned char max: %d\n", UCHAR_MAX);
    printf("unsigned short max: %u\n", USHRT_MAX);
    printf("unsigned int max: %u\n", UINT_MAX);
    printf("unsigned long max: %lu\n", ULONG_MAX);
}
