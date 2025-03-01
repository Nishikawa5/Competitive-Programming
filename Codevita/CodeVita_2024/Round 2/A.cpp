#include <bits/stdc++.h>
using namespace std;

int timeToMinutes(int hour, int minute, string period) {
    if (period == "PM" && hour != 12) {
        hour += 12;
    }
    if (period == "AM" && hour == 12) {
        hour = 0;
    }
    return hour * 60 + minute;
}

void solve() {
    int n;
    cin >> n;

    unordered_map<int, int> working_time;
    unordered_map<int, pair<int, string>> past_state_employee;
    unordered_map<int, bool> is_inconsistent;
    for (int i = 0; i < n; i++) {
        int employee;
        string action, place;
        cin >> employee >> action >> place;

        int hour, minute;
        char dummy;
        cin >> hour >> dummy >> minute;
        
        string period;
        cin >> period;

        int time = timeToMinutes(hour, minute, period);

        if (!working_time.count(employee)) {
            working_time[employee] = 0;
        }

        if (action == "enters") {
            if (past_state_employee.count(employee) && past_state_employee[employee].second != "") {
                if (past_state_employee[employee].second[0] == 'r') {
                    is_inconsistent[employee] = true;
                }
            }
            past_state_employee[employee] = {time, place};
        } else if (action == "exits") {
            if (!past_state_employee.count(employee) || past_state_employee[employee].second == "") {
                continue;
            }

            if (past_state_employee[employee].second == place) {
                if (place[0] == 'r') {
                    working_time[employee] += time - past_state_employee[employee].first;
                }
            } else {
                // inconsistent
                if (past_state_employee[employee].second[0] == 'r') {
                    is_inconsistent[employee] = true;
                }
            }
            past_state_employee[employee].first = 0;
            past_state_employee[employee].second = "";
        }
    }

    for (auto &employee: past_state_employee) {
        if (employee.second.second != "" && employee.second.second[0] == 'r') {
            is_inconsistent[employee.first] = true;
        }
    }

    int suspect;
    cin >> suspect;

    bool cannot = false;
    for (auto &wt: working_time) {
        if (working_time[suspect] > wt.second) {
            if (!is_inconsistent[wt.first]) {
                cout << "No\n";
                return;
            } else {
                cannot = true;
            }
        }
    }
    if (cannot) {
        cout << "Cannot be determined\n";
        return;
    }

    cout << "Yes\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;

    while (tc--) {
        solve();
    }
    return 0;
}
