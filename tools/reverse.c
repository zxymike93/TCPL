void reverse(char s[])
{
    int i, j = 0;
    char temp;

    while (s[i] != '\0')
        ++i;
    --i;
    if (s[i] == '\n')
        --i;
    while (j < i) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        --i;
        ++j;
    }
}
