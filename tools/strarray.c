#include <stdio.h>

#define MAXLINE 1000

int readline(char line[], int maxline);
void copy(char to[], char from[]);


/* Print the longest line. */
main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = readline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
	    copy(longest, line);
        }
    }
    if (max > 0) {
        printf("%s", longest);
    }
    return 0;
}


/* Read one line at one time,
    store it in variable s,
    and return its length. */
int readline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i) {
	s[i] = c;
    }
    if (c == '\n') {
	s[i] = c;
	++i;
    }
    /* 把空字符插入到行尾作为字符串结束的标志 */
    s[i] = '\0';
    return i;
}


/* Copy array from[] to array to[],
    to[] is assumed big enough. */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
	++i;
    }
}

