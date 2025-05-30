#include <bits/stdc++.h>
using namespace std;

void solve() {
    int MOD = 998244353;

    int num_problems, num_contest;
    cin >> num_problems >> num_contest;
    
    map<int, int> problems;

    for (int i = 0; i < num_problems; i++) {
        int p;
        cin >> p;

        problems[p]++;
    }


    vector<pair<int, int>> problems_vec(problems.begin(), problems.end());
    int unique_difficulty_count = problems_vec.size();

    // how many ways can we pick the numbers in problems so that we have
    // all different numbers

    vector<vector<long long>> dp(num_contest+1, vector<long long>(unique_difficulty_count+1));
    


    // a contest with dp[number of problems][problems used] = number of possible contests
    // we have like _ _ _ ... _ _ problems in the context with types_used problems used
    // we want _ _ _ ... _ _ _ (1 more problem than before) with types_used+1 problems used
    // so we can just add 1 of the new type of types_used for each problem we had before
    // so
    // dp[nop][problems used] = dp[nop][problems used - 1] + dp[nop-1][problems used-1] * problems[p[j]]
    long long cumulative_count = 0;
    for (int j = 1; j <= unique_difficulty_count; j++) { 
        cumulative_count = (cumulative_count + problems_vec[j-1].second);
        cumulative_count %= MOD; 
        dp[1][j] = cumulative_count;
    }

    for (int contest_items = 2; contest_items <= num_contest; contest_items++) {
        for (int types_considered = contest_items; types_considered <= unique_difficulty_count; types_considered++) {
            dp[contest_items][types_considered] = dp[contest_items][types_considered-1] +
                                                 1LL * dp[contest_items-1][types_considered-1] * (problems_vec[types_considered-1].second);
            dp[contest_items][types_considered] %= MOD;
        }
    }
    cout << dp[num_contest][unique_difficulty_count] << endl;
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
