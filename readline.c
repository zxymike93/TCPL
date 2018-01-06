int readline(char line[], int max_line)
{
    int c, i;
    /* return int length of line */
    while (--max_line > 0 && (c=getchar() != EOF) && c != '\n') {
        line[i++] = c;
    }
    if (c == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return i;
}
