#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isBetween(char c) {
    return c >= '2' && c <= '9';
}

// hard to understand problem "piles"
int whatisthecard(void) {
    int T;
    char card[52][3];



    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int end = 26;

        for (int j = 0; j < 52; j++) {
            scanf(" %s", card[j]);
        }

        int value;
        int tot = 0;
        for (int j = 0; j < 3; j++) {
            if (isBetween(card[end][0])) value = card[end][0] - '0';
            else if (isBetween(card[end][1])) value = card[end][1] - '0';
            else value = 10;

            end -= (10 - value) + 1;
            tot += value;
        }
        if (tot > end) tot += 26 - end;
        printf("Case %d: %s\n", i, card[tot - 1]);
    }
}