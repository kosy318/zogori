#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int d[1000010];
int f(int num) {
    if(d[num]) return d[num];

    int ret = 0;
    if(num % 2) ret += f(num / 2 + 1);
    else ret += f(num / 2);

    return ret + 1;
}
int main() {
    int n;
    scanf("%d", &n);
    d[4] = 1;
    d[5] = 2;
    d[6] = 2;

    printf("%d", f(n));
    return 0;
}