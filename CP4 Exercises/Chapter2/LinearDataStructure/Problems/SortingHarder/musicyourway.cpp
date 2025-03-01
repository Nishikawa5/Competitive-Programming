#include <bits/stdc++.h>
using namespace std;

/*
stable sort

some order:
song title
artist name
same attribute same order
*/

void printStr(vector<string> v) {
    cout << v[0];
    for (int i = 1; i < v.size(); i++) {
        cout << " " << v[i];
    }
    cout << endl;
}


int main() {
    unordered_map<string, int> attribute_to_idx;
    string attribute;
    vector<string> attributes;

    char c;
    int i = 0;
    do {
        cin >> attribute;
        attributes.push_back(attribute);
        attribute_to_idx[attribute] = i++;
        c = getchar();
    } while (c != '\n');
    int n;
    cin >> n;
    vector<vector<string>> data(n, vector<string>(i));
    for (vector<string> &str_vet: data) {
        for (string &str: str_vet) {
            cin >> str;
        }
    }

    int sort_num;
    cin >> sort_num;
    vector<string> sort_order(sort_num);
    for (string &str: sort_order) {
        cin >> str;
    }

    for (string &curr_sort: sort_order) {
        printStr(attributes);
        
        // sort by curr_sort idx
        stable_sort(data.begin(), data.end(), [&] (vector<string> a, vector<string> b) {
            return a[attribute_to_idx[curr_sort]] < b[attribute_to_idx[curr_sort]];
        });

        for (vector<string> &attr: data) {
            printStr(attr);
        }
        if (curr_sort != sort_order.back()) {
            cout << endl;
        }
    }
}