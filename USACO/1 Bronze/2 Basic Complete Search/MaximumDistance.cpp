#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> x(n);
    vector<int> y(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    int maxdist = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dx = x[i] = x[j];
            int dy = y[i] - y[j];
            int square_distance = dx * dx + dy * dy;
            maxdist = max(maxdist, square_distance);

            // may fail because pow transforms into float and (int) round. HINT : STICK WITH INT WHENEVER POSSIBLE 
            //maxdist = max(maxdist, (int) pow(x[i] - x[j], 2) + (int) pow(y[i] - y[j], 2));
        }
    }
    printf("%d\n", maxdist);
}