#include <bits/stdc++.h>
using namespace std;

/*
grid customers x 'x'

we have two cases:
case 1:
assume ceil((a1 + a2 + ... + an) / x) = rows = customers >= max(a1, a2, ..., an)

we can make a matrix customers x 'x'
since customers >= max(a1, a2, ..., an) we can just fill the columns with car models
representing the cars the i-th customer bought

and the customers will always buy every car, since rows * columns >= total_cars

this is optimal since is the least amount of customers to buy every car not considering the model

case 2:
assume ceil((a1 + a2 + ... + an) / x) = rows = customers < max(a1, a2, ..., an)

now we cant fill every row of a column, we need at least max(a1, a2, ..., an) to be able to fill the rows
so with max(a1, a2, ..., an) customers we can fill all the rows and buy all cars, since
max(a1, a2, ..., an) * x > ceil((a1 + a2 + ... + an) / x) * x

*/

long long myceil(long long a, long long b) {
    return a / b + ((a % b) > 0);
}

void solve() {
    int n, x;
    cin >> n >> x;

    long long total_cars = 0;
    int max_car = 0;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;

        total_cars += c;
        max_car = max(max_car, c);
    }

    cout << max((long long)max_car, myceil(total_cars, x)) << endl;
}


int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}