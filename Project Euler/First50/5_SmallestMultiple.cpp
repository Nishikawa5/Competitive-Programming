#include <bits/stdc++.h>

using namespace std;


int Sol(void) {
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

    int N = 20;
    int result = 1;
    for (int i = 2; i <= N; i++) {
        // when is not div, add a prime that make it divisible
        if (result % i) {
            // not divisible, so search for prime
            int prime;
            for (int k = 0; k < primes.size(); k++) {
                if (!((result * primes[k]) % i)) {
                    prime = primes[k];
                    break;
                }
            }
            // and multiply
            result *= prime;
        }
    }
    cout << result << endl;
}

long gcd(long a, long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long lcm(long n) {
    long result = 1;

    for (long i = 1; i <= n; i++) {
        result = (result * i) / gcd(result, i);
    }
    return result;
}

int AnotherSol(void) {
    long N = 20;

    cout << lcm(20) << endl;
}

