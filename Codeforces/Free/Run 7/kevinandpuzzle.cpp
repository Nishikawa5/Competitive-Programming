#include <bits/stdc++.h>
using namespace std;

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
    dp_truth[0] = (classmates[0] == 0);
    dp_lie[0] = 1;

    dp_truth[1] = dp_truth[0];
    if (classmates[1] == 1) {
        dp_truth[1] += dp_lie[0];
    }
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
        if (classmates[i] == classmates[i - 2]) {
            dp_truth[i] += dp_lie[i - 2];
        }


        // ai lie   => i-1 and i+1 are honest => ai-1 + 1 == ai+1
        // assume this classmate is telling a lie, possible iff i-1 is telling the truth
        // how many possible games of i-1 telling the truth?
        dp_lie[i] = dp_truth[i - 1];
    }
    cout << dp_lie[n - 1] + dp_truth[n - 1] << endl;
}


int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}