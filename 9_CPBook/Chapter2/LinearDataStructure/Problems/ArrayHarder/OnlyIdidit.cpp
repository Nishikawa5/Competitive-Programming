#include <bits/stdc++.h>

using namespace std;


/*
one friend try to solve the problem none of other 2 have solved
which friend did it
*/
int main(void) {
    int tc;

    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        int ns;

        int count[10001];
        memset(count, 0, sizeof(count));

        int *problems[3];
        for (int j = 0; j < 3; j++) {
            int size;
            cin >> size;
            problems[j] = (int *) malloc(sizeof(int) * (size + 1));
            problems[j][0] = size;
        
            for (int k = 1; k <= size; k++) {
                cin >> problems[j][k];
                count[problems[j][k]]++;
            }
        }

        vector<vector<int>> solved(3);
        int maxSolved = 0;
        for (int j = 0; j < 3; j++) {
            int size = problems[j][0];
        
            for (int k = 1; k <= size; k++) {
                if (count[problems[j][k]] == 1) {
                    solved[j].push_back(problems[j][k]);
                    
                    maxSolved = max((int)solved[j].size(), maxSolved);
                }
            }
        }

        printf("Case #%d:\n", i);
        for (int j = 0; j < 3; j++) {
            if (solved[j].size() == maxSolved) {
                sort(solved[j].begin(), solved[j].end());
                cout << j + 1 << " " << maxSolved;
                for (int k = 0; k < maxSolved; k++) {
                    cout << " " << solved[j][k];
                }
                cout << endl;
            }
        }
    }
}