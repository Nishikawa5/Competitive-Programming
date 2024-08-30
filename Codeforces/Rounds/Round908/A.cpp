#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
If someone wins, then the last round winner is the winner

so we have to verify if there's a way to the last round winner win the game starting from left.

*/

/* check if the last is the winner for given X */
bool checkX(int X, char *wins) {
    int i = 1;
    int seq[2] = {1, 0};
    int win[2] = {0, 0};
    int pointer = 0;

}

int main(void) {
    short int t;
    short int n;
    char *wins = (char *) malloc(sizeof(char) * 21);

    char winner;
    short int winA;
    short int winB;
    short int *sets = (short int *) malloc(sizeof(short int) * 20);

    scanf("%hd", &t);
    getchar();

    for (int i = 0; i < t; i++) {
        scanf("%hd", &n);
        getchar();
        scanf("%s", wins);

        winner = wins[n - 1];
        memset(sets, 0, sizeof(short int) * 20);
        // check if there's a way to winner win

        int idx = 0;
        sets[0] = 1;
        for (int k = 1; k < n; k++) {
            if (wins[i] != wins[i - 1]) idx++;
            sets[idx]++;
        }
    }
}