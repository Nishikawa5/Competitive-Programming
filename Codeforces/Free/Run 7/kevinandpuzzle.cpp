#include <bits/stdc++.h>
using namespace std;

int MOD = 998244353;

void solve() {
    int n;
    cin >> n;

    vector<int> classmates(n);
    for (auto &c: classmates) {
        cin >> c;
    }

    // if is lie   => liar
    //       truth => honest/liar
    // no adjacent liars

    // 2 cases:
    // ai truth => there are ai liars
    // ai lie   => there are ai-1 liars, since 2 cant be adjacent
    // how many games where i tells the/a truth/lie
    vector<int> dp_truth(n);
    vector<int> dp_lie(n);
    // 0 says the truth
    dp_truth[0] = (classmates[0] == 0);
    // 0 lies
    dp_lie[0] = 1;

    if (n == 1) {
        cout << dp_truth[0] + dp_lie[0] << endl;
        return;
    }


    // 1 says the truth
    if (classmates[1] == 0) {
        dp_truth[1] += dp_truth[0];
    }
    if (classmates[1] == 1) {
        dp_truth[1] += dp_lie[0];
    }
    // 1 lies
    dp_lie[1] = dp_truth[0];
    for (int i = 2; i < n; i++) {
        // ai truth => i+1 is either a liar or honest
        //             assume honest => ai == ai+1
        //             assume liar   => ai + 1 == ai+2
        // assume this classmate is telling the truth, possible iff 
        // ai-1 is telling the truth => ai == ai-1
        // ai-1 is lying => ai == ai-2 + 1

        if (classmates[i] == classmates[i - 1]) {
            // the case ai is telling the truth and ai-1 is also telling the truth
            dp_truth[i] += dp_truth[i - 1];
        }
        if (classmates[i] == classmates[i - 2] + 1) {
            // the case ai is telling the truth and ai-1 is lying, so ai-2 is telling the truth
            dp_truth[i] += dp_lie[i - 1];
        }
        dp_truth[i] %= MOD;


        // ai lie   => i-1 and i+1 are honest => ai-1 + 1 == ai+1
        // assume this classmate is telling a lie, possible iff i-1 is telling the truth
        // how many possible games of i-1 telling the truth?
        dp_lie[i] = dp_truth[i - 1];
    }
    cout << (dp_lie[n - 1] + dp_truth[n - 1]) % MOD << endl;
}


int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}