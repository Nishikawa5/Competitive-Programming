#include <bits/stdc++.h>
using namespace std;

int main(void) {
    // the tree is organized the same as priority queue
    int height;
    string moves;
    cin >> height >> moves;
    
    int curr_val = (1 << (height + 1));
    int idx = 1;
    for (auto c: moves) {
        idx *= 2;
        idx += (c == 'R');
    }

    cout << curr_val - idx << endl;
}