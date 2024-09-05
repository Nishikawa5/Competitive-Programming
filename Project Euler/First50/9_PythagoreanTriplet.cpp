#include <bits/stdc++.h>

using namespace std;

/*
a^2 + b^2 = c^2
and a + b + c = N
*/
bool isTriplet(int a, int b, int c) {
    return a * a + b * b == c * c;
}

int main(void) {
    long maxPer = 3000;
    long maxMult[maxPer + 1] = {-1};
    
    // store all results in an array
    for (int a = 1; a < maxPer; a++) {
        for (int b = a + 1; b < maxPer - a; b++) {
            // assume is a triplet
            long c2 = a * a + b * b;

            // verify if is perfect square
            long c = sqrt(c2);
            
            long sum = a + b + c;
            if (sum > maxPer) {
                break;
            }
            if (c * c != c2) {
                continue;
            }

            maxMult[sum] = max(maxMult[sum], a * b * c);
        }
    }
    int tc;
    cin >> tc;
    while (tc--) {
        int N;

        cin >> N;

        printf("%ld\n", maxMult[N] ? maxMult[N] : -1);
    }
}