int binsearch(int x, int s[], int len)
{
    int low, mid, high;
    low = 0;
    high = len - 1;
    mid = (low + high) / 2;
    while (low <= high && x != s[mid]) {
        if (x < s[mid])
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low + high) / 2;
    }
    if (x == s[mid])
        return mid;
    else
        return -1;
}
