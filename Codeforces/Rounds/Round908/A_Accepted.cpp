#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
If someone wins, then the last round winner is the winner

so we have to verify if there's a way to the last round winner win the game starting from left.

We don't have to verify because every input is a valid game
*/


int main(void) {
    short int t;
    short int n;
    char *wins = (char *) malloc(sizeof(char) * 21);

    char winner;

    scanf("%hd", &t);
    getchar();

    for (int i = 0; i < t; i++) {
        scanf("%hd", &n);
        getchar();
        scanf("%s", wins);

        printf("%c\n", wins[n - 1]);
    }
}