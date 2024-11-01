#include <bits/stdc++.h>

using namespace std;

/*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    return 0;


BE VERY CAREFUL WITH getchar();

*/

void printVector(vector <char> chr) {
    if (chr.empty()) return;
    printf("%c", chr[0]);
    for (int i = 1; i < chr.size(); i++) {
        printf(" %c", chr[i]);
    }
    printf("\n");
}

int main(void) {
    int n;
    int steps[3] = {-1, 0, 1};
    scanf("%d", &n);
    getchar();
    getchar();

    char **grid = (char **) malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++) {
        grid[i] = (char *) malloc(sizeof(char) * n);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = getchar();
            getchar();
        }
        getchar();
    }

    int curr[2] = {0, 0};
    bool destination = false;
    bool first = false;
    int currtemp[2] = {0, 0};
    while (!destination) {
        vector <char> close;
        grid[curr[0]][curr[1]] = 'M';
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if ((0 <= curr[0] + steps[i] && curr[0] + steps[i] < n) && 
                    (0 <= curr[1] + steps[j] && curr[1] + steps[j] < n)) {
                    char temp = grid[curr[0] + steps[i]][curr[1] + steps[j]];

                    if (temp == 'D') destination = true;
                    if (temp == 'L' || temp == 'T' || temp == 'W' || temp == 'S') {
                        close.push_back(temp);
                    } else if (temp == 'R') {
                        currtemp[0] = curr[0] + steps[i];
                        currtemp[1] = curr[1] + steps[j];
                    }
                }
            }
        }
        curr[0] = currtemp[0];
        curr[1] = currtemp[1];
        if (first && !close.empty()) {
            sort(close.begin(), close.end());
            printVector(close);
        }
        first = true;
    }
    printf("DESTINATION\n");
}