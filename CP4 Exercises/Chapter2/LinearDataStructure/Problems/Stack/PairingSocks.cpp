#include <stack>
#include <queue>
#include <iostream>

using namespace std;

/*
2n socks stacked

move from top to top of aux
move top of aux to original
pair top sock together from each pile


*/
int main(void) {
    int n;
    scanf("%d", &n);

    n *= 2;

    stack<int> aux;

    int currSock;
    for (int i = 0; i < n; i++) {
        scanf("%d", &currSock);

        if (aux.empty()) {
            aux.push(currSock);
        } else {
            if (aux.top() == currSock) {
                aux.pop();
            } else {
                aux.push(currSock);
            }
        }
    }
    if (!aux.empty()) {
        printf("impossible\n");
    } else {
        printf("%d\n", n);
    }
}