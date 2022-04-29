#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const ll inf = (1ll << 61);

struct point {
    int x, y, val;
    bool operator<(const point& rhs) const {
        if (x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }
};

struct compy {
    bool operator() (const point& lhs, const point& rhs) const {
        if (lhs.y != rhs.y) return lhs.y < rhs.y;
        return lhs.x < rhs.x;
    }
};

struct node {
    ll mn, mx;
    bool lazy_flag;
    node() : mn(inf), mx(0), lazy_flag(false) {};
    node(ll x) : mn(x), mx(x), lazy_flag(false) {};
    node(ll mn, ll mx) : mn(mn), mx(mx), lazy_flag(false) {};
    node operator+(const node& rhs) const {
        return node(
                max(0ll, min(mn, rhs.mx)),
                max(0ll, max(mx, rhs.mx))
                );
    }
    void operator+=(const node& rhs) {
        this->mn += rhs.mn;
        this->mx += rhs.mx;
        if (this->mn < 0) this->mn = 0;
        if (this->mx < 0) this->mx = 0;
    }
    void operator+=(const int& rhs) {
        this->mn += rhs;
        this->mx += rhs;
        if (this->mn < 0) this->mn = 0;
        if (this->mx < 0) this->mx = 0;
    }
};

void _propagate(int x, int s, int e, node* tree, ll* lazy) {
    if (!lazy[x]) return;
    tree[x] += lazy[x];
    if (s != e) {
        lazy[x * 2] += lazy[x];
        lazy[x * 2 + 1] += lazy[x];
    }
    lazy[x] = 0;
}

node _query(int x, int s, int e, int l, int r, node* tree, ll* lazy) {
    _propagate(x, s, e, tree, lazy);
    if (l > e || r < s) return node();
    if (l <= s && e <= r) return tree[x];
    return _query(x * 2, s, (s + e) / 2, l, r, tree, lazy)
            + _query(x * 2 + 1, (s + e) / 2 + 1, e, l, r, tree, lazy);
}

void _update(int x, int s, int e, int l, int r, ll dv, node* tree, ll* lazy) {
    _propagate(x, s, e, tree, lazy);
    if (l > e || r < s) return;
    if (l <= s && e <= r) {
        tree[x] += dv;
        if (s != e) {
            lazy[x * 2] += dv;
            lazy[x * 2 + 1] += dv;
        }
        return;
    }
    _update(x * 2, s, (s + e) / 2, l, r, dv, tree, lazy);
    _update(x * 2 + 1, (s + e) / 2 + 1, e, l, r, dv, tree, lazy);
    tree[x] = tree[x * 2] + tree[x * 2 + 1];
}

node query(int n, int l, int r, node* tree, ll* lazy) {
    return _query(1, 1, n, l, r, tree, lazy);
}

void update(int n, int l, int r, ll dv, node* tree, ll* lazy) {
    _update(1, 1, n, l, r, dv, tree, lazy);
}

point raw[2000], a[2000];

node tree[4096 * 2];
ll lazy[4096 * 2];

int n, m, c1, c2;

void zip() {
    sort(raw, raw + n + m);
    a[0].y = raw[0].y;
    a[0].val = raw[0].val;
    for (int i = 1; i < n + m; i++) {
        if (raw[i - 1].x == raw[i].x) {
            a[i].x = a[i - 1].x;
        } else {
            a[i].x = a[i - 1].x + 1;
        }
        a[i].y = raw[i].y;
        a[i].val = raw[i].val;
    }

    sort(raw, raw + n + m, compy{});
    sort(a, a + n + m, compy{});
    a[0].y = 0;
    for (int i = 1; i < n + m; i++) {
        if (raw[i - 1].y == raw[i].y) {
            a[i].y = a[i - 1].y;
        } else {
            a[i].y = a[i - 1].y + 1;
        }
    }

    for (int i = 0; i < n + m; i++) {
        if (a[i].val == 1) {
            a[i].val = c1;
        } else {
            a[i].val = -c2;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> raw[i].x >> raw[i].y;
        raw[i].val = 1;
    }
    cin >> m;
    for (int i = n; i < n + m; i++) {
        cin >> raw[i].x >> raw[i].y;
        raw[i].val = -1;
    }

    cin >> c1 >> c2;

    zip();
    sort(a, a + n + m);

    ll mx = 0;

    for (int y1 = 0; y1 < 2000; y1++) {
        for (node& x : tree) x = node();
        memset(lazy, 0, sizeof lazy);

        for (int i = 0; i < n + m; i++) {
            if (a[i].y < y1) continue;
            update(2001, a[i].y, 2000, a[i].val, tree, lazy);
            mx = max(mx, query(2001, y1, 2000, tree, lazy).mx);
        }
    }

    cout << mx;

    return 0;
}