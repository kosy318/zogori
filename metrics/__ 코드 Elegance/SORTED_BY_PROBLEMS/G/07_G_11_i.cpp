#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m, n;
pair<ll, ll> a[111111];

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i].first);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i].second);
    }

    sort(a+1,a+1+n);

    ll dap = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i].second != a[i-1].second) dap++;
    }

    printf("%lld\n", dap);

    return 0;
}

/*
2 6
 0 3 4 7 8 11
 1 1 1 2 2 1

 2 6
 0 3 4 7 8 11
 1 2 1 2 2 1
 */