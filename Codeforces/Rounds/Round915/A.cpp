#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) (((a)>(b))?(a):(b))

int main(void) {
    int t;
    scanf("%d", &t);

    int m, n;
    while (t--) {
        scanf("%d %d", &m, &n);

        printf("%d\n", MAX(m, n));
    }
}