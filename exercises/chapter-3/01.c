#include <stdio.h>

// Return index of x in s(a list of numbers)
int binsearch(int x, int s[], int len)
{
        int low = 0;
        int high = len - 1;
        int mid = (low + high) / 2;

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

int test_one()
{
        int len = 1000;
        int nums[len];
        int i = 0;

        while (i < len -1) {
                nums[i] = i + 1;
                i++;
        }

        return binsearch(5, nums, len);
}

int test_two()
{
        int x = 4;
        int nums[10] = {0, 4, 8, 9, 10, 11, 14, 35, 100, 111};

        return binsearch(8, nums, 10);
}

int main()
{
        int r;

        r = test_one();
        printf("Test binsearch: %d\n", r);
        r = test_two();
        printf("Test binsearch: %d\n", r);
}