#include <bits/stdc++.h>
using namespace std;

/*
the farthest node of any node will be the endpoint of the diameter, so we can just perform 1 dfs to get to the farthest
node from some starting node and calculate the max depth of this farthest node.

proof sketch:
assume the diameter is b -> c
lets prove by contradiction that b or c is the farthest node from a, which is an endpoint:
assume a is an arbitrary node, x is the intersection of paths and b and c are diameter endpoints
and d is the farthest node from a =>

a -> b < a -> d => d -> x > b -> x => d -> x + x -> c > b -> x + x -> c
so the diameter would be d -> c, which is a contradiction 

Therefore, b or c is an endpoint

draw a tree where the diameter is an horizontal line to make it easier to see

*/

int max_depth(int curr_node, int parent, vector<vector<int>> &tree) {
    int curr_depth = 0;
    for (auto &node : tree[curr_node]) {
        if (node != parent) {
            curr_depth = max(curr_depth, max_depth(node, curr_node, tree));
        }
    }
    return curr_depth + 1;
}

void farthest_node(int curr_node, int parent, int curr_distance, int &max_distance, int &farthest, vector<vector<int>> &tree) {
    if (max_distance < curr_distance) {
        max_distance = curr_distance;
        farthest = curr_node;
    }

    for (auto &node : tree[curr_node]) {
        if (node != parent) {
            farthest_node(node, curr_node, curr_distance + 1, max_distance, farthest, tree);
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> tree(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int max_dist = 0;
    int farthest = 0;
    farthest_node(0, -1, 0, max_dist, farthest, tree);

    cout << max_depth(farthest, -1, tree) - 1 << endl;
}