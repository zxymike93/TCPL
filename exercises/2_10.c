#include <stdio.h>

int lower(int c);

int main()
{
    int c = 'A';
    int b = 'D';
    printf("%c\n", lower(c));
    printf("%c\n", lower(b));
}


int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c+'a'-'A' : c;
}
