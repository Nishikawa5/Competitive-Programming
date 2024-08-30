#include <bits/stdc++.h>

using namespace std;

/*
2D grass w/ N cows

North ^
East  >

Cow either stop if grass eaten
           eat all grass and move one cell forward

output: grass eaten
*/
int main(void) {
    int N;

    cin >> N;

    vector<pair<char, pair<int, int>>> cows;
    
    for (int i = 0; i < N; i++) {
        pair<char, pair<int, int>> cow;
        cin >> cow.first >> cow.second.first >> cow.second.second;
        cows.push_back(cow);
    }

    // for north cow:
    // xce > xcn
}