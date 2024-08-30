#include <bits/stdc++.h>
using namespace std;

int main() {
    int words_num, sz;
    cin >> words_num >> sz;

    // contar as palavras que podem ser formadas (mantendo em ordem alfabetica)
    map<string, int> count;
    while (words_num--) {
        string word;
        cin >> word;

        int pos = 0;
        for (char &c: word) {
            if (c == '*') {
                break;
            }
            pos++;
        }

        // conta as palavras possiveis
        for (char sub = 'a'; sub <= 'z'; sub++) {
            word[pos] = sub;
            count[word]++;
        }
    }

    // pega a melhor palavra, mantendo em ordem alfabetica
    string most_appeared = "";
    int appearences = 0;
    for (auto &curr_count: count) {
        if (curr_count.second > appearences) {
            most_appeared = curr_count.first;
            appearences = curr_count.second;
        }
    }
    cout << most_appeared << " " << appearences << endl;
}