#include <bits/stdc++.h>
using namespace std;

int sum_digits(int n) {
    int rst = 0;
    while (n) {
        rst += n % 10;
        n /= 10;
    }
    return rst;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    const int MAX_POLLENS = (int) 1e6 + 1;

    int pollens, position;
    cin >> pollens >> position;
    vector<int> freq(MAX_POLLENS);

    for (int i = 0; i < pollens; i++) {
        int pollen;
        cin >> pollen;
        freq[pollen]++;
    }

    int ans = 0;
    for (int i = MAX_POLLENS - 1; i >= 0; i--) {
        // from MAX_POLLENS - 1 to 0 because bees always choose the biggest pollen
        // the next freq[i] bees goes to this i-th pollen
        position -= freq[i];
        // the pollens eaten now are next_pollen[i]
        freq[i - sum_digits(i)] += freq[i];
        freq[i] = 0;    // all of them were eaten

        if (position <= 0) {
            // the bee ate this pollen
            ans = sum_digits(i);
            break;
        }
    }
    cout << ans << endl;
}