#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


#define MAXOP 100
#define NUMBER '0'
#define NAME '1'

int getop(char []);
void push(double);
double pop(void);
void empty(void);
void math_func(char []);

int main()
{
    int type;
    double op, op2;
    char s[MAXOP];

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
            printf("error: %d not supported\n", type);
            break;
        }
    }
    return 0;
}


void math_func(char s[])
{
    double op2;

    if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s, "pow") == 0) {
        op2 = pop();
        push(pow(pop(), op2));
    } else
        printf("error: %s not supported\n", s);
}


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


int getch(void);
void ungetch(int);

// get next num / op from stack
int getop(char s[])
{
    int i, c;
    i = 0;

    // space
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    // math funcs
    if (isalpha(c)) {
        while (isalpha(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);
        if (strlen(s) > 1)
            return NAME;
        else
            return c;
    }
    // not number
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    // negative
    if (c == '-') {
        if (isdigit((c = getch())) || c == '.')
            s[++i] = c;
        else {
            if (c != EOF)
                ungetch(c);
            return '-';
        }
    }
    // positive
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
