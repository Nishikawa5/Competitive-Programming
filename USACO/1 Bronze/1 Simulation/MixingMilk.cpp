#include <bits/stdc++.h>

using namespace std;

int main(void) {
    vector<pair<int, int>> bucket(3);

    for (int i = 0; i < 3; i++) {
        cin >> bucket[i].first >> bucket[i].second;
    }

    for (int i = 0; i < 100; i++) {
        if (bucket[i % 3].second + bucket[(i + 1) % 3].second <= bucket[(i + 1) % 3].first) {
            bucket[(i + 1) % 3].second += bucket[i % 3].second;
            bucket[i % 3].second = 0;
        } else {
            bucket[i % 3].second = bucket[i % 3].second + bucket[(i + 1) % 3].second - bucket[(i + 1) % 3].first;
            bucket[(i + 1) % 3].second = bucket[(i + 1) % 3].first;
        }
    }
    
    for (int i = 0; i < 3; i++) {
        cout << bucket[i].second << endl;
    }
}