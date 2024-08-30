#include <bits/stdc++.h>
using namespace std;

int main() {
    int maxT = (int) 2e5 + 1;
    int n, x;
    cin >> n >> x;

    vector<bool> intervalos(maxT, false);
    while (n--) {
        int comeco, prox;
        cin >> comeco >> prox;

        for (int i = 0; i <= prox; i++) {
            intervalos[comeco + i] = true;
        }
    }

    int min_col = INT_MAX;
    int min_start = 0;
    vector<int> dp(maxT);
    for (int i = maxT - 1; i >= 0; i--) {
        // quantas atividades ja houveram colisoes?
        if (i + x >= maxT) {
            dp[i] = 0;
        } else {
            dp[i] = dp[i + x];
        }
        // esse i esta no intervalo de colisao?
        dp[i] += intervalos[i];

        // ela pode comecar agora?
        if (i <= 60 * 8) {
            // verifica se e minimo
            if (dp[i] <= min_col) {
                min_start = i;
                min_col = dp[i];
            }
        }
    }
    cout << min_start << " " << min_col << endl;
}