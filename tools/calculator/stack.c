#include <stdio.h>
#include <stdlib.h>

#define MAXVAL 100

int sp = 0;             // stack pointer
double val[MAXVAL];     // stack

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("push: stack is full\n");
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("pop: stack empty\n");
        return 0.0;
    }
}

void empty(void)
{
    sp = 0;
}
