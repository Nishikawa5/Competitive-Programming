#include <bits/stdc++.h>
using namespace std;

/*
a + b = (a & b) << 1 + a ^ b
and
a ^ b = ~(a & b) & (a | b)
=>
a + b = (a & b) << 1 + ~(a & b) & (a | b)
which has 2 asks
and we need to ask for every element minus the last one, so we have exactly 2n - 2 questions
we can use one more question to find a1 and we are done
a1 + a2
     a2 + a3
          ...
=> a2 = a2 + a1 - a1
*/

void ask(string op, int i1, int i2) {
    cout << op << " " << i1 << " " << i2 << endl;
}

int get_answer() {
    int ans;
    cin >> ans;
    return ans;
}

// ask and return the addition
int add(int i1, int i2) {
    ask("and", i1, i2);
    int aandb = get_answer();
    ask("or", i1, i2);
    int aorb = get_answer();

    return (aandb << 1) + (~(aandb) & (aorb));
}


int main() {
    int n, k;
    cin >> n >> k;

    vector<int> sequence(n + 1);
    // find a1
    int a1_plus_a2 = add(1, 2);
    int a2_plus_a3 = add(2, 3);
    int a1_plus_a3 = add(1, 3);
    int a1 = (a1_plus_a2 - a2_plus_a3 + a1_plus_a3) / 2;

    // fill the first 3
    sequence[1] = a1;
    sequence[3] = a1_plus_a3 - a1;
    sequence[2] = a2_plus_a3 - sequence[3];

    // now find the rest
    for (int i = 4; i <= n; i++) {
        int a1_plus_ai = add(1, i);
        sequence[i] = a1_plus_ai - a1;
    }
    sort(sequence.begin(), sequence.end());
    cout << "finish " << sequence[k] << endl;
}