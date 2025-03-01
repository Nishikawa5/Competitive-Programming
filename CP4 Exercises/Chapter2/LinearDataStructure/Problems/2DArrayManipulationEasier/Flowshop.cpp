#include <bits/stdc++.h>

using namespace std;

/*
Workers at each stage j works only swather at a time

We have to do work in parallel
*/
int main(void) {
    int N; // Swathers offered
    int M; // Stages

    scanf("%d %d", &N, &M);
    int times[N][M];
    int currtime = 0;   // initially 0
    int machine[M] = {1}; // the machine we are at the moment
    int extratime;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &times[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        // ->
        for (int j = 0; j < M; j++) {
            // v
            if (times[i][j] != 0) {
                currtime += times[i][j];
                // do the work in parallel
                for (int m = 0; m < j; m++) {
                    // v
                    extratime = times[i][j];
                    for (int k = machine[m]; k < N; k++) {
                        // ->
                        if (times[k][m] <= extratime) {
                            extratime -= times[k][m];
                            times[k][m] = 0;

                            machine[m] = k + 1;
                        } else {
                            times[k][m] -= extratime;
                            machine[m] = k;
                            break;
                        }
                    }
                }
                times[i][j] = 0;
            }
        }
        printf("%d ", currtime);
    }
    printf("\n");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", times[i][j]);
        }
        printf("\n");
    }

}