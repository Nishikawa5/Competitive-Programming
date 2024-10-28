#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int t;
    int n;

    scanf("%d", &t);

    string a, b, c;

    while(t--) {
        scanf("%d", &n);
        cin >> a >> b >> c;
        bool isPossible = false;

        for (int i = 0; i < n; i++) {
            // if a[i] != b[i] we choose an uppercase
            // else we choose the letter or uppercase
            if (a[i] == c[i] || b[i] == c[i]) {
                continue;
            } else {
                isPossible = true;
                break;
            }
        }
        if (isPossible) printf("YES\n");
        else printf("NO\n");
    }
}