#include <bits/stdc++.h>
using namespace std;

int getNum(string str, int i) {
    string num;
    while (i < str.size() && '0' <= str[i] && str[i] <= '9') {
        num.push_back(str[i++]);
    }
    return stoi(num);
}

void solve() {
    string numbers;
    string commands;
    cin >> numbers >> commands;

    int ptr = 0;
    for (int i = 0; i < commands.size(); i++) {
        if (commands[i] == 'R' && ptr < numbers.size() - 1) {
            ptr++;
        } else if (commands[i] == 'L' && ptr > 0) {
            ptr--;
        } else if (commands[i] == 'T' && '0' <= numbers[ptr] && numbers[ptr] < '9') {
            numbers[ptr]++;
        } else if (commands[i] == 'D' && '0' < numbers[ptr] && numbers[ptr] <= '9') {
            numbers[ptr]--;
        } else if (commands[i] == 'S') {
            i++;
            int swap_idx = getNum(commands, i) - 1;

            swap(numbers[ptr], numbers[swap_idx]);
        }
    }
    cout << numbers << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;

    while (tc--) {
        solve();
    }
    return 0;
}
