#include <stdio.h>

#define MAXLINE 1000

/* 定义外部变量 */
int max;
char line[MAXLINE];
char longest[MAXLINE];

/* 函数原型 */
int readline(void);
void copy(void);


main()
{
    int len;
    /* 声明外部变量 */
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = readline()) > 0) {
	if (len > max) {
            max = len;
	    copy();
	}
    }
    if (max > 0) {
	printf("%s", longest);
    }
    return 0;
}


/* 函数声明 */
int readline(void)
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE-1
        && (c=getchar()) != EOF && c != '\n'; ++i) {
	    line[i] = c;
    }
    if (c == '\n') {
	line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}


/* 函数声明 */
void copy(void)
{
    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0') {
	++i;
    }
}

