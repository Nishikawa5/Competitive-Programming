#include <bits/stdc++.h>

using namespace std;

// given an integer N, precompute every prime before N
vector<long> precomputePrimes(int N) {
    vector<long> primes;
    primes.push_back(2);
    for (int i = 3; i <= N; i += 2) {
        bool isPrime = true;
        for (long prime : primes) {
            if (prime * prime > i) {
                // no larger prime factor possible
                // so i is prime
                // to convince this is true, an example is when we are
                // searching if a number is prime we just need to
                // go to sqrt(i) because if there's a multiple it must
                // be less than or equal to sqrt(i)
                break;
            }

            if (i % prime == 0) {
                // not prime
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main(void) {
    // 2000000 is the greatest
    vector<long> primes = precomputePrimes(2000000);

    int tc;
    cin >> tc;

    while (tc--) {
        int N;
        cin >> N;

        long sum = 0;
        for (int k = 0; k < primes.size() && primes[k] <= N; k++) {
            sum += primes[k];
        }
        cout << sum << endl;
    }
}