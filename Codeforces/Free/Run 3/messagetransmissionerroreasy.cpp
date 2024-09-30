#include <bits/stdc++.h>
using namespace std;

void solve() {
    string msg;
    cin >> msg;

    for (int i = 1; i < msg.size() - 1; i++) {
        // assume we sent this message
        string sent_message = msg.substr(0, msg.size() - i);

        // j starts at 1 because it need to overlap
        for (int j = 1; j < sent_message.size(); j++) {
            // check if this sent_message can form the msg while overlapping
            if (sent_message + sent_message.substr(j, sent_message.size()) == msg && 
                sent_message.substr(sent_message.size() - j, sent_message.size()) + sent_message.substr(j, sent_message.size()) == sent_message) {
                
                cout << "YES\n";
                cout << sent_message << "\n";
                return;
            }
        }
    }
    cout << "NO\n";
    return;
}

int main() {
    int tc = 1;

    while (tc--) {
        solve();
    }
}