#include <bits/stdc++.h>
using namespace std;

/*
if the friends encounter eachother in the end and there's some friend that moved 2 times more => finish line
*/

void move(vector<int> friends) {
    // moves every friend inside this vector
    cout << "next";
    for (int &f: friends) {
        cout << " " << f;
    }
    cout << endl;
}

void get_groups(vector<int> &groups) {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string group;
        cin >> group;

        for (char c: group) {
            // put this friend in i-th group
            groups[c - '0'] = i;
        }
    }
}

int main() {
    vector<int> groups(10);
    // find the cycle
    // do that until both 0 and 1 are in the same group (floyd algo)
    do {
        move({0, 1});
        get_groups(groups);
        move({1});
        get_groups(groups);
    } while(groups[0] != groups[1]);

    // found the cycle, so move every friend to the same vertice
    while (groups[1] != groups[2]) {
        move({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
        get_groups(groups);
    }
    cout << "done\n";
}