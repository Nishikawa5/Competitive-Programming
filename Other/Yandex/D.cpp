#include <bits/stdc++.h>
using namespace std;

/*
interactive problem:
ask if the height is ok or wet, find the N < M / 2
*/

void ask(long long height) {
    cout << height << endl;
}

long long first_true(long long lo, long long hi, function<bool(long long)> f) {
    hi++;

    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;

        if (f(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

void solve() {
    string ans;
    long long height = 1;

    ask(height);
    cin >> ans;

    if (ans == "ok") {
        cout << "! 1" << endl;
        return;
    }

    long long max_height = 1000000000000000000;
    while (ans == "wet" && height * 2 <= max_height) {
        height *= 2;
        ask(height);
        cin >> ans;
    }

    if (height * 2 > max_height && ans == "wet") {
        height = max_height;
    }

    // "ok" is between height and height / 2
    // get the first true
    long long N = first_true(height / 2, height, [&](long long curr_height) {
        ask(curr_height);
        cin >> ans;

        return ans == "ok";
    });

    cout << "! " << N << endl;
}

int main() {
    int tc = 1;

    while (tc--) {
        solve();
    }
    return 0;
}