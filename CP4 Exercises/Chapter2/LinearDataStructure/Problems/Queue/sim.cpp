#include <bits/stdc++.h>
using namespace std;

pair<string, char> buildString() {
    char c;
    string str = "";
    while ((c = getchar()) && c != '\n' && c != '['  && c != ']') {
        if (c == '<') {
            if (!str.empty()) {
                str.pop_back();
            }
        } else {
            str.push_back(c);
        }
    }
    return {str, c};
}

void solve() {
    deque<string> text;
    char curr_state = ']';
    string curr_string = "";

    pair<string, char> next_block = buildString();
    while (next_block.second != '\n') {
        curr_string.append(next_block.first);
        if (curr_state != next_block.second) {
            if (curr_state == ']') {
                text.push_back(curr_string);
            } else if (curr_state == '[') {
                text.push_front(curr_string);
            }
            curr_string = "";
            curr_state = next_block.second;
        }
        next_block = buildString();
    }
    curr_string.append(next_block.first);
    if (curr_state == ']') {
        text.push_back(curr_string);
    } else if (curr_state == '[') {
        text.push_front(curr_string);
    }

    while (!text.empty()) {
        cout << text.front();
        text.pop_front();
    }
}

int main() {
    int tc;
    cin >> tc;
    getchar();

    while (tc--) {
        solve();
    }
}