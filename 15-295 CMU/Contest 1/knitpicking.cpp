#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    map<string, map<string, int>> socks; // type -> (fit -> count)
    
    for (int i = 0; i < n; i++) {
        string type, fit;
        int count;
        cin >> type >> fit >> count;
        socks[type][fit] += count;
    }
    
    bool possible = false;
    
    for (const auto& [type, fits] : socks) {
        int left = fits.count("left") ? fits.at("left") : 0;
        int right = fits.count("right") ? fits.at("right") : 0;
        int any = fits.count("any") ? fits.at("any") : 0;
        
        if ((left > 0 && right > 0) || 
            (left > 0 && any > 0)   || 
            (right > 0 && any > 0)  || 
            (any >= 2)
            ) {
            possible = true;
            break;
        }
    }
    
    if (!possible) {
        cout << "impossible" << endl;
        return;
    }
    
    int answer = 0;    
    for (const auto& [type, fits] : socks) {
        int left = fits.count("left") ? fits.at("left") : 0;
        int right = fits.count("right") ? fits.at("right") : 0;
        int any = fits.count("any") ? fits.at("any") : 0;
        
        // left + right pair
        if (left > 0 || right > 0) {
            answer += max(left, right);
        } else if (any > 0) {
            answer++;
        }
    }
    
    // since is possible, we can pick any socket
    cout << answer + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;

    while (tc--) {
        solve();
    }
    return 0;
}
