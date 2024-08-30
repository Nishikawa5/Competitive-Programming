#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/*
We can binary search on k
lets maintain the current position and make an interval of where we can go
*/

bool check(int intervals[200000][2], int n, int k) {
    int ll = 0;
    int rr = 0;

    for (int i = 0; i < n; i++) {
        ll = max(ll - k, intervals[i][0]);
        rr = min(rr + k, intervals[i][1]);
        if (ll > rr) return false;
    }
    return true;
}

int main(void) {
    int t;
    int n;
    int intervals[200000][2];

    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &intervals[i][0], &intervals[i][1]);
        }

        // find the best k
        unsigned int low = -1;
        unsigned int high = 1000000000;

        while (high - low > 1) {
            unsigned int mid = low + (high - low) / 2;
            if (check(intervals, n, mid)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        printf("%u\n", high);
    }
}