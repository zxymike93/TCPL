#include <stdio.h>

int main()
{
    char c;
    int small, mid, big;

    while ((c=getchar()) != EOF) {
        switch (c) {
        case '(': ++small; break;
        case ')': --small; break;
        case '[': ++mid; break;
        case ']': --mid; break;
        case '{': ++big; break;
        case '}': --big; break;
        default: break;
        }

        // if (c == '(')
        //     ++small;
        // else if (c == '[')
        //     ++mid;
        // else if (c == '{')
        //     ++big;
        // else if (c == ')')
        //     --small;
        // else if (c == ']')
        //     --mid;
        // else if (c == '}')
        //     --big;
    }
    if (small != 0 || mid != 0 || big != 0)
        printf("Syntax Error\n");
    return 0;
}
