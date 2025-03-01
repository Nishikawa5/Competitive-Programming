#include <bits/stdc++.h>
using namespace std;

int main() {
    int commands_num, childs_num;
    cin >> childs_num >> commands_num;

    stack<int> commands;
    while (commands_num--) {
        string command;
        cin >> command;

        if (command == "undo") {
            int pop_num;
            cin >> pop_num;

            while (!commands.empty() && pop_num--) {
                commands.pop();
            }
        } else {
            commands.push(stoi(command));
        }
    }
    int curr_child = 0;
    while (!commands.empty()) {
        curr_child = (curr_child + commands.top()) % childs_num;
        commands.pop();
    }
    cout << (curr_child + childs_num) % childs_num << endl;
}