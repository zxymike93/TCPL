// htoi - heximal to decimal

#include <stdio.h>

#define VALID 1
#define INVALID 0

int htoi(char s[]) {
        int i = 0, n = 0, h = 0;
        int state;

        // skip prefix like - 0x, 0X, etc..
        if (s[i] == '0') {
                ++i;
                if (s[i] == 'x' || s[i] == 'X') {
                        ++i;
                }
        }

        for (state = VALID; state == VALID; ++i) {
                if (s[i] >= '0' && s[i] <= '9') {
                        h = s[i] - '0';
                } else if (s[i] >= 'a' && s[i] <= 'f') {
                        h = s[i] - 'a' + 10;
                } else if (s[i] >= 'A' && s[i] <= 'F') {
                        h = s[i] - 'A' + 10;
                } else {
                        state = INVALID;
                }

                if (state == VALID) {
                        n = n * 16 + h;
                }
        }

        printf("%d\n", n);
        return n;
}

int main() {
        char s1[] = {'F', 'D'};
        char s2[] = "0x9d";
        char s3[] = "00";

        // 253
        htoi(s1);
        // 157
        htoi(s2);
        // 0
        htoi(s3);
}