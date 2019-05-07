// char **argv
//      argv: pointer to pointer to char (* > * > char)

// int (*daytab)[13]
//      daytab: pointer to array[13] of int (* > [13])

// int *daytab[13]
//      daytab: array[13] of pointer to int ([13: * > int])

// void *comp()
//      comp: function returning pointer to void (f = *)

// void (*comp)()
//      comp: pointer to function returning void (* = void)

// char (*(*x())[])()
//      x: function returning pointer to array[] of
//         pointer to function returning char
//      (char (f (ptr
//                (list (ptr (f))))))

// char (*(*x[3])())[5]
//      x: array[3] of pointer to function returning
//         pointer to array[5] of char
//      (char (* 5
//               (list (ptr
//                       (f (ptr
//                            (* 3 (list)))))))))

// dcl:         *ddcl
// ddcl:        name
//              (dcl)
//              ddcl()
//              ddcl[]

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

enum {
        NAME,
        PARENS,
        BRACKETS
};

char buf[MAX];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= MAX)
        printf("ungetch: too many chars\n");
    else
        buf[bufp++] = c;
}

char out[1000];
int tokentype;
char name[MAX];
char token[MAX];

int gettoken(void)
{
        int c;
        char *p = token;

        while ((c = getch()) == ' ' || c == '\t')
                ;

        if (c == '(') {
                if ((c = getch()) == ')') {
                        strcpy(token, "()");
                        return tokentype = PARENS;
                } else {
                        ungetch(c);
                        return tokentype = '(';
                }
        } else if (c == '[') {
                for (*p++ = c; (*p++ = getch()) != ']'; )
                        ;
                
                *p = '\0';
                return tokentype = BRACKETS;
        } else if (isalpha(c)) {
                for (*p++ = c; isalnum(c = getch()); )
                        *p++ = c;
                
                *p = '\0';
                ungetch(c);
                return tokentype = NAME;
        } else {
                return tokentype = c;
        }
}

void dcl(void);
void dirdcl(void);

void dcl(void)
{
        int ns;

        for (ns = 0; gettoken() == '*'; )
                ns++;
        
        dirdcl();
        while (ns-- > 0)
                strcat(out, " pointer to");
}

void dirdcl(void)
{
        int type;

        if (tokentype == '(') {
                dcl();
                if (tokentype != ')')
                        printf("ERROR: missing )\n");
        } else if (tokentype == NAME) {
                strcpy(name, token);
        } else {
                printf("ERROR: expected name or (dcl)\n");
        }

        while ((type = gettoken()) == PARENS || type == BRACKETS) {
                if (type == PARENS) {
                        strcat(out, " function returning");
                } else {
                        strcat(out, " array");
                        strcat(out, token);
                        strcat(out, " of");
                }
        }
}

void test_dcl(void);
void test_undcl(void);

int main()
{
        // test_dcl();
        test_undcl();

        return 0;
}

char datatype[MAX];

void test_dcl(void)
{
        while (gettoken() != EOF) {
                strcpy(datatype, token);
                out[0] = '\0';
                dcl();

                if (tokentype != '\n')
                        printf("Syntax Error\n");

                printf("%s: %s %s\n", name, out, datatype);
        }
}

void test_undcl(void)
{
        int type;
        char tmp[MAX];

        while (gettoken() != EOF) {
                strcpy(out, token);
                while ((type = gettoken()) != '\n') {
                        if (type == PARENS || type == BRACKETS) {
                                strcat(out, token);
                        } else if (type == '*') {
                                sprintf(tmp, "(*%s)", out);
                                strcpy(out, tmp);
                        } else if (type == NAME) {
                                sprintf(tmp, "%s %s", token, out);
                                strcpy(out, tmp);
                        } else {
                                printf("Invalid input at %s\n", token);
                        }
                }

                printf("%s\n", out);
        }
}