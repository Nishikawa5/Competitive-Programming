#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    int tcase;
    int heights[20];

    scanf("%d", &n);

    while (n--) {
        scanf("%d", &tcase);

        for (int i = 0; i < 20; i++) {
            scanf("%d", &heights[i]);
        }

        // do insertion sort
        int totalsum = 0;
        for (int i = 1; i < 20; i++) {
            // i-th element selected
            int j = i;
            while (j > 0 && heights[j - 1] > heights[j]) {
                totalsum++;
                int temp = heights[j - 1];
                heights[j - 1] = heights[j];
                heights[j] = temp;
                j--;
            }
        }

        printf("%d %d\n", tcase, totalsum);
    }
}