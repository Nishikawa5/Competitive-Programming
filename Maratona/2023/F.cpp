#include <bits/stdc++.h>
using namespace std;

int main() {
    int disposicao, cans_num, rev_num;
    cin >> disposicao >> cans_num >> rev_num;
    int rst = rev_num;

    vector<int> cans(cans_num);
    for (auto &x: cans) {
        cin >> x;
    }

    while (rev_num--) {
        int rev;
        cin >> rev;
        disposicao += rev;
    }
    
    int i = 0;
    while (i < cans.size() && cans[i] <= disposicao) {
        disposicao -= cans[i++];
        rst++;
    }
    cout << rst;
}