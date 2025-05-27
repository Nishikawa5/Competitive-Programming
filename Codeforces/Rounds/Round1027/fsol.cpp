#include <bits/stdc++.h>
using namespace std;

int get_min_op(int num, int interval) {
    if (num == 1) {
        return 0;
    }

    // get the factors
    vector<int> factors;
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            factors.push_back(i);
            factors.push_back(num/i);
        }
    }

    sort(factors.begin(), factors.end());

    // knapsack dp
    // number of factors <= interval needed for (number i) == factor[i]
    vector<int> dp(factors.size(), INT_MAX-1);
    // factor[0] == 1 and 1 need 0 factors
    dp[0] = 0;

    for (int i = 1; i < factors.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (factors[i] / factors[j] > interval) {
                // we start from the biggest factor less than factor i, 
                // so if it is greater than interval, there's no other smaller after that
                break;
            }

            if (factors[i] % factors[j] == 0) {
                // since it is divisible, we can just multiply their division, which is <= interval
                // i*(factors[i]/factors[j]) == factors[j]
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    return (dp[factors.size()-1] == INT_MAX-1) ? -1 : dp[factors.size()-1];
}


void solve() {
    int start, interval, target;
    cin >> start >> target >> interval;


    int multiple = gcd(start, target);
    int need = target/multiple;
    int erase = start/multiple;

    int min_op_mult = get_min_op(need, interval);
    int min_op_div = get_min_op(erase, interval);

    if (min_op_div != -1 && min_op_mult != -1) {
        cout << min_op_mult + min_op_div << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
    return 0;
}
