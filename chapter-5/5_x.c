#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

// 假设有一个 stack 叫 buff, 用来存储提前读取的下一个字符
int buf[MAX];
int pbuf = 0;

int getch(void)
{
        int c;
        if (pbuf > 0) {
                c = buf[pbuf];
                pbuf--;
        } else {
                c = getchar();
        }

        return c;
}

void ungetch(int c)
{
        if (pbuf < MAX) {
                pbuf++;
                buf[pbuf] = c;
        } else {
                printf("Buffer for getch/ungetch is full.\n");
        }
}

// 版本1: 不考虑指针 * 的情况
enum { NAME, PAREN, BRACK, ERR};

void parse_type(char *type)
{
        int c;
        while ((c = getch()) != EOF && !isspace(c)) {
                *type = c;
                type++;
        }

        if (isspace(c))
                *type = '\0';
}

void parse_name(char *name)
{
        int c;
        while ((c = getch()) != EOF && isalpha(c)) {
                *name = c;
                name++;
        }

        ungetch(c);
        *name = '\0';
}

int parse_token(char *num)
{
        int c, token;
        while ((c = getch()) != EOF) {
                if (c == '(') {
                        if ((c = getch()) == ')') {
                                token = PAREN;
                                return token;
                        }
                } else if (c == '[') {
                        for ( ; isdigit(c = getch()); ) {
                                *num = c;
                                num++;
                        }
                        *num = '\0';

                        if (c == ']') {
                                token = BRACK;
                                return token;
                        } else {
                                token = ERR;
                                return token;
                        }
                }
        }
}

int main(void)
{
        char name[MAX];
        char type[10];
        int token;
        char r[MAX];
        char num[10];

        parse_type(type);
        parse_name(name);
        token = parse_token(num);

        if (token == PAREN) {
                strcpy(r, "Func returing");
        } else if (token == BRACK) {
                strcat(r, "Array[");
                strcat(r, num);
                strcat(r, "] of");
        } else if (token == ERR) {
                printf("Syntax Error\n");
                return 1;
        }

        printf("%s: %s %s\n", name, r, type);
        return 0;
}