#include <iostream>
#include <iomanip>

using namespace std;

#define PI 3.141592653589793238

int main(void) {
    int n;
    scanf("%d", &n);

    printf("%.2lf\n", PI);

    cout << setprecision(n + 1);
    cout << PI << endl;
}