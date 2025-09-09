#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    char c;

    double temp;
    cin >> c >> temp;

    int curr_bal = temp*100;

    int ans = 0;
    while (n--) {
        double deposit;
        cin >> c >> deposit;

        curr_bal += deposit*100;

        if (curr_bal % 100) {
            ans++;
        }
    }
    cout << ans << endl;
}