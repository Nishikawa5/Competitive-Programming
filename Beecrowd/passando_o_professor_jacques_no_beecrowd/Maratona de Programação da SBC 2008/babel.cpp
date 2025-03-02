#include <bits/stdc++.h>
using namespace std;


/*
just get the shortest path with last initial != curr initial
*/

int INF = 1e9;

int main() {
    int m;

    while (cin >> m && m) {
        string start, dest;

        cin >> start >> dest;

        // lets use indexed languages
        unordered_map<string, int> lang_to_idx;
        int curr_idx = 0;

        lang_to_idx[start] = curr_idx++;
        if (start != dest) {
            lang_to_idx[dest] = curr_idx++;
        }
        
        vector<vector<pair<pair<int, int>, char>>> graph(2*m + 2);

        for (int i = 0; i < m; i++) {
            string from, to, word;
            
            cin >> from >> to >> word;

            if (lang_to_idx.find(from) == lang_to_idx.end()) {
                lang_to_idx[from] = curr_idx++;
            }
            if (lang_to_idx.find(to) == lang_to_idx.end()) {
                lang_to_idx[to] = curr_idx++;
            }

            graph[lang_to_idx[from]].push_back({{lang_to_idx[to], word.size()}, word[0]});
            graph[lang_to_idx[to]].push_back({{lang_to_idx[from], word.size()}, word[0]});
        }

        // {distance, {node, last letter}}
        typedef pair<int, pair<int, char>> State;
        priority_queue<State, vector<State>, greater<State>> pq;

        // dist[node][lastLetter] = shortest distance to this state
        vector<unordered_map<char, int>> dist(graph.size());

        int start_idx = lang_to_idx[start];
        int dest_idx = lang_to_idx[dest];

        pq.push({0, {start_idx, '\0'}});
        dist[start_idx]['\0'] = 0;
        
        bool possible = false;
        int shortestLength = INF;

        while (!pq.empty()) {
            State curr_state = pq.top();
            pq.pop();

            int curr_dist = curr_state.first;
            int curr_node = curr_state.second.first;
            char last_letter = curr_state.second.second;

            if (curr_node == dest_idx) {
                shortestLength = curr_dist;
                possible = true;
                break;
            }

            // not best known dist
            if (curr_dist > dist[curr_node][last_letter]) continue;

            for (auto &edge: graph[curr_node]) {
                if (edge.second == last_letter) {
                    continue;
                }

                int new_dist = curr_dist + edge.first.second;

                if (dist[edge.first.first].find(edge.second) == dist[edge.first.first].end() ||
                    new_dist < dist[edge.first.first][edge.second]) {
                    // if we dont have the distance of the currnode to edge with this letter yet, add
                    // or if the new dist is better, update.

                    dist[edge.first.first][edge.second] = new_dist;
                    pq.push({new_dist, {edge.first.first, edge.second}});
                }
            }
        }

        if (possible) {
            cout << shortestLength << endl;
        } else {
            cout << "impossivel" << endl;
        }
    }
}