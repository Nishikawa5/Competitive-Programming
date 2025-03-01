#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> arr) {
    for (auto &n: arr) {
        cout << n << " ";
    }
    cout << endl;
}

/*
Could have used a long long int to compare instead of a vector, since comparing them works the same
and we would have at most 10 digits
*/

vector<int> treatInput() {
    string classes;
    getchar();
    // could get the line until '-' and '\n'
    getline(cin, classes);
    
    vector<int> treated_classes;
    int i = 0;
    while (!i || classes[i - 1] != ' ') {
        if (classes[i] == 'u') {
            treated_classes.push_back(3);
        } else if (classes[i] == 'm') {
            treated_classes.push_back(2);
        } else if (classes[i] == 'l') {
            treated_classes.push_back(1);
        }
        while (classes[i] != '-' && classes[i] != ' ') {
            i++;
        }
        i++;
    }
    reverse(treated_classes.begin(), treated_classes.end());

    return treated_classes;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        vector<pair<string, vector<int>>> people(n);

        for (int i = 0; i < n; i++) {
            cin >> people[i].first;
            people[i].first[people[i].first.size() - 1] = '\0';
            people[i].second = treatInput();
        }

        sort(people.begin(), people.end(), [&] (pair<string, vector<int>> a, pair<string, vector<int>> b) {
            int i = 0;
            while (i < a.second.size() || i < b.second.size()) {
                int curr_a = 2;
                int curr_b = 2;
                if (i < a.second.size()) {
                    curr_a = a.second[i];
                }
                if (i < b.second.size()) {
                    curr_b = b.second[i];
                }

                i++;
                if (curr_a < curr_b) {
                    return false;
                } else if (curr_a > curr_b) {
                    return true;
                }
            }
            return a.first < b.first;
        });

        for (int i = 0; i < n; i++) {
            cout << people[i].first << endl;
        }
        cout << "==============================" << endl;
    }
}