#include <bits/stdc++.h>

using namespace std;

/*
Stable sort of strings using just 2 first chars

*/

// str1[0] > str2[0] || str1[0] == str2[0] && str1[1] > str2[1] => str1 > str2
bool compareStr(string str1, string str2) {
    return str1[0] > str2[0] || str1[0] == str2[0] && str1[1] > str2[1];
}

/*
Let's use bubble sort to make a stable sort
*/
void bubbleSort(vector<string> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size() - i - 1; j++) {

            if (compareStr(vec[j], vec[j + 1])) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

int main(void) {
    int n;
    bool nl = false;
    while (cin >> n && n) {
        if (nl) cout << endl;

        vector<string> names;
        string name;
        while (n--) {
            cin >> name;
            names.push_back(name);
        }

        bubbleSort(names);
        
        for (int i = 0; i < names.size(); i++) {
            if (i) cout << "\n";
            cout << names[i];
        }
        cout << "\n";

        nl = true;
    }
}