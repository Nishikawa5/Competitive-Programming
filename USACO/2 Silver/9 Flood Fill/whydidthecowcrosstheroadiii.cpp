#include <bits/stdc++.h>
using namespace std;

void printArrayInt(vector<vector<bool>> arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

vector<pair<int, int>> steps = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int direction(int a, int b, int c, int d) {
    if (a - c == 0 && b - d == 1) {
        return 0;
    } else if (a - c == 0 && b - d == -1) {
        return 1;
    } else if (a - c == 1 && b - d == 0) {
        return 2;
    } else {
        return 3;
    }
}

void floodfill(int curr_i, int curr_j, int &visited_cows, vector<vector<vector<int>>> &cantgo, vector<vector<bool>> &fields, vector<vector<bool>> &visited) {
    if (curr_i < 0 || curr_i >= fields.size() || curr_j < 0 || curr_j >= fields.size() || visited[curr_i][curr_j]) return;

    visited[curr_i][curr_j] = true;
    visited_cows += fields[curr_i][curr_j];

    for (int i = 0; i < 4; i++) {
        bool cango = true;
        for (int j = 0; j < cantgo[curr_i][curr_j].size(); j++) {
            if (cantgo[curr_i][curr_j][j] == i) {
                cango = false;
            }
        }

        if (cango) {
            floodfill(curr_i + steps[i].first, curr_j + steps[i].second, visited_cows, cantgo, fields, visited);
        }
    }
}

int main() {
    freopen("countcross.in", "r", stdin);
	freopen("countcross.out", "w", stdout);

    int fields_num, cows_num, roads_num;
    cin >> fields_num >> cows_num >> roads_num;

    vector<vector<vector<int>>> cantgo(fields_num, vector<vector<int>>(fields_num));

    while (roads_num--) {
        int from_i, from_j, to_i, to_j;
        cin >> from_i >> from_j >> to_i >> to_j;

        from_i--; from_j--; to_i--; to_j--;

        cantgo[from_i][from_j].push_back(direction(from_i, from_j, to_i, to_j));
        cantgo[to_i][to_j].push_back(direction(to_i, to_j, from_i, from_j));
    }
    
    vector<vector<bool>> fields(fields_num, vector<bool>(fields_num, false));
    vector<pair<int, int>> cow_positions(cows_num);
    for (int i = 0; i < cows_num; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        fields[a][b] = true;
        cow_positions[i] = {a, b};
    }

    vector<vector<bool>> visited(fields_num, vector<bool>(fields_num, false));

    int distant_pairs = 0;
    int cows_seen = 0;
    for (int i = 0; i < cow_positions.size(); i++) {
        if (!visited[cow_positions[i].first][cow_positions[i].second]) {
            int visited_cows = 0;
            floodfill(cow_positions[i].first, cow_positions[i].second, visited_cows, cantgo, fields, visited);

            distant_pairs += visited_cows * (cows_num - cows_seen - visited_cows);
            cows_seen += visited_cows;
        }
    }
    cout << distant_pairs << endl;
}