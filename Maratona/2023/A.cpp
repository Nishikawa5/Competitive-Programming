#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, h;
    cin >> n >> h;

    int max_rides = 0;
    while (n--) {
        int curr_h;
        cin >> curr_h;

        max_rides += h >= curr_h;
    }
    cout << max_rides << endl;
}