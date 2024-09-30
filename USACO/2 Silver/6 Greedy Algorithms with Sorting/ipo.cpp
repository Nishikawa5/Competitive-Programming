#include <bits/stdc++.h>
using namespace std;

/*
max after fin k proj
*/
int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int max_proj = k;
    int curr_capital = w;
    int n = profits.size();

    vector<pair<int, int>> project(n);
    for (int i = 0; i < n; i++) {
        project[i] = {capital[i], profits[i]};
    }
    sort(project.begin(), project.end());

    priority_queue<int> curr_doable;
    int idx = 0;
    while (max_proj--) {
        // add the doable projects
        while (idx < n && project[idx].first <= curr_capital) {
            curr_doable.push(project[idx++].second);
        }
        if (curr_doable.empty()) {
            // can't do any projects with current capital, so break
            break;
        }

        // do the best project
        curr_capital += curr_doable.top();
        curr_doable.pop();
    }
    
    return curr_capital;
}