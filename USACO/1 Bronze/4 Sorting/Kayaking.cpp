#include <bits/stdc++.h>
using namespace std;

/* 
Didn't saw that we had to test for every pair
*/
int main() {
    int n;
    cin >> n;

    n *= 2;
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    sort(weights.begin(), weights.end());

    int mindiff = INT_MAX;
    vector<int> minusplus{-1, 1};
    // try deleting every pair and check the total difference for each
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sign = 0;
            int currdiff = 0;
            for (int k = 0; k < n; k++) {
                if (k != i && k != j) {
                    currdiff += weights[k] * minusplus[(sign++) % 2]; 
                }
            }
            mindiff = min(mindiff, currdiff);
        }
    }
    cout << mindiff << endl;
}