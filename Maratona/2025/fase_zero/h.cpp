#include <bits/stdc++.h>
using namespace std;

#define ll long long

bitset<64> get_rhs(bitset<64> lhs, int numberofbitsov2) {
    bitset<64> rhs;

    for (int i = 0; i < numberofbitsov2; i++) {
        rhs[numberofbitsov2 - i - 1] = lhs[i];
    }
    return rhs;
}

void solve() {
    ll x;
    cin >> x;

    bitset<64> bits(x);

    int number_of_bits = 0;
    ll temp = x;
    while (temp) {
        number_of_bits++;
        temp >>= 1;
    }

    if (number_of_bits == 1 || number_of_bits == 0) {
        cout << x << endl;
        return;
    }

    // changes the number of bits iff is a power of 2
    else if (!(x & (x - 1))) {
        // is power of 2
        // and that is all ones
        cout << x-1 << endl;

        return;
    }

    // get the first nob/2
    bitset<64> lhs = bits >> (number_of_bits + 1)/2;
    
    // the mid bit if it has
    bitset<64> midbit = (x >> (number_of_bits/2)) & 0b1;

    bitset<64> rhs = get_rhs(lhs, number_of_bits - (number_of_bits + 1)/2);


    // now we have everything from left to mid
    // and now we have two options:
    // we can just get the inverted lhs
    // or we get the first bit that is 1, put 1's, then get the rest
    bitset<64> complete = (lhs << (number_of_bits+1)/2) | midbit << (number_of_bits/2) | rhs;


    ll value = complete.to_ullong();
    if (value > x) {
        ll new_lhs = ((lhs << (number_of_bits+1)/2) | (midbit << (number_of_bits/2))).to_ullong();


        new_lhs -= 1;



        bitset<64> bit_new_lhs(new_lhs >> ((number_of_bits + 1)/2));

        bitset<64> new_midbit = (new_lhs >> (number_of_bits/2)) & 0b1;
        bitset<64> bit_new_rhs = get_rhs(bit_new_lhs, number_of_bits - (number_of_bits + 1)/2);

        ll new_value = ((bit_new_lhs << (number_of_bits+1)/2) | new_midbit << (number_of_bits/2) | bit_new_rhs).to_ullong();
        cout << new_value << endl;
    } else {
        cout << value << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;

    while (tc--) {
        solve();
    }
    return 0;
}
