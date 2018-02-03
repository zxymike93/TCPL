/* pseudo-code

    have x and L[a..b],
    get L[mid] = (b-a)/2
    if x > L[mid]:
        L[mid..b]
    else x < L[mid]:
        L[a..mid]
    else x == L[mid]:
        return mid
*/

int x;
int length;
int L[length];


int binsearch(int x, int L[], int length)
{
    int a = 0;
    int b = length - 1;
    int mid;
    while (a < b) {
        mid = (b + a) / 2;
        if (x > L[mid])
            a = mid;
        else if (x < L[mid])
            b = mid;
        else
            return mid;
    }
    return -1;
}

