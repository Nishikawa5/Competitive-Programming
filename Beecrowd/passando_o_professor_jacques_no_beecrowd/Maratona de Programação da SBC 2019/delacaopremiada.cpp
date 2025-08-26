#include <bits/stdc++.h>
using namespace std;

void solve() {
    // n members, 1 boss
    // 1 -> 2 

    int members, guesses;
    cin >> members >> guesses;

    vector<int> parent(members);
    vector<int> num_childs(members);
    vector<int> scores(members);

    parent[0] = -1;

    for (int i = 1; i < members; i++) {
        int p;
        cin >> p;

        parent[i] = p - 1;
        num_childs[parent[i]]++;
    }

    queue<int> queue;
    for (int i = 0; i < members; i++) {
        if (num_childs[i] == 0) {
            // is leaf
            queue.push(i);
            scores[i] = 1;
        }
    }

    vector<int> branch_scores;
    while (!queue.empty()) {

        int curr_member = queue.front();
        queue.pop();

        // analyzing the curr_member
        if (parent[curr_member] != -1 &&
            --num_childs[parent[curr_member]] == 0) {
            // it was the last child,
            // so continue
            scores[parent[curr_member]] = scores[curr_member] + 1;
            queue.push(parent[curr_member]);
        } else {
            // the parent have more child, 
            // so we cut this branch
            // since theres a deeper branch (bfs)
            branch_scores.push_back(scores[curr_member]);
        }
    }

    int ans = 0;
    for (int i = 0, to = min(guesses, (int)branch_scores.size()); i < to; i++) {
        ans += branch_scores[branch_scores.size() - i - 1];
    }

    cout << ans << endl;
}

int main() {
    solve();
}