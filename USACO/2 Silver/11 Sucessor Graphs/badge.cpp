#include <bits/stdc++.h>
using namespace std;

int main() {
    // choose i in cycle => is i
    // choose i not in cycle => first j in cycle

    int n;
    cin >> n;

    vector<int> indicate(n);
    for (auto &p: indicate) {
        cin >> p;
        p--;
    }
    
    for (int start = 0; start < n; start++) {
        int slow_pointer = start;
        int fast_pointer = start;
        // find the loop
        do {
            slow_pointer = indicate[slow_pointer];
            fast_pointer = indicate[indicate[fast_pointer]];
        } while (slow_pointer != fast_pointer);

        // go back to the first
        int go_back = slow_pointer;
        int start_again = start;
        while (go_back != start_again) {
            start_again = indicate[start_again];
            go_back = indicate[go_back];
        }
        cout << go_back + 1 << " ";
    }
    cout << endl;
}