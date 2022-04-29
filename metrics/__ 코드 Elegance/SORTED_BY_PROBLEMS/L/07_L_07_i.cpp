#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m, n;
ll a[22222];
struct abc {
    ll s, e, t;
    bool operator <(abc a)const {
        if (e == a.e && s == a.s) return t < a.t;
        if( e == a.e) return s < a.s;
        return e < a.e;
    }
} b[22222];
vector<abc> v[22222];
ll d[22222];

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld %lld", &b[i].s, &b[i].e, &b[i].t);
    }
    sort(b+1, b+1+n);
    for (int i = 1; i <= n; i++) {
        v[b[i].e].push_back(b[i]);
    }

    ll mx = 0;
    for (int i = 1; i <= 15000; i++) {
        d[i] = mx;
        for (auto it : v[i]) {
            int s = it.s;
            int e = it.e;
            int t = it.t;
            d[i] = max(d[i], d[s]+(e-s)*a[t]);
        }
        mx = max(mx, d[i]);
    }

    ll dap = -1;
    for (int i = 1; i <= 15; i++) {
        dap = max(dap, d[i]);
    }

    printf("%lld\n", dap);

    return 0;
}


/*
2 5
2
 3
 2 5 1
 4 5 2
 4 6 1
 7 11 2
 6 10 1

 3 5
 2
 3
 1
 1 4 1
 3 6 3
 5 8 2
 7 10 1
 9 12 2

 */