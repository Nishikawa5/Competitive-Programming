#include <bits/stdc++.h>
using namespace std;

/*
every possibility:
00
01
02
10
11
12
20
21
22

00 01 02
10 11 12
20 21 22

00 10 20
01 11 21
02 12 22

00 11 22
00 12 21
01 10 22
01 12 20
02 10 21
02 12 20

organizing:
00 01 02

00 10 20
00 11 22
00 12 21

01 11 21
01 10 22
01 12 20

02 12 22
02 10 21
02 12 20


only way i think rn:
 brute force:
  choose one from 0, another from 1 and another from 2. If possible, use every possible
  fig_num

const vector<array<array<int, 2>, 3>> VALIDCOMBINATIONS = {
    {{{0, 0}, {0, 1}, {0, 2}}},  // 00 01 02
    {{{0, 0}, {1, 1}, {2, 2}}},  // 00 11 22
    {{{0, 0}, {1, 2}, {2, 1}}},  // 00 12 21
    {{{0, 0}, {1, 0}, {2, 0}}},  // 00 10 20

    {{{0, 1}, {1, 1}, {2, 1}}},  // 01 11 21
    {{{0, 1}, {1, 0}, {2, 2}}},  // 01 10 22
    {{{0, 1}, {1, 2}, {2, 0}}},  // 01 12 20

    {{{0, 2}, {1, 2}, {2, 2}}},  // 02 12 22
    {{{0, 2}, {1, 0}, {2, 1}}},  // 02 10 21
    {{{0, 2}, {1, 1}, {2, 0}}},  // 02 11 20
};

shit that wont work, since we would also need  00          01            02 which is 12!


*/

int map_num(const string& s) {
    if (s == "um") return 0;
    if (s == "dois") return 1;
    if (s == "tres") return 2;
    return -1;
}

int map_fig(const string& s) {
    if (s == "circulo" || s == "circulos") return 0;
    if (s == "quadrado" || s == "quadrados") return 1;
    if (s == "triangulo" || s == "triangulos") return 2;
    return -1;
}

int get_third_type(int type1, int type2) {
    int num1 = type1 / 3;
    int fig1 = type1 % 3;
    
    int num2 = type2 / 3;
    int fig2 = type2 % 3;
    
    int num3, fig3;
    
    if (num1 == num2) {
        num3 = num1;
    } else {
        num3 = 3 - num1 - num2;
    }
    
    if (fig1 == fig2) {
        fig3 = fig1;
    } else {
        fig3 = 3 - fig1 - fig2;
    }
    
    return num3 * 3 + fig3;
}

string state_string(const vector<int>& card_count) {
    string s = "";
    for (int i = 0; i < 9; i++) {
        s += to_string(card_count[i]) + ",";
    }
    return s;
}

int backtrack(vector<int>& card_count, map<string, int>& memo) {
    string state = state_string(card_count);
    if (memo.count(state)) return memo[state];
    
    int max_sets = 0;
    
    for (int type1 = 0; type1 < 9; type1++) {
        if (card_count[type1] == 0) continue;
        
        for (int type2 = 0; type2 < 9; type2++) {
            if (type1 == type2 && card_count[type1] < 2) continue;
            if (type1 != type2 && card_count[type2] == 0) continue;
            
            int type3 = get_third_type(type1, type2);
            
            if (type3 == type1 && type1 == type2 && card_count[type1] < 3) continue;
            if (type3 == type1 && type1 != type2 && card_count[type1] < 2) continue;
            if (type3 == type2 && type1 != type2 && card_count[type2] < 2) continue;
            if (type3 != type1 && type3 != type2 && card_count[type3] == 0) continue;
            
            card_count[type1]--;
            card_count[type2]--;
            card_count[type3]--;
            
            int sets = 1 + backtrack(card_count, memo);
            max_sets = max(max_sets, sets);
            
            card_count[type1]++;
            card_count[type2]++;
            card_count[type3]++;
        }
    }
    
    memo[state] = max_sets;
    return max_sets;
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        vector<int> card_count(9, 0);  // 9 card types (3 nums x 3 figs)
        
        for (int i = 0; i < N; i++) {
            string num_str, fig_str;
            cin >> num_str >> fig_str;
            
            int num = map_num(num_str);
            int fig = map_fig(fig_str);
            
            int type = num * 3 + fig;
            card_count[type]++;
        }
        
        map<string, int> memo;
        int max_sets_count = backtrack(card_count, memo);
        
        cout << max_sets_count << endl;
    }
    
    return 0;
}