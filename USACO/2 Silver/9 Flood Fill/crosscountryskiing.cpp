#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> steps = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int first_true(int lo, int hi, function<bool(int)> f) {
	hi++;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (f(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

void floodfill(int i, int j, vector<vector<int>> &heights, vector<vector<bool>> &visited, int d) {
    visited[i][j] = true;
    for (int k = 0; k < 4; k++) {
        int visit_i = i + steps[k].first;
        int visit_j = j + steps[k].second;

        if (!(visit_i < 0 || visit_i >= heights.size() || visit_j < 0 || visit_j >= heights[i].size()) &&
            !visited[visit_i][visit_j] && (abs(heights[i][j] - heights[visit_i][visit_j]) <= d)) {
            
            floodfill(visit_i, visit_j, heights, visited, d);
        }
    }
}

int main() {
    freopen("ccski.in", "r", stdin);
	freopen("ccski.out", "w", stdout);

    int dim1, dim2;
    cin >> dim1 >> dim2;

    vector<vector<int>> heights(dim1, vector<int>(dim2));
    for (vector<int> &vec: heights) {
        for (int &h: vec) {
            cin >> h;
        }
    }

    vector<pair<int, int>> waypoints;
    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim2; j++) {
            bool dummy;
            cin >> dummy;

            if (dummy) {
                waypoints.push_back({i, j});
            }
        }
    }

    // bin search pattern F F F F ... F T T ... T
    // find the first true
    auto f = [&](int d) {
        if (waypoints.empty()) return true;

        vector<vector<bool>> visited(dim1, vector<bool>(dim2));
        pair<int, int> start = waypoints[0];
        floodfill(start.first, start.second, heights, visited, d);

        for (auto &w: waypoints) {
            if (!visited[w.first][w.second]) {
                return false;
            }
        }
        return true;
    };

    cout << first_true(0, 1e9, f) << endl;
}