#include <bits/stdc++.h>
using namespace std;

int tree_diameter(int curr_node, int parent, int &diameter, vector<vector<int>> &tree) {
    // compute the diameters of every node (not considering parent) and stores the max
    // dfs through every node connected to some node and return the max depth of this subtree
    // the result should be the sum of 2 greatest depth

    int first_greatest_depth = 0;
    int second_greatest_depth = 0;

    for (auto &node : tree[curr_node]) {
        if (node != parent) {
            // we assume the parent is not part of this current diameter, 
            // since the diameter of the parent will be computed later
            // and avoid revisit
            int node_depth = tree_diameter(node, curr_node, diameter, tree);

            if (first_greatest_depth < node_depth) {
                second_greatest_depth = first_greatest_depth;
                first_greatest_depth = node_depth;
            } else if (second_greatest_depth < node_depth) {
                second_greatest_depth = node_depth;
            }
        }
    }

    diameter = max(diameter, first_greatest_depth + second_greatest_depth);

    return first_greatest_depth + 1;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> tree(n);
    
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int diameter = 0;
    tree_diameter(0, -1, diameter, tree);

    cout << diameter << endl;
}