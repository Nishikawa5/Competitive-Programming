#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int heights[5];
    int height;

    scanf("%d", &height);
    scanf("%d %d %d %d %d", &heights[0], &heights[1], &heights[2], &heights[3], &heights[4]);

    int maxBlocks[height + 1] = {0};

    for (int i = 0; i < 5; i++) {
        if (heights[i] <= height) {
            maxBlocks[heights[i]] = 1;
        }
    }

    for (int i = 1; i <= height; i++) {
        bool flag = false;
        for (int k = 0; k < 5; k++) {
            if (i - heights[k] > 0) {
                if (maxBlocks[i] < maxBlocks[i - heights[k]]) {
                    maxBlocks[i] = maxBlocks[i - heights[k]];
                    flag = true;
                }
            } 
        }
        if (flag) maxBlocks[i]++;
    }

    if (maxBlocks[height] == 0) {
        printf("Impossible\n");
    } else {
        int cur = maxBlocks[height];
        int curi = height;

        unordered_map <int, int> map;

        while (cur != 1) {
            int maxrm = INT_MIN;
            int maxback = INT_MIN;
            for (int k = 0; k < 5; k++) {
                if (curi - heights[k] > 0) {
                    if (maxrm < maxBlocks[curi - heights[k]] || 
                    (maxback < heights[k] && maxBlocks[curi - heights[k]] == maxrm)) {

                        maxrm = maxBlocks[curi - heights[k]];
                        maxback = heights[k];
                    }
                } 
            }
            map[maxback]++;
            curi -= maxback;
            cur--;
        }
        map[curi]++;

        for (int i = 0; i < 5; i++) {
            int maxfreq = 0;
            int maxheight = INT_MAX;
            for (int k = 0; k < 5; k++) {
                if (maxfreq < map[heights[k]] || 
                    (maxheight > heights[k] && map[heights[k]] == maxfreq)) {
                    
                    maxfreq = map[heights[k]];
                    maxheight = heights[k];
                }
            }
            if (maxfreq == 0) break;

            printf("%d ", maxheight);
            map[maxheight] = INT_MIN;
        }
    }
}