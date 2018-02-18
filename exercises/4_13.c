#include <stdio.h>

void reverse(char s[])
{
	static int i;
	static int j;
	char temp;

	if (i == 0) {
		while (s[i] != '\0')
			++i;
		--i;
		if (s[i] == '\n')
			--i;
	}

	if (j < i) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		++j;
		--i;
		reverse(s);
	}
}


int main(int argc, char const *argv[])
{
	char s[] = "0123456";
	reverse(s);
	printf("%s\n", s);
	return 0;
}