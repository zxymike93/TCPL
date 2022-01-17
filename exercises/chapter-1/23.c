// uncomment

#include <stdio.h>
#define MAXLINE     1000
#define IN          1
#define OUT         0


void in_comment(char c, char next);

int main()
{
    int c, next;

    while ((c=getchar()) != EOF) {
        if (c == '/') {
            if ((next=getchar()) == '*') {
                in_comment(c, next);
            }
            // else if (next == '') {}
            else {
                putchar(c);
                putchar(next);
            }
        }
        // else if () {}
        else
            putchar(c);
    }
}


void in_comment(char c, char next)
{
    while (c != '*' || next != '/') {
        c = next;
        next = getchar();
    }
}
