#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int t;
    char pos1;
    int pos2;

    scanf("%d", &t);
    getchar();
    while (t--) {
        scanf("%c", &pos1);
        scanf("%d", &pos2);
        getchar();

        for (int i = 0; i < 8; i++) {
            if (pos1 != 'a' + i) {
                printf("%c%d\n", 'a' + i, pos2);
            }
        }

        for (int i = 0; i < 8; i++) {
            if (pos2 != i + 1) {
                printf("%c%d\n", pos1, i + 1);
            }
        }
    }
}