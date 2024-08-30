#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> string_day;

int next_renew(int &start_day, int days_passed, int curr_day) {

    if (start_day == 0 && curr_day - days_passed >= 91) {
        // cicles
        return ((curr_day - days_passed) / 91) * 91;
    } else if (start_day == 4) {
        start_day = 0; // (31 % 7 + start_day) % 7;
        return 31;
    } else if (start_day == 3) {
        start_day = 0; // (32 % 7 + start_day) % 7;
        return 32;
    }
    start_day += 2; // (30 % 7 + start_day) % 7;
    start_day %= 7;
    return 30;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    string_day["Mon"] = 0;
    string_day["Tue"] = 1;
    string_day["Wed"] = 2;
    string_day["Thu"] = 3;
    string_day["Fri"] = 4;
    string_day["Sat"] = 5;
    string_day["Sun"] = 6;

    string day;
    cin >> day;
    int start_day = string_day[day];

    int n;
    cin >> n;

    string max_start_day;
    int max_day = INT_MAX;
    bool can_get = false;
    while (n--) {
        int curr_start_day;
        int curr_day;
        cin >> curr_day;

        curr_start_day = (start_day - (curr_day % 7) + 7) % 7;

        int days_passed = 0;
        bool f = !curr_day;
        while ((days_passed < curr_day) || f) {
            days_passed += next_renew(curr_start_day, days_passed, curr_day);
            f = false;
        }

        max_day = min(max_day, days_passed - curr_day);
    }

    cout << max_day << endl;
}