
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    map<int, int> candies;
    for (int i = 0; i < n; i++) {
        int candy_power;
        cin >> candy_power;
 
        candies[candy_power]++;
        int curr_power = candy_power;
        while (candies[curr_power] >= 2) {
            candies[curr_power + 1] += candies[curr_power] / 2;
            candies[curr_power] %= 2;
            curr_power++;
        }
    }
 
    int powers = 0;
    for (auto c: candies) {
        if (c.second == 1) {
            powers++;
        }
    }
 
    if (candies.size() > 1 && powers <= 2) {
        cout << "Y" << endl;
    } else {
        cout << "N" << endl;
    }
}