#include <bits/stdc++.h>
using namespace std;

/*
n    : a1b1, anbn
n + 1: a2b2, an-1bn-1
...

we have (i + 1) * (n - i) combinations with ai
since these combinations are fixed we can just sort it to multiply with sorted b and get the result
*/
int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // get the combinations of a
    vector<int> aicomb(n);
    for (int i = 0; i < n; i++) {
        aicomb[i] = (i + 1) * (n - i) * a[i];
    }

    // sort them to get the best rst
    sort(aicomb.begin(), aicomb.end());
    sort(b.begin(), b.end(), greater<int>());

    int rst = 0;
    for (int i = 0; i < n; i++) {
        rst += aicomb[i] * b[i];
    }
    cout << rst << endl;
}