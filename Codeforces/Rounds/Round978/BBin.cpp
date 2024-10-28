#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll first_true(ll lo, ll hi, function<bool(ll)> f) {
	hi++;
	while (lo < hi) {
		ll mid = lo + (hi - lo) / 2;
		if (f(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

/*
O(nlgn * 10)

barely passes (999ms)


*/
void solve() {
    int models, up_to;
    cin >> models >> up_to;

    vector<int> cars(models);
    for (auto &c: cars) {
        cin >> c;
    }

    cout << first_true(1, (LLONG_MAX / 32), [&](ll customers) {
        // check if this number of customers can buy all cars
        vector<ll> ith_car(up_to + 1, 0);
        ith_car[0] = customers;
        for (int i = 0; i < models; i++) {
            int curr_cars = cars[i];
            int j = 0;
            
            int next_change = 0;
            int k = 0;
            for (; curr_cars && k < ith_car.size() - 1; k++) {
                int temp = next_change;

                if (ith_car[k] >= curr_cars) {
                    next_change = curr_cars;
                    ith_car[k] -= curr_cars;
                    curr_cars = 0;
                } else {
                    next_change = ith_car[k];
                    curr_cars -= ith_car[k];
                    ith_car[k] = 0;
                }

                ith_car[k] += temp;
            }
            ith_car[k] += next_change;

            if (curr_cars != 0) {
                return false;
            }
        }

        return true;
    }) << endl;
}


int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }
}