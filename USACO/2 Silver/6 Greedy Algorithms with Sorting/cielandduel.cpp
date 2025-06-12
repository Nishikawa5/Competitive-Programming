#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> attack;
    vector<int> defense;

    for (int i = 0; i < n; i++) {
        string pos;
        int power;
        cin >> pos >> power;

        if (pos == "ATK") {
            attack.push_back(power);
        } else {
            defense.push_back(power);
        }
    }

    vector<int> ciel_cards(m);
    for (auto &c: ciel_cards) {
        cin >> c;
    }


    sort(attack.begin(), attack.end());
    sort(defense.begin(), defense.end());

    sort(ciel_cards.begin(), ciel_cards.end());


    // we can either break all defenses and attackers
    // for defense we must use a card as close 
    // as possible and bigger
    // so we first try to break the defense and then attack
    // for each ciel card
    int points_if_all_broken = 0;
    int points_1 = 0;

    int atk = 0;
    int def = 0;
    for (int i = 0; i < m; i++) {
        
        if (def < defense.size() && defense[def] < ciel_cards[i]) {
            // break that
            def++;
        } else if (atk < attack.size() && attack[atk] <= ciel_cards[i]) {
            // break that and sum
            points_1 += ciel_cards[i] - attack[atk];
            atk++;
        } else {
            // cant break or no cards to break
            points_if_all_broken += ciel_cards[i];
        }
    }
    
    if (atk + def == n) {
        // all cards broken?
        points_1 += points_if_all_broken;
    }

    //            or deal the max with the attackers
    int points_2 = 0;
    int idx = ciel_cards.size() - 1;
    for (int i = 0; i < attack.size() && idx >= 0; i++) {
        if (ciel_cards[idx] >= attack[i]) {
            points_2 += ciel_cards[idx--] - attack[i];
        } else {
            break;
        }
    }    

    cout << max(points_1, points_2) << endl;
}

int main() {
    int tc = 1;

    while (tc--) {
        solve();
    }
}