#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> intervalos(n);
    for (auto &p: intervalos) {
        cin >> p.first >> p.second;
        p.second += p.first;
    }

    int min_col = INT_MAX;
    int min_start = 0;
    for (int i = 0; i <= 480; i++) {
        int colisoes = 0;
        for (auto interv: intervalos) {
            int primeiro_maiorigual = max(0, (int) ceil((interv.first - i) / (float) x));
            int ultimo_maiorigual = max(0, (int) floor((interv.second - i) / (float) x));

            if (interv.first <= primeiro_maiorigual * x + i && primeiro_maiorigual * x + i <= interv.second) {
                colisoes += ultimo_maiorigual - primeiro_maiorigual + 1;
            }
        }
        if (colisoes < min_col) {
            min_col = colisoes;
            min_start = i;
        }
    }
    cout << min_start << " " << min_col << endl;
}