#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int T;
    int n;
    int *vec = (int *) malloc(sizeof(int) * 10);

    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &vec[i]);
        }

        if (vec[0] == 1) printf("YES\n");
        else             printf("NO\n");
    }
}