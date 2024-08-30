#include <bits/stdc++.h>
using namespace std;

void printvec(vector<bool> lig) {
    for (int i = 1; i < lig.size(); i++) {
        cout << lig[i] << " ";
    }
    cout << endl;
}

bool check_light(vector<bool> lighten) {
    for (int i = 1; i < lighten.size(); i++) {
        if (lighten[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int switches, lightbulbs;
    cin >> switches >> lightbulbs;
    vector<bool> lighten(lightbulbs + 1, false);    

    int lig;
    cin >> lig;
    while (lig--) {
        int idx;
        cin >> idx;
        lighten[idx] = true;
    }

    vector<vector<int>> switch_set(switches);
    for (int i = 0; i < switches; i++) {
        int curr_sz;
        cin >> curr_sz;

        for (int j = 0; j < curr_sz; j++) {
            int s;
            cin >> s;
            switch_set[i].push_back(s);
        }
    }

    // check if starts off
    if (check_light(lighten)) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < 2 * switches; i++) {
        // lighten
        int idx = i % switches;
        for (int k = 0; k < switch_set[idx].size(); k++) {
            lighten[switch_set[idx][k]] = !lighten[switch_set[idx][k]];
        }

        // check if every lights are off
        if (check_light(lighten)) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}