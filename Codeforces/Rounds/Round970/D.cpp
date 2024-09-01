#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        vector<int> graph(n);
        string colors;
        for (auto &g: graph) {
            cin >> g;
            g--;
        }
        cin >> colors;

        vector<int> visited(n, -1);
        for (int i = 0; i < n; i++) {
            int j = i;
            int fi = 0;
            vector<int> visited_sequence;
            while (visited[j] == -1) {
                visited_sequence.push_back(j);
                fi += colors[j] == '0';
                visited[j] = fi;
                j = graph[j];
            }
            // add only if not loop
            bool loop = false;
            for (auto &v: visited_sequence) {
                if (v == j) {
                    loop = true;
                    break;
                }
            }

            if (!loop) {
                fi += visited[j];
                for (int &v: visited_sequence) {
                    visited[v] = fi;
                    fi -= colors[v] == '0';
                }
            } else {
                for (int &v: visited_sequence) {
                    visited[v] = fi;
                }
            }

            cout << visited[i] << " ";
        }
        cout << endl;
    }
}