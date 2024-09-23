#include <bits/stdc++.h>
using namespace std;

void dfs(int curr_vertice, bool &is_cycle, vector<int> &cycles, vector<int> &indicate) {
    if (cycles[curr_vertice] != -2) {
        // check if we have a cycle
        if (cycles[curr_vertice] == -1) {
            // we are in a cycle
            is_cycle = true;
            cycles[curr_vertice] = curr_vertice;
        }
        // to not repeat
        return;
    }

    // mark as visited
    cycles[curr_vertice] = -1;
    // dfs the next (mark to come back later, while filling the cycles)
    dfs(indicate[curr_vertice], is_cycle, cycles, indicate);

    if (cycles[curr_vertice] == -1) {
        // visited, so mark the first cycle of it
        // cycle => the vertice we are in
        // not cycle => the vertice that starts the cycle
        cycles[curr_vertice] = (is_cycle ? curr_vertice : cycles[indicate[curr_vertice]]);
    } else {
        // got back to non ciclic nodes
        is_cycle = false;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> indicate(n);
    for (auto &i: indicate) {
        cin >> i;
        i--;
    }
    
    vector<int> cycles(n, -2);
    bool is_cycle = false;
    for (int i = 0; i < n; i++) {
        dfs(i, is_cycle, cycles, indicate);
        cout << cycles[i] + 1 << " ";
    }
    cout << endl;
}