#include <bits/stdc++.h>
using namespace std;

/*
x 0 y
abs(x - y) >= 3 => impossible
abs(x - y) == 2 => 1
abs(x - y) == 1 => 2
abs(x - y) == 0 => 3

x 0 0 == 0 0 x => m * (x 0 y)

0 0 0 => m * (x 0 0)

fix the limits

0 0 0 0 0

*/
int main() {
    int n, ub;
    cin >> n >> ub;

    vector<int> arr(n + 2);
    arr[0] = arr[n + 1] = 0;
    for (int i = 1; i < n + 1; i++) {
        cin >> arr[i];
    }


}