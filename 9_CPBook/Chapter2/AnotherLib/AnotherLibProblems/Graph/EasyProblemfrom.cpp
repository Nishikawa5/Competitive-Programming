#include <bits/stdc++.h>

using namespace std;

/*
Solution 2 is better because we don't have to allocate space for n elements in vector
*/

int solution2(void) {
    int n, m;

    while (scanf("%d %d", &n, &m) != EOF) {
        unordered_map<int, vector<int>> graph;

        int number;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &number);
            
            graph[number].push_back(i);
        }

        int k, v;
        while (m--) {
            scanf("%d %d", &k, &v);
            
            if (graph[v].size() >= k) {
                printf("%d\n", graph[v][k - 1]);
            } else {
                printf("0\n");
            }
        }
    }
}




int main(void) {
    int n, m;

    while (scanf("%d %d", &n, &m) != EOF) {
        vector<vector<int>> graph(n + 1);
        map<int, int> numbertoindex;

        int number;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &number);
            
            if (!numbertoindex[number]) {
                numbertoindex[number] = i;
            }

            graph[numbertoindex[number]].push_back(i);
        }

        int k, v;
        while (m--) {
            scanf("%d %d", &k, &v);
            if (numbertoindex[v]) {
                vector<int> vec = graph[numbertoindex[v]];

                if (vec.size() < k) {
                    printf("0\n");
                } else {
                    printf("%d\n", vec[k - 1]);
                }
            } else {
                printf("0\n");
            }
        }
    }
}