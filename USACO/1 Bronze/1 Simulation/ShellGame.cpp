#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector<int> v{1, 2, 3};
    vector<int> points(3, 0);
    for (int i = 0; i < N; i++) {
        // swap
        int a, b;
        cin >> a >> b;
        swap(v[a - 1], v[b - 1]);

        // guess
        int g;
        cin >> g;

        // assume starts at 1
        if (v[g - 1] == 1) {
            points[0]++;
        }

        // assume starts at 2
        if (v[g - 1] == 2) {
            points[1]++;
        }

        // assume starts at 3
        if (v[g - 1] == 3) {
            points[2]++;
        }
    }
    cout << max(points[0], max(points[1], points[2])) << endl;
}