#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    unordered_map<int, int> right_end;   // end of the interval of number i rend[i]
    unordered_map<int, int> count;  // count the number of elements

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        right_end[a[i]] = i;
        count[a[i]]++;
    }

    int left = 0;
    int most_right = 0;
    int max_changes = 0;
    int min_changes = 0;
    for (int i = 0; i < n; i++) {
        // find the most right
        most_right = max(most_right, right_end[a[i]]);
        // maximum number of changes so we can get the minimum
        // e.g. 1 1 2 3 4 5 1 5 (in this subset we have more ones so the minimum to change is the length - ones)
        max_changes = max(max_changes, count[a[i]]);

        // found the end of most right, so change the array
        if (most_right == i) {
            min_changes += most_right - left + 1 - max_changes;
            left = most_right + 1;

            max_changes = 0;
        }        
    }
    cout << min_changes << endl;
}