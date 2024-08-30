#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int T;
    int n;
    char *AB = (char *) malloc(sizeof(char) * 200001);

    scanf("%d", &T);
    getchar();

    while (T--) {
        scanf("%d", &n);
        getchar();
        scanf("%s", AB);
        getchar();

        int A = 0;
        int B = 0;
        int operations = 0;

        for (int i = 0; i < n; i++) {
            if (AB[i] == 'A') {
                A++;
            } else {
                while (i < n && AB[i] == 'B') {
                    B++;
                    i++;
                }
                if (B) i--;
                if (A) {
                    operations += (A + B - 1);
                    A = 1;
                }

                B = 0;
            }
        }
        printf("%d\n", operations);
    }
}