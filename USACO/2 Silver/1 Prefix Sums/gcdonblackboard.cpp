#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void printvec(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> prefixgcd(n + 1);
    vector<int> suffixgcd(n + 1);
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    prefixgcd[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefixgcd[i] = gcd(prefixgcd[i - 1], nums[i - 1]);
    }
    //printvec(prefixgcd);

    suffixgcd[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        suffixgcd[i] = gcd(suffixgcd[i + 1], nums[i]);
    }
    //printvec(suffixgcd);

    int maxgcd = 0;
    for (int i = 0; i < n; i++) {
        // choose which number to ignore
        maxgcd = max(maxgcd, gcd(prefixgcd[i], suffixgcd[i + 1]));
    }

    cout << maxgcd;
}