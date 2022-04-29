#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;

struct seg {
    ll l, r;
    bool operator< (const seg& rhs) const {
        if (l != rhs.l) return l < rhs.l;
        return r < rhs.r;
    }
} a[100000];

int n;

bool validate(ll d) {
    ll last = a[0].l;
    for (int i = 1; i < n; i++) {
        ll q = last + d;
        if (q > a[i].r) return false;
        last = max(a[i].l, q);
    }
    return true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].r += a[i].l;
    }

    sort(a, a + n);

    ll h = 20000000000, l = 0;
    while (l < h) {
        ll m = (l + h + 1) / 2;
        if (validate(m)) {
            l = m;
        } else {
            h = m - 1;
        }
    }

    cout << l;

    return 0;
}