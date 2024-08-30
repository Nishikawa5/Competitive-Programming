#include <bits/stdc++.h>
using namespace std;

/*
Every number before the greatest? + 1
*/
int main() {
    freopen("sleepy.in", "r", stdin);
	freopen("sleepy.out", "w", stdout);

    int n;
    cin >> n;

    int sorted = 1;
    int cow;
    int prevcow;
    cin >> prevcow;
    for (int i = 1; i < n; i++) {
        cin >> cow;
    
        if (cow >= prevcow) {
            sorted++;
        } else {
            sorted = 1;
        }
        prevcow = cow;
    }
    cout << n - sorted << endl;
}