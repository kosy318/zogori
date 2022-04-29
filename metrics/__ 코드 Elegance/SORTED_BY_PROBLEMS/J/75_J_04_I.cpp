#include <bits/stdc++.h>
using namespace std;

int N, D[1000005];

int main() {
    scanf("%d", &N);
    D[4] = 1, D[5] = 2, D[6] = 2;
    for(int i=7; i<=N; i++) {
        int a = (i + 3) / 3;
        int b = (i + 3 - a) / 2;
        int c = (i + 3 - a - b);
        int mx = max({ a, b, c });
        int mn = min({ a, b, c });
        int md = a + b + c - mx - mn;
        D[i] = D[mx] + D[md] + 2;
    }
    printf("%d\n", D[N]);
}
