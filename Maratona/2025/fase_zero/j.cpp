#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int filters_num;
    ll k;
    cin >> filters_num >> k;
    
    if (filters_num == 0) {
        cout << "\n";
        return;
    }
    
    vector<ll> filters(filters_num);
    for (int i = 0; i < filters_num; i++) {
        cin >> filters[i];
    }
    /*
    stopping condition:
        filters[start] + steps*K > filters[steps]
        =>
        steps = position - start

        filters[start] - start*K > filters[position] - position*K

        =>
        new condition:
        
        val[start] > val[position]

        for val[x] = filters[i % N] - x*K


    */
    
    // find all answers simultaneously
    // Val[x] = filters[x % N] - x * k
    // consider x up to 2N-1
    int val_arr_size = 2 * filters_num;
    vector<ll> val_arr(val_arr_size);
    
    for (int i = 0; i < val_arr_size; i++) {
        // fill the adjusted limit array
        val_arr[i] = filters[i % filters_num] - (ll)i * k;
    }
    
    vector<int> ans(filters_num);
    stack<int> st; // monotonic stack storing indices
    
    // 2N-1 down to 0
    for (int i = val_arr_size - 1; i >= 0; i--) {
        /*
        we start at the farthest idx
        and pop when we find a greater value with smaller idx
        */
        while (!st.empty() && val_arr[st.top()] >= val_arr[i]) {
            st.pop();
        }
    

        // if i is a starting particle index (0 to N-1)
        if (i < filters_num) {
            // the element at position i+N guarantees theres always a valid answer
            if (!st.empty()) {
                int p = st.top();
                ans[i] = (p % filters_num) + 1;
            } else {
                // this case shouldnt happen
                ans[i] = i;
            }
        }
        
        st.push(i);
    }
    
    for (int i = 0; i < filters_num; i++) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}