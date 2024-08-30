#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int sizes[4];
    int before, after;

    scanf("%d %d %d %d", &sizes[0], &sizes[1], &sizes[2], &sizes[3]);
    scanf("%d %d", &before, &after);

    int maxRooms[before + after + 1] = {0};

    for (int i = 0; i < 4; i++) {
        if (sizes[i] <= before + after) {
            maxRooms[sizes[i]] = 1;
        }
    }

    for (int i = 1; i <= before + after; i++) {
        bool flag = false;
        for (int k = 0; k < 4; k++) {
            if (i - sizes[k] > 0) {
                if (maxRooms[i] < maxRooms[i - sizes[k]]) {
                    maxRooms[i] = maxRooms[i - sizes[k]];
                    flag = true;
                }
            } 
        }
        if (flag) maxRooms[i]++;
    }

    int cur = maxRooms[before];
    int curi = before;

    unordered_map <int, int> map;

    while (cur != 1) {
        int maxrm = INT_MIN;
        int maxback = INT_MIN;
        for (int k = 0; k < 4; k++) {
            if (curi - sizes[k] > 0) {
                if (maxrm < maxRooms[curi - sizes[k]] || 
                   (maxback < sizes[k] && maxRooms[curi - sizes[k]] == maxrm)) {

                    maxrm = maxRooms[curi - sizes[k]];
                    maxback = sizes[k];
                }
            } 
        }
        map[maxback]++;
        curi -= maxback;
        cur--;
    }
    map[curi]++;

    // create a function if have time
    cur = maxRooms[before + after];
    curi = before + after;

    unordered_map <int, int> map2;

    while (cur != 1) {
        int maxrm = INT_MIN;
        int maxback = INT_MIN;
        for (int k = 0; k < 4; k++) {
            if (curi - sizes[k] > 0) {
                if (maxrm < maxRooms[curi - sizes[k]] || 
                   (maxback < sizes[k] && maxRooms[curi - sizes[k]] == maxrm)) {

                    maxrm = maxRooms[curi - sizes[k]];
                    maxback = sizes[k];
                }
            } 
        }
        map2[maxback]++;
        curi -= maxback;
        cur--;
    }
    map2[curi]++;

    printf("%d ", map[sizes[0]] - map2[sizes[0]]);
    for (int i = 1; i < 4; i++) {
        printf("%d ", map[sizes[i]] - map2[sizes[i]]);
    }
}