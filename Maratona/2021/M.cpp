#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    vector<pair<pair<int, int>, int>> assignments(n);
    for (int i = 0; i < n; i++) {
        int time, deadline;
        cin >> time >> deadline;
        assignments[i].first.first = deadline;
        assignments[i].first.second = time;
        assignments[i].second = i + 1;
    }
 
    sort(assignments.begin(), assignments.end());
    // checa se e possivel resolver todos
    long long curr_time = 0;
    for (int i = 0; i < n; i++) {
        pair<int, int> asg = assignments[i].first;
        curr_time += asg.second;
        if (curr_time > asg.first) {
            // nao possivel
            cout << "*\n";
            return 0;
        }
    }
 
    // coloca na menor ordem lexicografica
    long long total_time = 0;
    while (!assignments.empty()) {
        int select = -1;
        int curr_time = total_time;
        // get the lowest index
        for (int i = 0, m = 1e9; i < assignments.size(); i++) {
            if (m >= assignments[i].first.second && (select == -1 || 
                assignments[i].second < assignments[select].second)) {
                
                select = i;
            }
 
            curr_time += assignments[i].first.second;
            m = min(m, assignments[i].first.first - curr_time);
        }
        total_time += assignments[select].first.second;
        cout << assignments[select].second << " ";
        assignments.erase(assignments.begin() + select);
    }
    cout << endl;
}