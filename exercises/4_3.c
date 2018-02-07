#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
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
        case '\n':
            printf(">>> %.8g\n", pop());
            break;
        default:
            printf("error: operator not supported");
            break;
        }
    }
    return 0;
}


#define MAXVAL 100

int sp = 0;             // stack space
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


int getch(void);
void ungetch(int);

// get next num / op from stack
int getop(char s[])
{
    int i, c;
    i = 0;

    // not number
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-')
        return c;

    if (c == '-') {
        if (isdigit((c = getch())) || c == '.')
            s[++i] = c;
        else {
            if (c != EOF)
                ungetch(c);
            return '-';
        }
    }

    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    if (c == '.') {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

#define BUFFSIZE 100

char buf[BUFFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFFSIZE)
        printf("ungetch: too many chars\n");
    else
        buf[bufp++] = c;
}
