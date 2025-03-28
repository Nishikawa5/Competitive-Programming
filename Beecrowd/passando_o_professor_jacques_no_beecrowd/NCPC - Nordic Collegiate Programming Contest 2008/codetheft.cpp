#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> code_to_idx;
int unique_codes = 0;

void printvec(vector<int> v) {
    for (auto n: v) {
        cout << n << " ";
    }
    cout << endl;
}

void get_code(vector<int> &code) {
    string curr_line;
    while (getline(cin, curr_line) && curr_line != "***END***") {
        string formatted_line;
        // format this line of code
        // ignore leading and trailing spaces
        int start = 0;
        int end = curr_line.size() - 1;
        while (curr_line[start] == ' ' && start < curr_line.size()) start++;
        while (curr_line[end] == ' ' && end >= 0) end--;

        
        // conseq space char inside lines are treated as one single space even for strings?
        // i will consider it is
        int i = start;
        while (i <= end) {
            formatted_line.push_back(curr_line[i]);
            if (curr_line[i] == ' ') {
                i++;
                while (curr_line[i] == ' ' && i <= end) i++;
            } else {
                i++;
            }
        }


        if (!(formatted_line.empty() || formatted_line == " ")) {
            
            if (code_to_idx.find(formatted_line) == code_to_idx.end()) {
                code_to_idx[formatted_line] = ++unique_codes;
            }
            
            code.push_back(code_to_idx[formatted_line]);
        }
    }
}

int find_longest_match(vector<int> &code, vector<int> &snippet) {
    unordered_map<int, vector<int>> snippet_pos;
    for (int i = 0; i < snippet.size(); i++) {
        snippet_pos[snippet[i]].push_back(i);
    }

    int longest = 0;
    for (int line = 0; line < code.size(); line++) {
        // start at this line
        
        if (snippet_pos.find(code[line]) != snippet_pos.end()) {
            // found this line in the snippet

            for (auto start_pos: snippet_pos[code[line]]) {
                int curr_conseq = 0;

                // start at st index of snippet

                int i = line;
                int j = start_pos;

                while (i < code.size() && j < snippet.size() && code[i] == snippet[start_pos]) {
                    curr_conseq++;
                    i++; 
                    start_pos++;
                }
                longest = max(longest, curr_conseq);
            }
        }
    }
    return longest;
}


int main() {
    int n;
    cin >> n;

    string dummy;
    getline(cin, dummy);

    vector<vector<int>> codes(n);
    vector<pair<string, int>> file_names;
    for (auto &code: codes) {
        string name;
        getline(cin, name);
        
        // first is always the name
        file_names.push_back({name, 0});

        get_code(code);
    }

    // got all the codes, so lets compare them
    vector<int> code_snippet;
    
    get_code(code_snippet);


    int max_match = 0;
    for (int i = 0; i < n; i++) {
        file_names[i].second = find_longest_match(codes[i], code_snippet);
        
        max_match = max(max_match, file_names[i].second);
    }

    if (max_match > 0) {
        cout << max_match;
        for (int i = 0; i < n; i++) {
            if (file_names[i].second == max_match) {
                cout << " " << file_names[i].first; 
            }
        }
        cout << endl;
    } else {
        cout << 0 << endl;
    }
}