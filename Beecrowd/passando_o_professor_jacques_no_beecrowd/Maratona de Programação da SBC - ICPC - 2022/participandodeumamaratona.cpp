#include <bits/stdc++.h>
using namespace std;

void solve() {
    int num_runners;
    cin >> num_runners;
    vector<pair<int, int>> runners(num_runners);

    for (auto &r: runners) {
        cin >> r.first >> r.second;
    }

    int num_photos;
    cin >> num_photos;

    vector<pair<int, pair<int, int>>> photos(num_photos);
    vector<int> discarded(num_photos, true);
    int num_discarded = num_photos;
    
    for (auto &p: photos) {
        cin >> p.first >> p.second.first >> p.second.second;
    }
    // check the number of valid photos without the runners

    for (int i = 0; i < num_photos; i++) {
        for (int j = 0; j < num_runners; j++) {
            long long runner_position = 1LL * (photos[i].first - runners[j].first) * runners[j].second;
            if (runners[j].first <= photos[i].first &&
                ((long long)photos[i].second.first <= runner_position && runner_position <= (long long)photos[i].second.second)) {
                
                discarded[i] = false;
                num_discarded--;
                break;
            }
        }
    }

    int q;
    cin >> q;

    for (int j = 0; j < q; j++) {
        int start, speed;
        cin >> start >> speed;

        int curr_discarded = num_discarded;
            
        for (int i = 0; i < num_photos; i++) {
            long long runner_position = 1LL * (photos[i].first - start) * speed;
            
            if (start <= photos[i].first && discarded[i] &&
                ((long long)photos[i].second.first <= runner_position && runner_position <= (long long)photos[i].second.second)) {
                
                curr_discarded--;
            }
        }
        cout << curr_discarded << endl;
    }

}

int main() {
    solve();
}