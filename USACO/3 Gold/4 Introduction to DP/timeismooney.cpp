#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("time.in", "r", stdin);
	freopen("time.out", "w", stdout);

    int MAX_DAYS = 1000;    // 1000t - t^2 < 0 <=> t > 1000
    int cities_num, roads_num, cost;
    cin >> cities_num >> roads_num >> cost;

    vector<int> moonies(cities_num);
    for (int &m: moonies) {
        cin >> m;
    }

    // every city that goes to graph[i];
    vector<vector<int>> graph(cities_num);
    for (int i = 0; i < roads_num; i++) {
        int c1, c2;
        cin >> c1 >> c2;
        graph[c1 - 1].push_back(c2 - 1);
    }

    int max_profit = 0;
    vector<vector<int>> maxmoney_day_city(MAX_DAYS + 1, vector<int>(cities_num, INT_MIN));
    maxmoney_day_city[0][0] = 0;
    for (int day = 0; day < MAX_DAYS; day++) {
        for (int city = 0; city < cities_num; city++) {
            if (maxmoney_day_city[day][city] != INT_MIN) {
                for (int goto_city: graph[city]) {
                    maxmoney_day_city[day + 1][goto_city] = max(maxmoney_day_city[day + 1][goto_city], 
                                                                (maxmoney_day_city[day][city] + moonies[goto_city]));
                }
            }
        }
        if (maxmoney_day_city[day][0] != INT_MIN) {
            max_profit = max(max_profit, (maxmoney_day_city[day][0] - (cost * day * day)));
        }
    }

    cout << max_profit << endl;
}