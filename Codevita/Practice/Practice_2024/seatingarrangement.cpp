#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string seats;
    cin >> seats;

    int occupied = 0;
    for (auto c: seats) {
        occupied += (c == 'O');
    }

    map<int, int> moved;
    int moves = 0;
    for (int i = 0; i < occupied; ++i) {
        moves += (seats[i] == 'E');
    }
    moved[moves]++;

    // sliding window
    for (int i = occupied; i < n; ++i) {
        moves -= (seats[i - occupied] == 'E');
        moves += (seats[i] == 'E');
        moved[moves]++;
    }

    auto it = moved.begin();
    if (it == moved.end() || (*it).first == 0) {
        cout << "00" << endl;
    } else {
        cout << (*it).first << " " << (*it).second << endl;
    }
}