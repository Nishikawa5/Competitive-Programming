#include <bits/stdc++.h>

using namespace std;

bool isPrime(long n) {
    if (n <= 1) return false;
    if (n == 2) return true;

    long root = sqrt(n);

    for (int i = 3; i <= root; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(){
    int tc;
    cin >> tc;
    vector<long> primes;
    primes.push_back(2);
    primes.push_back(3);
    for(int a0 = 0; a0 < tc; a0++){
        long n;
        cin >> n;
        // starts with last prime
        long i = primes[primes.size() - 1] + 2;
        while (i <= n) {
            if (isPrime(i)) {
                primes.push_back(i);
            }
            i += 2;
        }

        long sum = 0;
        for (int k = 0; k < primes.size() && primes[k] <= n; k++) {
            sum += primes[k];
        }
        cout << sum << endl;
    }
    return 0;
}