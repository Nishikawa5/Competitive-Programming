#include <bits/stdc++.h>
using namespace std;

int main() {
    int num_heights;
    cin >> num_heights;
    vector<int> heights(num_heights);
    for (auto &h: heights) {
        cin >> h;
    }

    auto f = [&] (vector<int> every_height) {
        stack<pair<int, int>> heights;
        int max_diff = 0;
        for (int i = 0; i < every_height.size(); i++) {
            pair<int, int> curr_height;
            curr_height.first = every_height[i];
            // minimum height
            curr_height.second = curr_height.first;

            if (!heights.empty()) {
                while (!heights.empty() && heights.top().first <= curr_height.first) {
                    pair<int, int> top_stack = heights.top();
                    max_diff = max(max_diff, top_stack.first - top_stack.second);
                    heights.pop();

                    if (!heights.empty()) {
                        heights.top().second = min(heights.top().second, top_stack.second);
                    }
                }
            }
            heights.push(curr_height);
        }
        return max_diff;
    };

    int max_diff = 0;
    max_diff = f(heights);
    reverse(heights.begin(), heights.end());
    max_diff = max(max_diff, f(heights));
    cout << max_diff << endl;
}