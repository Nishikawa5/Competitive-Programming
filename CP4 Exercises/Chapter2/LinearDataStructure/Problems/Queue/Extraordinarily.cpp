#include <bits/stdc++.h>

using namespace std;

/*
all student are listening
awaken - listen and count
strictly more sleep, sleeps for b minutes
otherwise he keep awaken for a minutes

*/
int main(void) {
    int n;
    int t = 0;
    int awaken, sleeping, initial;

    while ((scanf("%d", &n) != EOF) && n != 0) {
        t++;
        queue<int> students[n]; // 1 awaken 0 sleeping
        pair<int, int> info[n];
        int slp = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &awaken, &sleeping, &initial);
        
            info[i].first = awaken;
            info[i].second = sleeping;
        }

    }
}