#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

int buff[MAX];
int pbuff = 0;

int getch(void)
{
        return (pbuff > 0) ? buff[--pbuff] : getchar();
}

void ungetch(int c)
{
        if (pbuff > MAX) {
                printf("[ungetch]: Too many characters.\n");
        } else {
                buff[pbuff++] = c;
        }
}

struct keywords {
        char *word;
        int count;
} keytab[] = {
        {"auto", 0}, {"break", 0}, {"case", 0}, {"char", 0}, {"const", 0},
        {"continue", 0}, {"default", 0}, {"do", 0}, {"double", 0},
        {"else", 0}, {"enum", 0}, {"extern", 0}, {"float", 0}, {"for", 0},
        {"goto", 0}, {"if", 0}, {"int", 0}, {"long", 0}, {"register", 0},
        {"return", 0}, {"short", 0}, {"signed", 0}, {"sizeof", 0},
        {"static", 0}, {"struct", 0}, {"switch", 0}, {"typedef", 0},
        {"union", 0}, {"unsigned", 0}, {"void", 0}, {"volatile", 0}, {"while", 0}
};

int nkeys = sizeof keytab / sizeof keytab[0];

int getword(char *word)
{
        int c;
        while (isspace(c = getch()))
                ;
        ungetch(c);

        while ((c = getch()) != EOF) {
                if (isspace(c)) {
                        *word = '\0';
                        ungetch(c);
                        return word[0];
                } else {
                        *word = c;
                        word++;
                }
        }

        return EOF;
}

int binsearch(char *word, struct keywords tab[], int n)
{
        int low = 0;
        int high = n - 1;
        int mid = -1;
        int cmp;

        while (low <= high) {
                mid = (low + high) / 2;
                cmp = strcmp(word, tab[mid].word);
                if (cmp > 0) {
                        low = mid + 1;
                } else if (cmp < 0) {
                        high = mid - 1;
                } else {
                        return mid;
                }
        }

        return -1;
}

int main()
{
        int n;
        char word[MAX];

        while (getword(word) != EOF) {
                n = binsearch(word, keytab, nkeys);
                if (n != -1)
                        keytab[n].count++;
        }

        for (n = 0; n < nkeys; n++) {
                if (keytab[n].count > 0)
                        printf("%s: %d\n", keytab[n].word, keytab[n].count);
        }

        return 0;
}