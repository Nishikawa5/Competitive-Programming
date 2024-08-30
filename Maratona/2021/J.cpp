#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
ll lin_perimeter(ll x, ll y, ll w, ll h) {
    if (y == h) return x;
    if (x == w) return w + h - y;
    if (y == 0) return w + h + w - x;
    if (x == 0) return w + h + w + y;
    return -1;
}
 
// indices de perimetros diferentes nao podem cruzar
int main() {
    ios::sync_with_stdio(0);
    int w, h, n;    
    cin >> w >> h >> n;
 
    vector<pair<ll, int>> ordered_perimeter;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll p1 = lin_perimeter(x1, y1, w, h);
        ll p2 = lin_perimeter(x2, y2, w, h);
        if (p1 >= 0 && p2 >= 0) {
            ordered_perimeter.push_back({p1, i});
            ordered_perimeter.push_back({p2, i});
        }
    }
    sort(ordered_perimeter.begin(), ordered_perimeter.end());
 
    stack<int> ord;
    bool valid = true;
    for (int i = 0; i < ordered_perimeter.size(); i++) {
        if (ord.empty() || ord.top() != ordered_perimeter[i].second) {
            ord.push(ordered_perimeter[i].second);
        } else {
            ord.pop();
        }
    }
 
    if (ord.empty()) {
        cout << "Y\n";
    } else {
        cout << "N\n";
    }
}