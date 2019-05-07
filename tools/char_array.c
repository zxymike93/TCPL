#include <stdio.h>

int main(int argc, char *argv[])
{
        // ./test hello world
        printf("%c\n", (*++argv)[0]);
        printf("%c\n", *++argv[0]);
}