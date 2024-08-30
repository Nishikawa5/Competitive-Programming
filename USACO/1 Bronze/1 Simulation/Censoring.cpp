#include <bits/stdc++.h>

using namespace std;

int main() {
    string text;
    string censor;
    cin >> text >> censor;

    string censored = "";

    for (int i = 0; i < text.size(); i++) {
        censored += text[i];
        
        // make the string censored never have the string to censor by seeing the last censor.size() letters
        if ((censored.size() >= censor.size()) && 
            (censored.substr(censored.size() - censor.size()) == censor)) {
            // delete the last censor.size() letters (string to censor)
            censored.resize(censored.size() - censor.size());
        }
    }
    cout << censored << endl;
}