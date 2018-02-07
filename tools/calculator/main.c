#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "calc.h"

#define MAXOP 100

int main()
{
    int type;
    double op, op2;
    char s[MAXOP];
    int vars[26];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case NAME:
            math_func(s);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: cannot divide zero\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("error: cannot mod zero\n");
            break;
        case '=':
            op2 = (int)pop();
            printf("op2=%d, A=%d", op2, A);
            if (op2 >= A && op2 <= Z)
                vars[(int)op2 - 'A'] = pop();
            else
                printf("error: variable name not defined\n");
            break;
        case 'p':
            op2 = pop();
            push(op2);
            break;
        case 'c':
            op2 = pop();
            push(op2);
            push(op2);
            break;
        case 's':
            op2 = pop();
            op = pop();
            push(op2);
            push(op);
            break;
        case 'e':
            empty();
            break;
        case 'i':
            printf(">>> %.8g\n", sin(pop()));
            break;
        case '\n':
            printf(">>> %.8g\n", pop());
            break;
        default:
            if (type >= 'A' && type <= 'Z')
                push(vars[type - 'A']);
            else
            printf("error: %d not supported\n", type);
            break;
        }
    }
    return 0;
}
