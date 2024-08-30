#include <bits/stdc++.h>
using namespace std;

int main() {
    string N, M;
    cin >> N >> M;

    if (N == "0") {
        cout << 0 << endl;
        return 0;
    }

    int last_N = N.size() - 1;
    int last_M = M.size() - 1;
    while (last_N != 0 && last_M != 0 && N[last_N] == M[last_M]) {
        last_N--; last_M--;
    }

    if (M.size() > N.size()) {
        cout << "0.";
        for (int i = 0; i < M.size() - N.size() - 1; i++) {
            cout << '0';
        }
        for (int i = 0; i < last_M; i++) {
            cout << N[i];
        }
    } else {
        for (int i = 0; i < last_N - last_M + 1; i++) {
            cout << N[i];
        }
        if (last_M >= 1) {
            cout << '.';
        }
        for (int i = last_N - last_M + 1; i <= last_N; i++) {
            cout << N[i];
        }
    }
    
}