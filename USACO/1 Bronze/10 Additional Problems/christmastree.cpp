#include <bits/stdc++.h>
using namespace std;
#define lli long long int

double calculateAboveBase(int h, int d, int total_h) {
    return (1 - h / (double) total_h) * d;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        lli n, d, total_h;
        cin >> n >> d >> total_h;

        double total_area = 0;
        lli h1, h2;
        cin >> h2;
        n--;
        while (n--) {
            cin >> h1;
            if (h1 - h2 < total_h) {
                total_area += (d + calculateAboveBase(h1 - h2, d, total_h)) * (h1 - h2) / 2.0;
            } else {
                total_area += d * total_h / 2.0;
            }
            h2 = h1;
        }
        total_area += d * total_h / 2.0;
        printf("%.7lf\n", total_area);
    }
}