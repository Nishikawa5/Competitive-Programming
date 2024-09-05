#include <stdio.h>
#include <stdlib.h>


int main(void) {
    char *instruction = malloc(sizeof(char) * 14);
    int T, n;

    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        int *moves = malloc(sizeof(int) * n);

        int i = 0;
        int position = 0;
        while (i < n) {
            scanf(" %[^\n]", instruction);

            if (instruction[0] == 'L') {
                moves[i] = -1;
            } else if (instruction[0] == 'R') {
                moves[i] = 1;
            } else {
                moves[i] = moves[atoi(instruction + 8) - 1];
            }

            position += moves[i++];
        }

        printf("%d\n", position);
        free(moves);
    }
}