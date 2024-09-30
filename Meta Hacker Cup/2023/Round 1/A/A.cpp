#include <bits/stdc++.h>
using namespace std;

void solve() {
    int num_cards, num_cuts;
    cin >> num_cards >> num_cuts;

    vector<int> cards_from(num_cards);
    vector<int> cards_to(num_cards);

    for (auto &c: cards_from) {
        cin >> c;
    }
    for (auto &c: cards_to) {
        cin >> c;   
    }

    // is it possible to rotate cardsfrom to cardsto?
    // every rotation is possible with one rotation
    // check if it is a rotation

    bool is_rotation = true;
    int i = 0;
    while (cards_from[i++] != cards_to[0]);
    i--;

    for (int j = 0; j < num_cards; j++) {
        if (cards_from[(i + j) % num_cards] != cards_to[j]) {
            is_rotation = false;
            break;
        }
    }


    if (!is_rotation || (!i && num_cuts == 1)) {
        cout << "NO\n";
    } else {
        // is a rotation
        if (num_cuts == 0) {
            if (!i) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            return;
        }

        // now lets analise if the number of rotations allow us to make to this rotation
        // we can make into any rotation in one move.
        if (num_cards == 2) {
            // we can't make not the rotation -> not the rotation -> ... -> the rotation always
            // since we have just 2 possibilities and one is the rotation
            // we can just change between these two
            if (!i) {
                // start at the rotation
                // so only when even is the rotation
                if (num_cuts % 2 == 0) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            } else {
                // the contrary
                if (num_cuts % 2) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            }
        } else {
            cout << "YES\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}