#include <bits/stdc++.h>
using namespace std;

vector<long long> get_odd_prime_factors(long long num) {
    vector<long long> factors;
    long long temp_num = num;
    for (long long d = 3; d * d <= temp_num; d += 2) {
        while (temp_num % d == 0) {
            factors.push_back(d);
            temp_num /= d;
        }
    }
    if (temp_num > 1) {
        factors.push_back(temp_num);
    }
    return factors;
}

void solve() {
    
    // a log can only be split in equal integer parts
    // so it must be a factor of the number
    // the logs will be the length/factor size and we have factor logs

    long long n, m, k;
    cin >> n >> m >> k;

    // Case 1: n is even.
    // The total nim-sum is g(m) XOR ... XOR g(m) (n times), which is 0.
    // This is a P-position (losing for the first player).

    // in other words, if n is even, the second beaver can always copy the first beaver
    // so the first beaver will eventually run out of moves
    if (n % 2 == 0) {
        cout << "Marsel" << endl;
        return;
    }

    // Case 2: n is odd.
    // The winner is determined by g(m). If g(m) > 0, Timur wins. Otherwise, Marsel wins.

    // Decompose m into 2^a * b, where b is odd.
    long long b = m;
    int a = 0;
    while (b > 0 && b % 2 == 0) {
        b /= 2;
        a++;
    }

    // Part 1: Calculate the Grundy number for the odd part `b`, assuming only odd splits.
    // This is the length of the longest chain of divisions by prime factors
    // that keeps the log length >= k.
    long long g_odd = 0;
    if (b >= k) {
        vector<long long> odd_prime_factors = get_odd_prime_factors(b);
        long long current_val = b;
        for (long long p : odd_prime_factors) {
            // To maximize the number of divisions, we always use the smallest available prime factors first.
            if (current_val / p >= k) {
                current_val /= p;
                g_odd++;
            } else {
                break;
            }
        }
    }

    // Part 2: Calculate the increments to the Grundy number from the even part (2^a).
    // An increment occurs for each power of 2 (from 2^1 to 2^a) that allows a split by 2.
    // A split by 2 from 2^i * b is possible if (2^i * b) / 2 >= k, i.e., 2^(i-1) * b >= k.
    long long num_increments = 0;
    if (b > 0) { // Avoid division by zero if m was initially 0.
        // We need to find how many i in [1, a] satisfy 2^(i-1) * b >= k.
        // This is equivalent to 2^(i-1) >= ceil(k/b).
        long long threshold = (k + b - 1) / b;
        
        long long power_of_2 = 1;
        int first_valid_i = -1;
        for (int i = 1; i <= a; ++i) {
            if (power_of_2 >= threshold) {
                first_valid_i = i;
                break;
            }
            // Check for overflow before multiplying power_of_2 by 2.
            // With a <= 30, power_of_2 fits within a 64-bit long long.
            if (power_of_2 > __LONG_LONG_MAX__ / 2) { 
                break; // Will overflow, but also certainly be >= threshold
            }
            power_of_2 *= 2;
        }

        if (first_valid_i != -1) {
            num_increments = a - first_valid_i + 1;
        }
    }

    long long grundy_m = g_odd + num_increments;

    if (grundy_m > 0) {
        cout << "Timur" << endl;
    } else {
        cout << "Marsel" << endl;
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
