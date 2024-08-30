#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string str;
    cin >> str >> n;

    // perceba que podemos fazer a string ficar ordenada se pudermos trocar um caractere do lado do outro
    // exemplo: cba -> cab -> acb -> abc
    // podemos pensar que estamos trocando um do lado do outro porém com n strings diferentes, espaçadas de n em n
    vector<vector<int>> counts(n, vector<int>(26, 0));
    for (int i = 0; i < str.size(); i++) {
        counts[i % n][str[i] - 'a']++;
    }
    for (int i = 0; i < counts.size(); i++) {
        int curr_idx = i;
        for (int k = 0; k < 26; k++) {
            while (counts[i][k]-- > 0) {
                str[curr_idx] = k + 'a';
                curr_idx += n;
            }
        }
    }
    cout << str << endl;
}