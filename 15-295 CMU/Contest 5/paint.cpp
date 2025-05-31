#include <bits/stdc++.h>
using namespace std;


void solve() {
    long long x;
    cin >> x;

    if (x == 1) {
        cout << 1 << endl;
        return;
    }

    vector<long long> primes;

    // connect every number in prime steps

    // prime => prime colors

    // a factor that is not prime that <= n
    // so we can connect all color that uses these primes
    // this makes we use one color
    // 0 1 2 3 4 0 1 2 3 4 0 1 2 3 4 0 1 2 3 4 0 1 2 3 4 0 1 2 3 4 0 1 2 3 4
    // 0 1 2 3 4 5 6 0 1 2 3 4 5 6 0 1 2 3 4 5 6 0 1 2 3 4 5 6 0 1 2 3 4 5 6


    long long tempx = x;
    

    if (x % 2 == 0) {
        primes.push_back(2);
        while (tempx % 2 == 0) {
            tempx /= 2;
        }
    }

    for (long long div = 3; div*div <= tempx; div += 2) {

        if (tempx % div == 0) {
            primes.push_back(div);

            while (tempx % div == 0) {
                tempx /= div;
            }
        }
    }

    if (tempx > 1) {
        primes.push_back(tempx);
    }

    if (primes.size() >= 2) {
        cout << 1 << endl;
    } else {
        cout << primes[0] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;

    while (tc--) {
        solve();
    }
    return 0;
}
