// Search for PATTERN in keyboard input.
// Usage: grep [OPTIONS]... PATTERN
// Options:
//     -x   Print lines that don't match PATTERN
//     -n   Print line numbers.

#include <stdio.h>

#define MAXLINE 100

// return int length of line
int readline(char line[], int max_line)
{
        int c, i = 0;
        while (--max_line > 0 && (c=getchar()) != EOF && c != '\n')
                line[i++] = c;

        if (c == '\n')
                line[i++] = '\n';

        line[i] = '\0';
        return i;
}

// return first index of pattern in searched line
int strindex(char s[], char p[])
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
            for (j=i, k=0; p[k]!='\0' && s[j]==p[k]; j++, k++)
                    ;

            if (p[k] == '\0' && k > 0)
                    return i;
    }
    return -1;
}

int main(int argc, char *argv[])
{
        char line[MAXLINE];
        int found = 0, e = 0, n = 0, c;
        long linum = 0;

        // Read OPTIONS
        // (*++argv)[0] eq **++argv
        while (--argc > 0 && (*++argv)[0] == '-') {
                // *++argv[0] eq *++(argv[0])
                while (c = *++argv[0]) {
                        switch (c) {
                        case 'x':
                                e = 1;
                                break;
                        case 'n':
                                n = 1;
                                break;
                        default:
                                printf("grep: illegal option %c\n", c);
                                argc = 0;
                                found = -1;
                                break;
                        }
                }
        }

        // use argv[1] as pattern
        if (argc != 1) {
                printf("Usage: grep -n -x PATTERN\n");
        } else {
                while (readline(line, MAXLINE) > 0) {
                        linum++;
                        if ((strindex(line, *argv) >= 0) != e) {
                                if (n == 1) {
                                        printf("%ld ", linum);
                                }
                                printf("%s", line);
                                found++;
                        }
                }
        }
        return found;
}