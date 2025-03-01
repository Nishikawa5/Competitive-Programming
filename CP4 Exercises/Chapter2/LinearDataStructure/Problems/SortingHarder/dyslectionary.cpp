#include <bits/stdc++.h>
using namespace std;

void print_maxword(string word, int maxword) {
    for (int i = 0; i < maxword - word.size(); i++) {
        cout << " ";
    }
    cout << word << endl;
}

void solve(vector<string> dict, int maxword) {
    // reverse to sort
    for (string &word: dict) {
        reverse(word.begin(), word.end());
    }
    sort(dict.begin(), dict.end());

    // reverse again to print
    for (string &word: dict) {
        reverse(word.begin(), word.end());
        print_maxword(word, maxword);
    }
}

/*
took some time to figure how to get the input with this format
didn't knew that getline(cin, word) would give "" if read '\n'
*/
int main() {
    string word;
    vector<string> dict;
    int maxword = 0;
    while (getline(cin, word)) {
        if (word == "") {
            solve(dict, maxword);
            cout << endl;

            maxword = 0;
            dict = {};
        } else {
            maxword = max(maxword, (int) word.size());
            dict.push_back(word);
        }
    }
    if (!dict.empty()) {
        solve(dict, maxword);
    }
}