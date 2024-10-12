#include <bits/stdc++.h>
using namespace std;

/*
>= maximum depth (if eliminate every lower depth)

minimum depth (if eliminate every other depth)

to minimize the # of op, pick an optimal depth d where the max # of nodes remain alive
ai: depth of node i
bi: max depth of i

i is alive <=> ai <= d <= bi
maximize # of alive
*/

int calculate_depth(int node, int parent, int curr_depth, vector<int> &prefix_intervals, vector<vector<int>> &tree) {
    int max_depth = curr_depth;

    for (auto neighbor: tree[node]) {
        if (parent != neighbor) {
            // not parent
            max_depth = max(max_depth, calculate_depth(neighbor, node, curr_depth + 1, prefix_intervals, tree));
        }
    }

    prefix_intervals[curr_depth]++;
    prefix_intervals[max_depth + 1]--;

    return max_depth;
}

void solve() {
    int nodes;
    cin >> nodes;

    vector<vector<int>> tree(nodes);
    for (int i = 1; i < nodes; i++) {
        int from, to;
        cin >> from >> to;

        tree[from - 1].push_back(to - 1);
        tree[to - 1].push_back(from - 1);
    }

    // +1 on depth, -1 after maxdepth
    vector<int> prefix_intervals(nodes + 1);
    calculate_depth(0, -1, 0, prefix_intervals, tree);

    int max_alive = prefix_intervals[0];
    for (int i = 1; i < prefix_intervals.size(); i++) {
        prefix_intervals[i] += prefix_intervals[i - 1];
        max_alive = max(max_alive, prefix_intervals[i]);
    }
    cout << nodes - max_alive << endl;
}



int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}