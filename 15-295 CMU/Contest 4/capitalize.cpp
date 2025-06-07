#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long key, shift_key, caps_lock;
    cin >> key >> shift_key >> caps_lock;

    string sequence;
    cin >> sequence;

    // store the best result with and without capslock
    vector<long long> without_caps(sequence.size() + 1);
    vector<long long> with_caps(sequence.size() + 1);
    
    with_caps[0] = caps_lock;

    int curr_idx = 1;
    for (char c: sequence) {

        if (c == 'A') {
            without_caps[curr_idx] = min(
                min(with_caps[curr_idx-1] + key + caps_lock, 
                    without_caps[curr_idx-1] + shift_key),
                    with_caps[curr_idx-1] + shift_key + caps_lock
                );

            with_caps[curr_idx] = min(
                min(with_caps[curr_idx-1] + key,
                    without_caps[curr_idx-1] + caps_lock + key),
                    without_caps[curr_idx-1] + shift_key + caps_lock
                );

        } else {
            without_caps[curr_idx] = min(
                min(with_caps[curr_idx-1] + caps_lock + key, 
                    without_caps[curr_idx-1] + key), 
                    with_caps[curr_idx-1] + shift_key + caps_lock
            );

            with_caps[curr_idx] = min(
                min(with_caps[curr_idx-1] + shift_key,
                    without_caps[curr_idx-1] + key + caps_lock),
                    without_caps[curr_idx-1] + shift_key + caps_lock
            );
        }
        curr_idx++;
    }
    cout << min(without_caps[sequence.size()], with_caps[sequence.size()]) << endl;
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
