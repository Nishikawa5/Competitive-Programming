#include <bits/stdc++.h>
using namespace std;

/*
A[i] == ?
count it

make a map counting the A[i] and then increase by map[?] 
*/
int main() {
    int n;
    cin >> n;

    unordered_map<int, int> count;
    vector<int> B(n + 1);
    long int pairnum = 0;

    for (int i = 0; i < n; i++) {
        int Ai;
        cin >> Ai;
        count[Ai]++;
    }

    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }
    
    for (int i = 0; i < n; i++) {
        int Ci;
        cin >> Ci;

        pairnum += count[B[Ci]];
    }
    cout << pairnum << endl;
}