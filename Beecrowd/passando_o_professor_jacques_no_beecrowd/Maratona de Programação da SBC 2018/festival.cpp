#include <bits/stdc++.h>
using namespace std;

struct Show{
    int start, end;
    int musics;
    int stage;
};
bool operator< (Show a, Show b) {
    if (a.start != b.start) {
        return a.start < b.start;
    }
    return a.end < b.end;
}

int fill_dp(int curr_pos, int mask, int stage_num, int total_shows, vector<int> &next_show, vector<Show> &shows, vector<vector<int>> &dp) {

    if (curr_pos >= total_shows) {
        if (mask == (1 << stage_num) - 1) {
            return 0;
        } else {
            return INT_MIN;
        }
    }

    if (dp[curr_pos][mask] != -1) {
        // already calculated and just one calculation is possible
        return dp[curr_pos][mask];
    }

    int ignore_curr_pos = fill_dp(curr_pos + 1, mask, stage_num, total_shows, next_show, shows, dp);
    int use_curr_pos = shows[curr_pos].musics + 
                       fill_dp(next_show[curr_pos], mask | (1 << shows[curr_pos].stage), stage_num, total_shows, next_show, shows, dp);

    dp[curr_pos][mask] = max(ignore_curr_pos, use_curr_pos);
    return dp[curr_pos][mask];
}


void solve() {
    // 525 + 13 + 90 + 231
    // intersections occurs just in different stages

    // 10 * 1000 * 3
    int stage_num;
    cin >> stage_num;

    vector<Show> shows;
    int total_shows = 0;
    for (int i = 0; i < stage_num; i++) {
        int shows_num;
        cin >> shows_num;

        for (int j = 0; j < shows_num; j++) {
            Show s;
            cin >> s.start >> s.end >> s.musics;
            s.stage = i;

            shows.push_back(s);
            total_shows++;
        }
    }

    // sort by ending time to create next array
    sort(shows.begin(), shows.end());

    // dp[position][mask representing the visited stages]
    vector<vector<int>> dp(total_shows, vector<int>(1<<stage_num, -1));

    // which show is the next after this one?
    vector<int> next_show(total_shows);

    for (int i = 0; i < total_shows; i++) {
        next_show[i] = total_shows;

        for (int j = i+1; j < total_shows; j++) {
            if (shows[j].start >= shows[i].end) {
                next_show[i] = j;
                break;
            }
        }
    }

    int ans = fill_dp(0, 0, stage_num, total_shows, next_show, shows, dp);

    cout << max(-1, ans) << endl;
}




int main() {
    solve();
}