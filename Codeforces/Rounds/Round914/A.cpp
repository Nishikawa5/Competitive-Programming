#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*
we make an L with every possibility of one piece and test
*/
int steps[2] = {-1, 1};
bool found(int x, int y, int xq, int yq, int tiles[2]) {
    //printf("king(%d %d) Quenn(%d %d)\n", x, y, xq, yq);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (x + steps[i] * tiles[0] == xq && y + steps[j] * tiles[1] == yq) return true;
            if (x + steps[i] * tiles[1] == xq && y + steps[j] * tiles[0] == yq) return true;
        }
    }
    return false;
}

int main(void) {
    int t;

    scanf("%d", &t);

    int tiles[2];
    int xk, yk;
    int xq, yq;

    while (t--) {
        scanf("%d %d", &tiles[0], &tiles[1]);
        scanf("%d %d", &xk, &yk);
        scanf("%d %d", &xq, &yq);

        int sum = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (found(xk + steps[i] * tiles[0], yk + steps[j] * tiles[1], xq, yq, tiles)) sum++;
                if (found(xk + steps[i] * tiles[1], yk + steps[j] * tiles[0], xq, yq, tiles)) sum++;
            }
        }
        printf("%d\n", tiles[0] == tiles[1] ? sum/2:sum);
    }
}