#include <bits/stdc++.h>
using namespace std;

int main() {
    int tickets, buy_num;
    cin >> tickets >> buy_num;
    multiset<int> prices;
    
    while (tickets--) {
        int price;
        cin >> price;
        prices.insert(price);
    }
    
    while (buy_num--) {
        int max_price;
        cin >> max_price;
        auto it = prices.upper_bound(max_price);
        
        if (it == prices.begin()) {
            cout << -1 << endl;
        } else {
            cout << *(--it) << endl;
            prices.erase(it);
        }
    }
}