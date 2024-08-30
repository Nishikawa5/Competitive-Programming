#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    int first = n;
    int days = 0;
    int integer_part;
    int decimal_part;
    int total_decimal = 0;
 
    days = 0;
    do {
        getchar();
        getchar();
        scanf("%d.%d", &integer_part, &decimal_part);
 
        total_decimal += decimal_part;
        if (n != first && (total_decimal % 100)) {
            days++;
        }
    } while (n--);
    cout << days << endl;
}