#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int &h: heights) {
        cin >> h;
    }
    
    // direita pra esquerda armazenando se ha um balao nessa altura
    unordered_map<int, int> seen;
    int tot_arr = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (!seen[heights[i] - 1]) {
            // se ainda nao foi visto, atira outra flecha
            tot_arr++;
        } else {
            // pode ter 2 baloes na mesma altura
            seen[heights[i] - 1]--;
        }
        seen[heights[i]]++;
    }
    cout << tot_arr << endl;
}