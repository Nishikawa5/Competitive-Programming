#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    getchar();

    while (tc--) {
        string line;
        getline(cin, line);
        list<char> text;

        list<char>::iterator iter = text.begin();
        for (char c: line) {
            switch (c) {
                case '<':
                    if (iter != text.begin()) {
                        iter = text.erase(--iter);
                    }
                    break;
                case '[':
                    iter = text.begin();
                    break;
                case ']':
                    iter = text.end();
                    break;
                default:
                    iter = text.insert(iter, c);
                    iter++;
                    break;
            }
        }

        for (char c: text) {
            cout << c;
        }
        cout << endl;
    }
}