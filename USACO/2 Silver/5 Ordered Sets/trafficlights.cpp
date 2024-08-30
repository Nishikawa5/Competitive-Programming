#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int passage_length, set_num;
    cin >> passage_length >> set_num;

    set<int> light_pos;
    multiset<int> passages_without_tl_len;
    light_pos.insert(0);
    light_pos.insert(passage_length);
    passages_without_tl_len.insert(passage_length);

    for (int i = 0; i < set_num; i++) {
        int curr_pos;
        cin >> curr_pos;

        // always works, since 0 < pi < x
        auto curr_pos_ub = light_pos.upper_bound(curr_pos);
        auto curr_pos_lb = curr_pos_ub;
        --curr_pos_lb;
        // erase this length
        int erase_len = *curr_pos_ub - *curr_pos_lb;
        passages_without_tl_len.erase(passages_without_tl_len.find(erase_len));
        // insert the new lengths
        passages_without_tl_len.insert(curr_pos - *curr_pos_lb);
        passages_without_tl_len.insert(*curr_pos_ub - curr_pos);
        light_pos.insert(curr_pos);

        auto ans = passages_without_tl_len.end();
        --ans;
        cout << *ans << " ";
    }
}