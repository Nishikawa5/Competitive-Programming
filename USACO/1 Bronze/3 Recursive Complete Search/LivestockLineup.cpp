#include <bits/stdc++.h>
using namespace std;
/*
First write - 30 min
try         - 48 min (accepted)
*/


int getcowindex(vector<string> currorder, string cow) {
    for (int i = 0; i < currorder.size(); i++) {
        if (currorder[i] == cow) return i;
    }
    return -1;
}

// checks if the order is satisfied
bool satisfy(vector<string> currorder, vector<pair<string, string>> order) {
    for (int i = 0; i < order.size(); i++) {
        int cow1 = getcowindex(currorder, order[i].first);
        int cow2 = getcowindex(currorder, order[i].second);

        if (cow1 == -1 || cow2 == -1) {
            return false;
        }
        if (abs(cow1 - cow2) != 1) {
            return false;
        }
    }
    return true;
}

// make every combination of cows (order matters) and see if is possible
bool recursion(vector<string> &currorder, vector<bool> &inorder, int height,
               vector<pair<string, string>> order, vector<string> cownames) {
    if (satisfy(currorder, order) && height == cownames.size()) {
        return true;
    } else if (height < cownames.size()) {
        for (int i = 0; i < cownames.size(); i++) {
            if (inorder[i]) continue;       // already considered
            // add the cow to the order
            currorder.push_back(cownames[i]);
            inorder[i] = true;
            if (recursion(currorder, inorder, height + 1, order, cownames)) {
                return true;
            }
            currorder.pop_back();
            inorder[i] = false;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    vector<string> cownames{"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    sort(cownames.begin(), cownames.end());

    int n;
    cin >> n;
    vector<pair<string, string>> order(n);
    for (int i = 0; i < n; i++) {
        string dummy;
        cin >> order[i].first >> dummy >> dummy >> dummy >> dummy >> order[i].second;
    }

    vector<string> currorder;
    vector<bool> inorder(n, false);
    recursion(currorder, inorder, 0, order, cownames);
    for (int i = 0; i < currorder.size(); i++) {
        cout << currorder[i] << endl;
    }
}