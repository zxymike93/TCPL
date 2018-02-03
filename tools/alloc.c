#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

/* 返回指向n个字符的指针 */
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp -n;
    }
    else
        return 0;
}

/* 释放p指向的存储区 */
void afree(char *p)
{
    if (p >= allocbuff && p < allocbuff + ALLOCSIZE)
        allocp = p;
}
