#include <bits/stdc++.h>

using namespace std;


int main(void) {
    string A;

    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; i++) {
        // in modulo 1000000007
        int decimalS = 0;
        cin >> A;
        int sizeA = A.size();
        bool parity = (((int) A.size()) % 2);

        while (sizeA != 0) {

            if (!parity) {
                // |A| is odd => middle bit of A is added to end of S and removed from A

            } else {
                // |A| is even => both middle of A are compared. The bigger is added to end of S and removed from A

            }
            parity = !parity;
            sizeA--;
        }
        // |A| is empty => terminates and return decimal representation of S

    }


}