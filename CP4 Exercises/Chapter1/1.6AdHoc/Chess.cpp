#include <stdio.h>
#include <stdlib.h>
#include <cmath>


// number of rooks, knights, queens and kings without attacking eachother in the board m x n
// queens always covers all the squares
// medium, was hard to see the queen cover squares
int chess(void) {
    int T;
    scanf("%d", &T);

    while (T--) {
        char piece;
        int m;
        int n;

        scanf(" %c %d %d", &piece, &m, &n);

        if (piece == 'r') printf("%d\n", ((m > n) ? (n) : (m)));
        else if (piece == 'k') printf("%d\n", (int) ceil((m * n) / 2.0));
        else if (piece == 'K') printf("%d\n", (int) (ceil(m / 2.0) * ceil(n / 2.0)));
        else if (piece == 'Q') {
            int min = ((m > n) ? (n) : (m));

            if (abs(m - n) >= 1) printf("%d\n", min);
            else printf("%d\n", min - 1);
        }
    }
}