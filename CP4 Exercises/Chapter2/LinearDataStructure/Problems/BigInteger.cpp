#include <stdio.h>

int main(void) {
    char integer[102]; // 101 digits integer
    while (scanf("%s", integer) != EOF && integer[0] != '0' && integer[1] != '\0') {
        int r = 0;
        for (int i = 0; integer[i] != '\0'; i++) {
            r = ((r * 10) + integer[i] - '0') % 17;
        }
        printf("%d\n", !r);
    }
}