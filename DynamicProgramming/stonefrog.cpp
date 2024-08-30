#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N;
    scanf("%d", &N);

    int c, c1, c2;
    int x, x1, x2;
    c = c1 = c2 = 0;
    scanf("%d", &x);
    x1 = x2 = x;
    for (int i = 1; i < N; i++) {
        scanf("%d", &x);

        int diff1 = abs(x - x1);
        int diff2 = abs(x - x2);
        c = min(diff1 + c1, diff2 + c2);

        x2 = x1;
        x1 = x;
        c2 = c1;
        c1 = c;
    }
    printf("%d\n", c);
}