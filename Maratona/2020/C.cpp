#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    vector<int> copos(n);
    int total = 0;
    for (auto &c: copos) {
        cin >> c;
        total += c;
    }
 
    int fora = 0;
    int media = total / n;
    for (auto &c: copos) {
        c -= media;
    }
 
    // horario
    auto f = [&](vector<int> copos) {
        long long rst = 0;
        int carregando = 0;
        for (auto &c: copos) {
            rst += carregando;
            if (c > 0) {
                carregando += c;
                c = 0;
            } else if (c < 0) {
                if (carregando > -c) {
                    carregando += c;
                    c = 0;
                } else if (carregando > 0) {
                    c += carregando;
                    carregando = 0;
                }
            }
        }
 
        for (auto &c: copos) {
            rst += carregando;
            if (c > 0) {
                carregando += c;
                c = 0;
            } else if (c < 0) {
                if (carregando > -c) {
                    carregando += c;
                    c = 0;
                } else if (carregando > 0) {
                    c += carregando;
                    carregando = 0;
                }
            }
        }
        return rst;
    };
 
    vector<int> clone(n);
    for (int i = n - 1; i >= 0; i--) {
        clone[(n - 1) - i] = copos[i];
    }
 
    cout << min(f(copos), f(clone)) << endl;
}