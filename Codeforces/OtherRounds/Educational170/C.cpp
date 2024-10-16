#include <bits/stdc++.h>
using namespace std;

void solve() {
    /*
    take one card
    -> take a card that is the same or +1 prev card
    at most k diff
    */

    int num_cards, distinct;
    cin >> num_cards >> distinct;

    map<int, int> cards;
    for (int i = 0; i < num_cards; i++) {
        int card;
        cin >> card;
        cards[card]++;
    }

    vector<pair<int, int>> cards_num;
    for (auto &card_num: cards) {
        cards_num.push_back(card_num);
    }

    // two pointers
    int ans = 0;
    int last_card = -1;
    int curr_cards = 0;
    for (int l = 0, r = 0; r < cards_num.size(); r++) {
        if (cards_num[r].first - 1 == last_card || last_card == -1) {
            if ((r - l) >= distinct) {
                // just remove the left and add the right
                curr_cards -= cards_num[l++].second;
            }
            // add new card
            curr_cards += cards_num[r].second;
            last_card = cards_num[r].first;
        } else {
            // remove all cards
            curr_cards = 0;
            last_card = -1;
            l = r--;
        }

        ans = max(ans, curr_cards);
    }
    cout << ans << endl;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}
