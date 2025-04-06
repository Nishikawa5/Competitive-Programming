#include <bits/stdc++.h>
using namespace std;

int main() {
    int stacks_num, instructions;
    cin >> stacks_num >> instructions;

    vector<int> stacks(stacks_num + 2);

    while (instructions--) {
        int start, end;
        cin >> start >> end;

        stacks[start]++;
        stacks[end + 1]--;
    }

    for (int i = 1; i < stacks.size(); i++) {
        stacks[i] += stacks[i - 1];
    }

    sort(stacks.begin(), stacks.end());
    // we have 2 more stacks
    cout << stacks[stacks_num / 2 + 2] << endl;
}