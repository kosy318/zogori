#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
struct abc {
    ll s, e;
    bool operator <(abc a)const {
        if (s == a.s) return e < a.e;
        return s < a.s;
    }
} a[111111];

bool feasible(ll mid) {
    ll prv = a[1].s;
    ll now;
    for (int i = 2; i <= n; i++) {
        now = max(prv+mid, a[i].s);
        if (a[i].e < now) return 0;
        prv = now;
    }
    return 1;
}


int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        ll x, l;
        scanf("%lld %lld", &x, &l);
        a[i].s = x;
        a[i].e = x+l;
    }

    sort(a+1,a+1+n);

    ll lft = 0, rgt = 1e12;
    ll dap = -1;
    while (lft <= rgt) {
        ll mid = (lft+rgt)/2;
        if (feasible(mid)) {
            lft = mid+1;
            dap = mid;
        }
        else {
            rgt = mid-1;
        }
    }

    printf("%lld\n", dap);


    return 0;
}

/*
 6
 0 67
 127 36
 110 23
 50 51
 100 12
 158 17

 6
 0 40
 10 55
 45 28
 90 40
 83 30
 120 30
 */