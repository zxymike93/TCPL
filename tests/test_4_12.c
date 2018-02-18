#include <stdio.h>
#include "../exercises/4_12.c"

#define MAXLEN 100

void itoa(int, char *);

int main()
{
	int a = 123;
	int b = -123;
	int c = 0;
	char s[MAXLEN];
	char t[MAXLEN];
	char u[MAXLEN];

	itoa(a, s);
	itoa(b, t);
	itoa(c, u);

	printf("a: %s\n", s);
	printf("b: %s\n", t);
	printf("c: %s\n", u);
}