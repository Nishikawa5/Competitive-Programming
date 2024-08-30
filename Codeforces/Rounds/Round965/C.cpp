#include <bits/stdc++.h>
using namespace std;

#define lli long long int

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        lli k;
        cin >> n >> k;

        vector<pair<lli, lli>> arr_add(n);
        for (int i = 0; i < n; i++) {
            cin >> arr_add[i].first;
        }
        for (int i = 0; i < n; i++) {
            cin >> arr_add[i].second;
        }
        sort(arr_add.begin(), arr_add.end(), [&](pair<lli, lli> a, pair<lli, lli> b) {
            if (a.first == b.first) {
                return b.second < a.second;
            } else {
                return a.first < b.first;
            }
        });

        lli max_score = 0;
        int median = (arr_add.size() + 1) / 2 - 1;

        int greatest_add1 = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (arr_add[i].second) {
                greatest_add1 = i;
                break;
            }
        }

        // test for the case we are adding everything in the greatest add1
        if (greatest_add1 != -1) {
            int curr_median = median;
            if (arr_add.size() % 2) {
                if (greatest_add1 >= median) {
                    curr_median--;
                }
            } else {
                if (greatest_add1 <= median) {
                    curr_median++;
                }
            }
            max_score = (arr_add[curr_median].first + max(arr_add[greatest_add1].first + k, arr_add[arr_add.size() - 1].first));
        }

        // if we increase the right we don't have to increase de median
        // lets see if it is ok to increase the median them
        // case 1: we increase left_add1
        if (arr_add.size() % 2) {
            median--;
        }

        max_score = max(max_score, arr_add[median].first + arr_add[arr_add.size() - 1].first);

        int closest_add1 = -1;
        int second_closest_add1 = -1;
        for (int i = median; i >= 0; i--) {
            if (arr_add[i].second && closest_add1 == -1) {
                closest_add1 = i;
            } else if (arr_add[i].second) {
                second_closest_add1 = i;
                break;
            }
        }
        
        if (closest_add1 != -1) {
            lli max_add = 0;
            if (arr_add[closest_add1].first + k > arr_add[median + 1].first) {
                // median + 1 is now the median
                max_add = arr_add[median + 1].first - arr_add[median].first;
                lli curr_k = arr_add[closest_add1].first + k - arr_add[median + 1].first;
                
                if (arr_add[median + 1].second) {
                    // both increase
                    max_add += curr_k / 2;
                } else if (arr_add[second_closest_add1].second != -1) {
                    // the one before increase till them and both increase
                    curr_k -= arr_add[median + 1].first - arr_add[second_closest_add1].first;
                    max_add += curr_k / 2;
                }
            } else {
                // closest_add1 is the median
                max_add = arr_add[closest_add1].first + k - arr_add[median].first;
            }
            max_score = max(max_add + (arr_add[median].first + arr_add[arr_add.size() - 1].first), max_score);
        }
        cout << max_score << endl;
    }
}