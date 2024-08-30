#include <bits/stdc++.h>
using namespace std;

int dfs(int curr_boss, vector<int> &total_employees, vector<vector<int>> &tree) {
    int total = 0;

    for (int employee: tree[curr_boss]) {
        total += dfs(employee, total_employees, tree);
    }
    total_employees[curr_boss] = total;
    return total + 1;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n);
    vector<int> total_employees(n, 0);

    for (int employee = 1; employee < n; employee++) {
        int direct_boss;
        cin >> direct_boss;

        tree[direct_boss - 1].push_back(employee);
    }
    dfs(0, total_employees, tree);

    for (int employees: total_employees) {
        cout << employees << " ";
    }
    cout << "\n";
}