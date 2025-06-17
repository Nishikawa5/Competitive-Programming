#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    long long a1, a2, a3; // Alice
    long long b1, b2, b3; // Bob

    cin >> n;
    cin >> a1 >> a2 >> a3;
    cin >> b1 >> b2 >> b3;

    // Alice wins
    long long max_wins = 0;
    max_wins += min(a1, b2);
    max_wins += min(a2, b3);
    max_wins += min(a3, b1);

    // a win is forced only if Alice has a move type (rock), but Bob has
    // run out of moves that can draw (rock) or win (paper) 
    // the remaining moves for Bob must be scissors, forcing Alice to win
    
    // so we can calculated it like that
    // lets say alice has a_i > b_i + b_(i+2)%3
    // so bob uses all b_i + b_(i+2)%3 moves versus that a_i
    // and alice must get a_i - (b_i + b_(i+2)%3) wins
    // but now for the rest of the alice moves there's no problem
    // since a_(i+1)%3 + a_(i+1)%3 == rest of b_(i+1)%3
    // and alice can just mitigate her wins
    // therefore, just one of these 3 equations sums a number != 0 
    long long min_wins = 0;
    min_wins += max(0LL, a1 - (b1 + b3));
    min_wins += max(0LL, a2 - (b2 + b1));
    min_wins += max(0LL, a3 - (b3 + b2));
    
    cout << min_wins << " " << max_wins << endl;
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