#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> potential_subsets(100002);
    vector<long long> subsetsrl(100002);
    potential_subsets[n + 1] = 0;
    subsetsrl[n + 1] = 0;
    bitset<100001> bseq;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        bseq[i] = x;
    }

    long long max_subsets = 0;
    for (int i = n; i >= 1; i--) {
        if (bseq[i] == 0) {
            potential_subsets[i] = potential_subsets[i + 1] + 1;
            subsetsrl[i] = subsetsrl[i + 1];
        } else {
            potential_subsets[i] = subsetsrl[i + 1];
            subsetsrl[i] = potential_subsets[i + 1] + 1;
        }
        max_subsets += subsetsrl[i];
    }
    cout << max_subsets << endl;
}