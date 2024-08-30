#include <bits/stdc++.h>

using namespace std;


/*
Since the algorithm below doesn't work, lets try brute force.
*/
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

int main(void) {
    // n-th prime
    long n = 10001;

    long i = 3;
    vector<long> primes;
    primes.push_back(2);
    while (primes.size() < n) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
        i += 2;
    }
    cout << primes[n - 1] << endl;
}
/*
// in hackerrank we store the value to dont keep doing same calculations
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
        while (primes.size() < n) {
            if (isPrime(i)) {
                primes.push_back(i);
            }
            i += 2;
        }

        cout << primes[n - 1] << endl;
    }
    return 0;
}
*/






/*
Sieve of Eratosthenes algorithm cost too much memory, so isnt possible to solve this problem
with it. Also we can't reuse the memory because we keep eliminating every multiple of a prime
from smallest to biggest.
*/
int Fail(void) {
    long N = 40000;
    bool isPrime[N];
    memset(isPrime, 1, sizeof(bool) * (N));

    long root = sqrt(N);

    vector<int> primes;
    for (int i = 2; i <= N; i++) {

        if (isPrime[i]) {
            primes.push_back(i);
            long j = i * i;

            while (j <= N) {
                isPrime[j] = false;
                j += i;
            }
        }
    }
    
    cout << primes.size() << " " << primes[4202] << endl;
}