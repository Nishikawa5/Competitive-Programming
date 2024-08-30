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
    long long total_time = assignments[0].first.second;
    for (int i = 1; i < n; i++) {
        // verifica se o assignments[i] pode ir para esquerda
        total_time += assignments[i].first.second;
        long long curr_time = total_time;
        int curr_asg = i;
        while (curr_asg > 0 && assignments[curr_asg].second < assignments[curr_asg - 1].second &&
               curr_time <= assignments[curr_asg - 1].first.first) {
            swap(assignments[curr_asg], assignments[curr_asg - 1]);
            curr_time -= assignments[curr_asg - 1].first.second;
            curr_asg--;
        }
    }


    for (int i = 0; i < n; i++) {
        cout << assignments[i].second << " ";
    }
    cout << endl;
}