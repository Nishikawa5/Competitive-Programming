#include <bits/stdc++.h>

using namespace std;

/*
Focus on smaller moves first
*/
int getIndex(vector <int> weights, int weight) {
    for (int i = 0; i < weights.size(); i++) {
        if (weights[i] == weight) return i;
    }
    return -1;
}

void printVector(vector <int> v) {
    for (int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(void) {
    int n;
    int office;
    int weight;

    scanf("%d %d", &n, &office);
    vector <int> weights;
    vector <int> sortedweights;
    getchar();
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight);
        getchar();
        weights.push_back(weight);
        sortedweights.push_back(weight);
    }

    sort(sortedweights.begin(), sortedweights.end());
    int minweight = sortedweights[0];
    int maxweight = sortedweights[n - 1];

    // change the weights to make the maxweight closest to office
    int temp = sortedweights[office - 1];
    for (int i = office; i < n; i++) {
        int temp2 = sortedweights[i];
        sortedweights[i] = temp;
        temp = temp2;
    }
    sortedweights[office - 1] = maxweight;

    // we can change by moving the minimum or just exchange 2 weights
    // go through all the vector and see which change would be the minimum change
    // then assume that the change has been done, mark this change as done
    int changes = n;
    bool *changed = (bool *) malloc(sizeof(bool) * n);
    memset(changed, 0, sizeof(bool) * n);
    for (int i = 0; i < n; i++) {
        if (weights[i] == sortedweights[i]) {
            changed[i] = true;
            changes--;
        }
    }

    int totalchanges = 0;
    for (int i = 0; i < changes; i++) {
        // have to do n changes max
        int from;
        int to;
        int minchange = INT_MAX;
        for (int i = 0; i < n; i++) {
            // find the smallest change
            if (!changed[i]) {
                if (minchange > sortedweights[i] * weights[i]) {
                    minchange = sortedweights[i] * weights[i];
                    from = i;
                }
                int mintemp = min(sortedweights[i], weights[i]);
                if (minchange > minweight * (mintemp + sortedweights[i] + weights[i])) {
                    minchange = minweight * (mintemp + sortedweights[i] + weights[i]);
                    from = i;
                }
            }
        }
        to = getIndex(weights, sortedweights[from]);

        int ctemp = weights[from];
        weights[from] = weights[to];
        weights[to]   = ctemp;
        
        changed[from] = true;
        if (weights[to] == sortedweights[to]) {
            changed[to] = true;
            i++;
        }

        totalchanges += minchange;
    }
    printf("%d\n", totalchanges);
}