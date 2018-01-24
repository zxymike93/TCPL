int escape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; ++i, ++j) {
        switch (s[i]) {
        case '\n':
            t[j++] = '\\';
            t[j] = 'n';
            break;
        case '\t':
            t[j++] = '\\';
            t[j] = 't';
            break;
        default:
            t[j] = s[i];
            break;
        }
    }
    t[j] = '\0';
}


int unescape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; ++i, ++j) {
        if (s[i] != '\\')
            t[j] = s[i];
        else {
            switch (s[++i]) {
            case 't':
                t[j] = '\t';
                break;
            case 'n':
                t[j] = '\n';
                break;
            default:
                t[j] = s[i];
                break;
            }
        }
    }
    t[j] = '\0';
}
