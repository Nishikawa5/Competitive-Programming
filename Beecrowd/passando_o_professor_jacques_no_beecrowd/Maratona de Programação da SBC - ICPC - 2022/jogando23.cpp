#include <bits/stdc++.h>
using namespace std;

#define MARIA 0
#define JOAO 1

int maria = 0;
int joao = 0;
vector<int> cards(14, 4);

void add_card(int i, int person) {
    if (person == MARIA) {
        maria += min(i, 10);
    } else {
        joao += min(i, 10);
    }
    cards[i]--;
}

void add_card(int i) {
    maria += min(i, 10);
    joao += min(i, 10);
    cards[i]--;
}


int main() {
    int common_cards;
    cin >> common_cards;

    int i1, i2;
    cin >> i1 >> i2;
    add_card(i1, JOAO);
    add_card(i2, JOAO);

    cin >> i1 >> i2;
    add_card(i1, MARIA);
    add_card(i2, MARIA);

    while (common_cards--) {
        int common_card;
        cin >> common_card;
        add_card(common_card);
    }

    // maria wins if:
    // maria + x == 23
    // joao + x > 23
    int w1 = 23 - maria;

    int w2 = 100;
    int at_least = 24 - joao;
    if (at_least <= 10) {
        // get the min card >= at_least
        
        for (int i = at_least; i <= 13; i++) {
            if (cards[i]) {
                w2 = min(10, i);
                break;
            }
        }
    }

    if (w1 <= 10 && w1 < w2 && cards[w1]) {
        cout << w1 << endl;
    } else if (w2 != 100 && maria + w2 <= 23) {
        cout << w2 << endl;
    } else {
        cout << -1 << endl;
    }
}