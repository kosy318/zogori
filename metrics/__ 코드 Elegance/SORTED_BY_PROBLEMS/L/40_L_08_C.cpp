#include <bits/stdc++.h>
#define X first
#define Y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define ini(x, y) memset(x, y, sizeof(x))
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;

const int SZ = 1 << 14;
ll tree[SZ << 1];
int pa[15005];

struct P {
    int s, e, val;
    bool operator<(const P& rhs) {
        if (s != rhs.s) return s < rhs.s;
        return e > rhs.e;
    }
};
int fnd(int n) {
    if (pa[n] < 0) return n;
    return pa[n] = fnd(pa[n]);
}
void uni(int a, int b) {
    a = fnd(a), b = fnd(b);
    if (a != b) pa[b] = a;
}

void update(int idx, int val) {
    for (tree[idx += SZ] = val; idx >>= 1; )
        tree[idx] = max(tree[idx << 1], tree[idx << 1 | 1]);
}
ll query(int L, int R, int idx = 1, int s = 0, int e = SZ - 1) {
    if (R < L || e < L || R < s) return 0;
    if (L <= s && e <= R) return tree[idx];

    int m = s + e >> 1;
    return max(query(L, R, idx << 1, s, m), query(L, R, idx << 1 | 1, m + 1, e));
}
int main() {
    //freopen("input.txt", "r", stdin);
    fastio; ini(pa, -1);
    int m, n;
    cin >> m >> n;

    int price[100];
    for (int i = 0; i < m; ++i) cin >> price[i];

    P arr[10000];
    for (int s, e, t, i = 0; i < n; ++i) {
        cin >> s >> e >> t;
        arr[i] = { s, e, (e - s) * price[t - 1] };
    }

    sort(arr, arr + n);

    ll dp[15005]{};
    for (int i = 0; i < n; ++i) {
        // overwrap
        dp[arr[i].e] = max(dp[arr[i].e], query(0, fnd(arr[i].s)) + arr[i].val);
        update(arr[i].e, dp[arr[i].e]);
    }

    cout << *max_element(dp, dp + 15005);

    return 0;
}