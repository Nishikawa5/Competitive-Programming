#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string soup;
    cin >> n;
    getchar();
    getline(cin, soup);

    stack<char> delimiters;
    for (int i = 0; i < n; i++) {
        if (soup[i] != ' ') {
            if (soup[i] == '(' || soup[i] == '[' || soup[i] == '{') {
                delimiters.push(soup[i]);
            } else if (!delimiters.empty() &&
                       ((delimiters.top() == '(' && soup[i] == ')') || 
                       (delimiters.top() == '[' && soup[i] == ']') || 
                       (delimiters.top() == '{' && soup[i] == '}'))) {
                delimiters.pop();
            } else {
                cout << soup[i] << " " << i << endl;
                return 0;
            }
        }
    }
    cout << "ok so far\n";
}