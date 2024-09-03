#include <bits/stdc++.h>
using namespace std;

int calculate_hash(vector<int> &vec, int x, int y) {
    int ans = 0;

    for (int i = 0; i < vec.size(); i++) {
        ans = ((long long) ans * x + vec[i]) % y;
    }
    return ans;
}

void count_sort(vector<int> &vec, int exp, vector<int> &dummy) {
    vector<int> count(10, 0);

    // sum
    for (int i = 0; i < vec.size(); i++) {
        count[(vec[i] / exp) % 10]++;
    }

    // calculate prefix
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // put in output
    for (int i = vec.size() - 1; i >= 0; i--) {
        dummy[--count[(vec[i] / exp) % 10]] = vec[i];
    }

    for (int i = 0; i < vec.size(); i++) {
        vec[i] = dummy[i];
    }
}

void radix_sort(vector<int> &vec) {
    vector<int> dummy(vec.size());
    // at most 10 digits
    int exp = 1;
    for (int i = 0; i <= 10; i++) {
        count_sort(vec, exp, dummy);
        exp *= 10;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while (tc--) {
        int n, a, b, c, x, y;
        cin >> n >> a >> b >> c >> x >> y;

        vector<int> magic_sequence(n);
        magic_sequence[0] = a;
        for (int i = 1; i < n; i++) {
            magic_sequence[i] = ((long long) magic_sequence[i - 1] * b + a) % c;
        }

        radix_sort(magic_sequence);
        cout << calculate_hash(magic_sequence, x, y) << endl;
    }
}