#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int numCards;

    while (cin >> numCards && numCards) {
        list<int> indexes;
        // initialize the list of indexes;
        for (int i = 0; i < numCards; i++) {
            indexes.push_back(i);
        }

        vector<string> cards(numCards);

        string cardType;
        string temp;

        list<int>::iterator it = indexes.begin(); // iterator for the list
        for (int i = 0; i < numCards; i++) {
            cin >> cardType >> temp;

            int sizeOpt = (temp.size() - 1) % indexes.size();
            for (int k = 0; k < sizeOpt; k++) {
                if (it == prev(indexes.end())) {
                    it = indexes.begin();
                } else {
                    it++;
                }
            }
            cards[*it] = cardType;
            list<int>::iterator aux = it;

            if (it == prev(indexes.end())) {
                it = indexes.begin();
            } else {
                it++;
            }
            indexes.erase(aux);
            
        }

        for (int i = 0; i < numCards; i++) {
            if (i) cout << " ";
            cout << cards[i];
        }
        cout << endl;
    }
}