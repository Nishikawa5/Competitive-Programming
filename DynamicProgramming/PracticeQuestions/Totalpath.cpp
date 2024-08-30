#include <bits/stdc++.h>

using namespace std;

int min5(int a, int b, int c, int d, int e) {
    int minimum = min(a, b);
    minimum = min(minimum, c);
    minimum = min(minimum, d);
    return min(minimum, e);
}
/*
We can approach this problem by dividing in 4 cases

*/
int minDist[100][100] = {0};
int minMovDP(pair<int, int> source, pair<int, int> destination) {
    if (source == destination) {
        return 0;
    }
    if (source.first > destination.first || source.second > destination.second) {
        return INT_MAX;
    }

    return min5(minMov(make_pair(source.first + 1, source.second), destination),
                minMov(make_pair(source.first, source.second + 1), destination),
                minMov(make_pair(source.first + 1, source.second + 1), destination),
                minMov(make_pair(source.first + 1, source.second + 2), destination),
                minMov(make_pair(source.first + 2, source.second + 1), destination)) + 1;
}

int minMov(pair<int, int> source, pair<int, int> destination) {
    if (source == destination) {
        return 0;
    }
    if (source.first > destination.first || source.second > destination.second) {
        return INT_MAX;
    }

    return min5(minMov(make_pair(source.first + 1, source.second), destination),
                minMov(make_pair(source.first, source.second + 1), destination),
                minMov(make_pair(source.first + 1, source.second + 1), destination),
                minMov(make_pair(source.first + 1, source.second + 2), destination),
                minMov(make_pair(source.first + 2, source.second + 1), destination)) + 1;
}











/*
Assume blocked routes are -1


*/
int numOfPaths(int x, int y) {
    int DP[x][y] = {0};

    for (int i = 0; i < x; i++) {
        DP[i][0] = 1;
    }

    for (int j = 0; j < y; j++) {
        DP[0][j] = 1;
    }

    for (int i = 1; i < x; i++) {
        for (int j = 1; j < y; j++) {
            DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
        }
    }
    return DP[x - 1][y - 1];
}


int main(void) {
    printf("%d\n", minMov(make_pair(0, 0), make_pair(15, 15)));
}