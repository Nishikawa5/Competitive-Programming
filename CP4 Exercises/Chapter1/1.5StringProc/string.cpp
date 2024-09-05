#include <cstring> // the same as <string.h> in C?
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>


using namespace std;

int p1(void) {
    string result = "";
    string line;

    getline(cin, line);
    while (line.rfind(".......", 0) != 0) {
        result += line;
        getline(cin, line);
    }
    
    printf("%s\n", result.c_str());
    cout << result << endl;
}

int P2(void) {
    string T;
    string P;
    vector <int> ind;

    getline(cin, T);
    getline(cin, P);

    int temp = -P.size();
    int i = 0;
    while(true) {
        temp = T.find(P, temp + P.size());
        if (temp == -1) break;
        ind.push_back(temp);
    }
    
    for (int i = 0; i < ind.size(); i++) {
        printf("%d\n", ind[i]);
    }
}


bool isIn(char c, string check) {
    for (int i = 0; i < check.size(); i++) {
        if (c == check[i]) return true;
    }
    return false;
}

int P3(void) {
    string T;
    string vowels = "aeiou";
    string conson = "qwrtypsdfghjklzxcvbnm";
    int vowel = 0;
    int conso = 0;
    int it = 0;

    getline(cin, T);

    while (T[it] != '\0') {
        if (T[it] >= 'A' && T[it] <= 'Z') T[it] += 32;

        if (isIn(T[it], vowels)) vowel++;
        else if (isIn(T[it], conson)) conso++;

        it++;
    }

    printf("%s\n%d\n%d\n", T.c_str(), vowel, conso);
}


int P4(void) {
    string T;
    vector <string> tokens;

    getline(cin, T);

    stringstream str(T);
    string word;
    while (str >> word) {
        tokens.push_back(word);
    }

    sort(begin(tokens), end(tokens));

    for (int i = 0; i < tokens.size(); i++) {
        printf("%s\n", tokens[i].c_str());
    }
}


int main(void) {
    string T;
    vector <string> tokens;
    unordered_map <string, int> map;
    int max = 0;
    string maxstr;

    getline(cin, T);

    stringstream str(T);
    string word;
    while (str >> word) {
        map[word]++;

        if (map[word] > max) {
            max = map[word];
            maxstr = word;
        }
    }

    printf("Word: %s\nTimes: %d\n", maxstr.c_str(), max);
}