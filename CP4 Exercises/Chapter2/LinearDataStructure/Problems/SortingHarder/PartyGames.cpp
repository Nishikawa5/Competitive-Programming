#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;

    while (cin >> n && n) {
        vector<string> names(n);

        for (int i = 0; i < n; i++) {
            cin >> names[i];
        }
        sort(names.begin(), names.end());

        string midleft = names[names.size() / 2 - 1];
        string midright = names[names.size() / 2];

        string rst;
        int currSub = 0;
        while (rst.empty()) {
            // pick a substring of midleft from smallest size to greatest
            string temp = midleft.substr(0, currSub);
            temp.push_back('A');
            // make every combination and compare
            for (int i = 0; i < 26; i++) {
                if (midright > temp && temp >= midleft) {
                    rst = temp;
                    break;
                }
                temp[temp.size() - 1]++;
            }
            currSub++;
        }

        cout << rst << endl;
    }
}