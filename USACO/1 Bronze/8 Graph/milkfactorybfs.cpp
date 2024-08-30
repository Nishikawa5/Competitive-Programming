#include <bits/stdc++.h>
using namespace std;

/*
start: 48
firstsub: 30 passed

could have done better by inverting the arrows, so we wouldn't need to search
from every node

would have to search just i
*/
void pushvec(queue<int> &q, vector<int> vec) {
    for (int i : vec) {
        q.push(i);
    }
}

bool isConnected(int a, int b, vector<int> graph[], int n) {
    queue<int> q;
    vector<bool> passed(n + 1, false);
    passed[a] = true;

    pushvec(q, graph[a]);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (passed[curr]) {
            continue;
        }
        pushvec(q, graph[curr]);
        passed[curr] = true;

        if (curr == b) {
            return true;
        }
    }
    return false;
}

int main() {
    freopen("factory.in", "r", stdin);
	freopen("factory.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> graph[n + 1];
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
    }

    // assume i, try to find it with every node
    for (int i = 1; i <= n; i++) {
        bool isThis = true;
        for (int j = 1; j <= n; j++) {
            if (j != i && !isConnected(j, i, graph, n)) {
                isThis = false;
                break;
            }
        }
        if (isThis) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}