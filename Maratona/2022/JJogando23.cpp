#include <bits/stdc++.h>
using namespace std;

// para maria ganhar:
// joao estoura
// maria chega a 23

// maria nao pode ganhar na proxima <=>
// maria < 13
// maria estourou

int main() {
    int n;
    cin >> n;
    int joao = 0;
    int maria = 0;
    int card;
    vector<int> used_cards(14, 0);

    for (int i = 0; i < 2; i++) {
        cin >> card;
        used_cards[card]++;
        joao += min(card, 10);
    }
    for (int i = 0; i < 2; i++) {
        cin >> card;
        used_cards[card]++;
        maria += min(card, 10);
    }

    for (int i = 0; i < n; i++) {
        cin >> card;
        used_cards[card]++;
        joao += min(card, 10);
        maria += min(card, 10);
    }

    int ans = -1;
    for (int common_card = 1; common_card <= 13; common_card++) {
        if (used_cards[common_card] < 4) {
            // e possivel tirar essa carta comum
            int common_card_value = min(common_card, 10);   // nao pode ultrapassar 10
            if (maria + common_card_value == 23 || (joao + common_card_value > 23 && maria + common_card_value <= 23)) {
                // maria chega a 23
                // ou joao estoura e maria nao
                ans = common_card;
                break;
            }
        }
    }
    cout << ans << endl;
}