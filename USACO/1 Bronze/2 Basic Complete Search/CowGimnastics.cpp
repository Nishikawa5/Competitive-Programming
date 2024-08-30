#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int cows;
    int sessions;

    cin >> sessions >> cows;

    int rankings[sessions][cows];
    for (int i = 0; i < sessions; i++) {
        for (int j = 0; j < cows; j++) {
            cin >> rankings[i][j]; 
        }
    }

    int totalpairs = 0;
    for (int k = 0; k < cows; k++) {
        // if true then is a possible pair
        vector<bool> possiblepairs(cows, true);
        possiblepairs[k] = false;

        // mark the not possible pairs for cow 
        int currcow = k + 1;
        for (int i = 0; i < sessions; i++) {
            for (int j = 0; j < cows; j++) {
                if (rankings[i][j] == currcow) {
                    // stop. cow did better than the rest
                    break;
                }
                possiblepairs[rankings[i][j] - 1] = false;
            }
        }

        for (int i = 0; i < cows; i++) {
            if (possiblepairs[i]) {
                totalpairs++;
            }
        }
    }
    // print number of consistent pairs
    cout << totalpairs << endl;
}