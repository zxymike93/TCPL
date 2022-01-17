// expr 2 3 4 * +
// Notice: On Ubuntu and zsh, escape *
// >>> 2 * (3 + 4)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int sp = 0;
int stack[MAX];

void push(int x)
{
        if (sp < MAX) {
                stack[sp] = x;
                sp++;
        } else {
                printf("PUSH: Stack is full.\n");
        }
}

int pop(void)
{
        if (sp > 0) {
                sp--;
                printf("POP: %d\n", stack[sp]);
                return stack[sp];
        } else {
                printf("POP: Stack is empty.\n");
                return 0;
        }
}

int main(int argc, char *argv[])
{
        int i;
        //printf("MAIN, argc: %d\n", argc);
        for (i = 1; i < argc; i++) {
                //printf("MAIN, argv[i]: %s\n", argv[i]);
                if (*argv[i] > '0' && *argv[i] < '9') {
                        push(atoi(argv[i]));
                } else if (strcmp(argv[i], "+") == 0) {
                        push(pop() + pop());
                } else if (strcmp(argv[i], "-") == 0) {
                        int tmp = pop();
                        push(pop() - tmp);
                } else if (strcmp(argv[i], "*") == 0) {
                        push(pop() * pop());
                } else if (strcmp(argv[i], "/") == 0) {
                        int tmp = pop();
                        push(pop() / tmp);
                } else {
                        printf("MAIN: Operation not suppported.\n");
                }
        }

        printf(">>> %d\n", pop());
        return 0;
}