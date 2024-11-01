#include <bits/stdc++.h>

using namespace std;

int main(void) {
    vector<int> dps;
    vector<int> size;
    vector<int> category;
    int barrack;

    int temp;
    int garbage;
    scanf("%d", &temp);
    dps.push_back(temp);
    while ((garbage = getchar()) != '\n') {
        scanf("%d", &temp);
        dps.push_back(temp);
    }
    
    scanf("%d", &temp);
    size.push_back(temp);
    while ((garbage = getchar()) != '\n') {
        scanf("%d", &temp);
        size.push_back(temp);
    }

    scanf("%d", &temp);
    category.push_back(temp);
    while ((garbage = getchar()) != '\n') {
        scanf("%d", &temp);
        category.push_back(temp);
    }

    scanf("%d", &barrack);

    
}