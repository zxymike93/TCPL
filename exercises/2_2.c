// Implement this for loop without && || operator
//  for (i = 0; i < lim - 1 && (c=getchar()) != '\n' && c != EOF; ++i)
//      s[i] = c;

#define YES     1
#define NO      0
int state;
int i = 0;
int c;

for (i = 0; state == YES; ;) {
    if (i >= lim - 1)
        state = NO;
    else if ((c=getchar()) == '\n')
        state = NO;
    else if (c == EOF)
        state = NO;
    else {
        s[i] = c;
        ++i;
    }
}
