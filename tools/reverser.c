#include <string.h>
#include <stdio.h>

void reverse(char s[])
{
	void reverser(char [], int, int);

	reverser(s, 0, strlen(s));
}

void reverser(char s[], int i, int len)
{
	char c;
	int j = len - 1 - i;

	if (i < j) {
		c = s[j];
		s[j] = s[i];
		s[i] = c;
		reverser(s, ++i, len);
	}
}


int main(int argc, char const *argv[])
{
	char s[] = "0123456";
	reverse(s);
	printf("%s\n", s);
	return 0;
}