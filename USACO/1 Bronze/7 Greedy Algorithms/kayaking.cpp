#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    n *= 2;
    vector<int> weigths(n);
    for (int i = 0; i < n; i++) {
        cin >> weigths[i]; 
    }
    sort(weigths.begin(), weigths.end());

    // choose 2 people to go solo
    int min_inst = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int curr_inst = 0;
            int signal = -1;
            for (int k = 0; k < n; k++) {
                if (k == j || k == i) {
                    continue;
                }

                curr_inst += weigths[k] * signal;
                signal *= -1;
            }
            min_inst = min(min_inst, curr_inst);
        }
    }
    cout << min_inst << endl;
}