#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <iostream>

using namespace std;

#define usi unsigned short int
#define uc unsigned char

int main(void) {
    int swathers, stages;

    scanf("%d %d", &swathers, &stages);
    int times[swathers][stages];

    for (int i = 0; i < swathers; i++) {
        for (int j = 0; j < stages; j++) {
            scanf("%d", &times[i][j]);
        }
    }

    for (int i = 1; i < swathers; i++) {
        times[i][0] += times[i - 1][0];
    }

    for (int j = 1; j < stages; j++) {
        times[0][j] += times[0][j - 1];
    }

    for (int i = 1; i < swathers; i++) {
        for (int j = 1; j < stages; j++) {
            /*
            We compare the left and up because both of them must be complete
            to do this stage. So we get the time that took most time to sum
            */
            times[i][j] += max(times[i - 1][j], times[i][j - 1]);
        }
    }

    printf("%d", times[0][stages - 1]);
    for (int i = 1; i < swathers; i++) {
        printf(" %d", times[i][stages - 1]);
    }
    printf("\n");
}


















/*

Consider only the earliest accepted solution
*/

int teamss(void) {
    short int n;
    short int t;
    short int m;

    short int time;
    short int teamID;
    char problem;

    bool **solved;
    short int *times; // store the max time of the problem
    short int *teams; // store which team solved the problem


    scanf("%hd %hd %hd", &n, &t, &m);

    solved = (bool **) malloc(sizeof(bool *) * n);
    teams = (short int *) malloc(sizeof(short int) * n);
    times = (short int *) malloc(sizeof(short int) * n);
    for (int i = 0; i < n; i++) {
        solved[i] = (bool *) malloc(sizeof(bool) * t);
        teams[i] = -1;
        times[i] = -1;
        memset(solved[i], 0, sizeof(bool) * t);
    }

    while(m--) {
        scanf("%hd %hd", &time, &teamID);
        getchar();
        problem = getchar();
        getchar();
        if (getchar() == 'Y') {
            // Yes
            if (!solved[problem - 'A'][teamID - 1]) {
                solved[problem - 'A'][teamID - 1] = true;
                
                if (times[problem - 'A'] <= time) {
                    times[problem - 'A'] = time;
                    teams[problem - 'A'] = teamID;
                }
            }

            for (int i = 0; i < 3; i++) getchar();
        } else {
            // No
            getchar();
            getchar();
        }
    }

    for (int i = 0; i < n; i++) {
        if (teams[i] != -1) {
            printf("%c %d %d\n", 'A' + i, times[i], teams[i]);
        } else {
            printf("%c - -\n", 'A' + i);
        }
    }
}































/*
first hate second,  second third and so on
*/

void copyKingdom(usi ***kingdom, usi k, usi R, usi C) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            kingdom[k % 2][i][j] = kingdom[(k + 1) % 2][i][j];
        }
    }
}

bool inInterval(usi n, usi RC) {
    return n >= 0 && n < RC;
}

void printKingdom(usi ***kingdom, usi k, usi R, usi C) {
    for (int i = 0; i < R; i++) {
        printf("%hd", kingdom[k % 2][i][0]);
        for (int j = 1; j < C; j++) {
            printf(" %hd", kingdom[k % 2][i][j]);
        }
        printf("\n");
    }
}
/*
easy to interpret and to implement
we need to make two arrays because we change instantaneously
we could make an array to store the rivals
*/
int Brothers(void) {
    usi N; // heirs
    usi R, C; // dimensions
    usi K; // battles

    short int border[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};


    usi ***kingdom = (usi ***) malloc(sizeof(usi **) * 2);
    kingdom[0] = (usi **) malloc(sizeof(usi *) * 100);
    kingdom[1] = (usi **) malloc(sizeof(usi *) * 100);
    for (int i = 0; i < 100; i++) {
        kingdom[0][i] = (usi *) malloc(sizeof(usi) * 100);
        kingdom[1][i] = (usi *) malloc(sizeof(usi) * 100);
    } 

    while (scanf("%hu %hu %hu %hu", &N, &R, &C, &K) != EOF && N) {
        usi temp;
        usi k = 0;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                scanf("%hu", &temp);
                kingdom[0][i][j] = temp;
                kingdom[1][i][j] = temp;
            }
        }
        for (int n = 0; n < K; n++) {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    for (int m = 0; m < 4; m++) {
                        if (inInterval(i + border[m][0], R) && inInterval(j + border[m][1], C)) {
                            if (kingdom[k % 2][i + border[m][0]][j + border[m][1]] - kingdom[k % 2][i][j] == 1 ||
                                (kingdom[k % 2][i][j] - kingdom[k % 2][i + border[m][0]][j + border[m][1]] == N - 1)) {
                                kingdom[(k + 1) % 2][i + border[m][0]][j + border[m][1]] = kingdom[k % 2][i][j];
                            }
                        }
                    }
                }
            }
            copyKingdom(kingdom, k, R, C);
            k++;
        }

        printKingdom(kingdom, k, R, C);

    }
}








/*
Cells that have common side, we make a new grid by f(g)

Easy to implement, hard to interpret
but i had getchar(); error of input, careful when using that

scanf("%1d", &x); get only one digit in input
*/

short steps[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

bool checkgrid(int **grid) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == 1) return true;
        }
    }
    return false;
}

void changegrid(int **grid) {
    int sum;
    int tempgrid[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum = 0;
            for (int k = 0; k < 4; k++) {
                short x1 = steps[k][0] + i;
                short y1 = steps[k][1] + j;

                if (x1 >= 0 && x1 < 3 && y1 >= 0 && y1 < 3) {
                    if (grid[x1][y1]) {
                        sum++;
                    }
                }
                tempgrid[i][j] = sum % 2;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = tempgrid[i][j];
        }
    }
}

int gridsucessor(void) {
    int T;
    int **grid = (int **) malloc(sizeof(int *) * 3);
    for (int i = 0; i < 3; i++) {
        grid[i] = (int *) malloc(sizeof(int) * 3);
    }

    scanf("%d", &T);

    while(T--) {
        int h = -1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                scanf("%1d", &grid[i][j]);
            }
        }

        while (checkgrid(grid)) {
            h++;
            changegrid(grid);
        }

        printf("%d\n", h);
    }
}




















/*
Use the transpose of matrix to make it faster?

*/

bool isEmpty(char **grid, int col, int N) {
    for (int i = 0; i < N; i++) {
        if (grid[i][col] == '$') {
            return false;
        }
    }
    return true;
}

int Dance(void) {
    short N, M;
    int num = 1;
    char **grid;

    scanf("%hd %hd", &N, &M);
    getchar();

    grid = (char **) malloc(sizeof(char *) * N);
    for (int i = 0; i < N; i++) {
        grid[i] = (char *) malloc(sizeof(char) * M);
        for (int j = 0; j < M; j++) {
            grid[i][j] = getchar();
        }
        getchar();
    }

    for (int j = 0; j < M; j++) {
        if (isEmpty(grid, j, N)) num++;
    }

    printf("%d\n", num);
}