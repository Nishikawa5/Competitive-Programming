#include <bits/stdc++.h>
using namespace std;

void printRing(int x, bool three) {
    if (three) {
        if (x >= 10) {
            cout << '.' << x;
        } else if (x > 0) {
            cout << ".." << x;
        } else {
            cout << "...";
        }
    } else {
        if (x >= 10) {
            cout << x;
        } else if (x > 0) {
            cout << "." << x;
        } else {
            cout << "..";
        } 
    }
}

void calculateFix(int start_i, int lim_i, int add_i, int start_j, int lim_j, int add_j, vector<vector<int>> &grid) {
    for (int i = start_i; i != lim_i; i += add_i) {
        for (int j = start_j; j != lim_j; j += add_j) {
            if (grid[i][j]) {
                if (i != start_i && j != start_j) {
                    grid[i][j] = min(grid[i - add_i][j], grid[i][j - add_j]) + 1;
                } else if (i != start_i || j != start_j) { 
                    grid[i][j] = 1;
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (auto &vec: grid) {
        string row;
        cin >> row;
        for (int i = 0; i < m; i++) {
            vec[i] = row[i] != '.';
        }
    }
    vector<vector<int>> prefix = grid;
    vector<vector<int>> suffix = grid;
    vector<vector<int>> anotherfix = grid;
    vector<vector<int>> otherfix = grid;
    
    calculateFix(0, n, 1,           0, m, 1, prefix);
    calculateFix(n - 1, -1, -1,     m - 1, -1, -1, suffix);
    calculateFix(0, n, 1,           m - 1, -1, -1, anotherfix);
    calculateFix(n - 1, -1, -1,     0, m, 1, otherfix);

    int max_ring = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = (min(min(prefix[i][j], suffix[i][j]), min(anotherfix[i][j], otherfix[i][j])));
            max_ring = max(max_ring, grid[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printRing(grid[i][j], max_ring >= 10);
        }
        cout << endl;
    }
}