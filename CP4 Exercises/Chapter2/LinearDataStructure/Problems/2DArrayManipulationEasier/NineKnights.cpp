#include <bits/stdc++.h>

using namespace std;

int main(void) {
    char grid[5][5];
    int steps[4][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}};
    int stepsign[2] = {-1, 1};

    int knightcount = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            grid[i][j] = getchar();
            if (grid[i][j] == 'k') knightcount++;
        }
        getchar();
    }
    if (knightcount != 9) {
        printf("invalid\n");
        return 0;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (grid[i][j] == 'k') {
                // check if attacks another knight
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l < 4; l++) {
                        int attacki = i + steps[l][0] * stepsign[k];
                        int attackj = j + steps[l][1] * stepsign[k];
                        if (0 <= attacki && attackj < 5 &&
                            0 <= attackj && attackj < 5) {
                            
                            if (grid[attacki][attackj] == 'k') {
                                printf("invalid\n");
                                return 0;
                            }
                        }
                    }
                }

            }
        }
    }
    printf("valid\n");
}