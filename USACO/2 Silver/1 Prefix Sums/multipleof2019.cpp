#include <bits/stdc++.h>
using namespace std;

int main() {
    string number;
    cin >> number;

    vector<int> remainder(2019, 0);
    remainder[0] = 1;                // remainder 0 is already valid
    int curr_num = 0;
    int pow = 1;

    /*
    construct the number from right to left
    since the partial mods are different than left to right (but final mods are equal)
    */
    long long multiples = 0;
    for (int i = number.size() - 1; i >= 0; i--) {
        curr_num = (curr_num + (number[i] - '0') * pow) % 2019;
        multiples += remainder[curr_num];
        remainder[curr_num]++;
        pow = (pow * 10) % 2019;
    }

    /*
    // also could count all combinations with:
    for (int i = 0; i < 2019; i++) {
        multiples += remainder[i] * (remainder[i] - 1) / 2;
    }
    */
    cout << multiples << endl;
}