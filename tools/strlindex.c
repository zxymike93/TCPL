// string left index

int strlindex(char s[], char p[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; p[k] != '\0' && s[j] == p[k]; j++, k++)
            ;
        if (k > 0 && p[k] == '\0')
            return i;
    }
    return -1;
}
