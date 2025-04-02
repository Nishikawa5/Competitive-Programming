#include <bits/stdc++.h>
using namespace std;

// code from https://cp-algorithms.com/algebra/fft.html
using cd = complex<double>;
const double PI = acos(-1);

int reverse(int num, int lg_n) {
    int res = 0;
    for (int i = 0; i < lg_n; i++) {
        if (num & (1 << i))
            res |= 1 << (lg_n - 1 - i);
    }
    return res;
}

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    int lg_n = 0;
    while ((1 << lg_n) < n)
        lg_n++;

    for (int i = 0; i < n; i++) {
        if (i < reverse(i, lg_n))
            swap(a[i], a[reverse(i, lg_n)]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<long long> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<long long> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

int main() {
    // cant do O(N**2) => no brute force
    int n;
    cin >> n;

    vector<int> squares(n);
    vector<int> first_poly(n);
    vector<int> second_poly(n);

    for (int i = 1; i < n; i++) {
        squares[1LL * i * i % n]++;
    }

    for (int i = 0; i < n; i++) {
        first_poly[i] = squares[i];
        second_poly[i] = squares[i];
    }

    // 1**2 + 1**2 == 2
    // 1**2 + 2**2 == 5
    // ...
    // multiplying the polynomials of squares results in the sum of squares
    vector<long long> mult_poly = multiply(first_poly, second_poly);
    long long total_triangles = 0;

    for (long long i = 0; i < mult_poly.size(); i++) {
        // if we have a sum of squares == square mod n   we add every combination of that
        // int a**2+b**2 % N = i
        total_triangles += mult_poly[i] * squares[i % n];
        if (i < n && i) {
            // add the solutions where c == 2*a**2 again so we can divide by 2
            total_triangles += squares[(2 * i * i) % n];
        }
    }
    // we counted both a**2 + b**2 and b**2 + a**2 for (a!=b) solutions
    // and added one more of solutions where a==b
    // so we can divide by 2
    cout << total_triangles / 2 << endl;
}