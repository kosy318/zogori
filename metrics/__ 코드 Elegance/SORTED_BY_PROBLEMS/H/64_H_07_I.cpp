#include<bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

constexpr int inf = 0x3f3f3f3f;

struct SegmentTree {
    using T = struct { int min, max; };
    static T op(T a, T b) { return {min(a.min, b.min), max(a.max, b.max)}; }
    static constexpr T e() { return {inf, -inf}; }
    using U = int;
    static void ap(U f, T& a) { a.min += f, a.max += f; }
    static void cp(U g, U& f) { f += g; }
    static constexpr U id() { return 0; }

    const int n;
    V<T> t;
    V<U> u;
    SegmentTree(int _n) : n(_n), t(2 * n, e()), u(n, id()) {}
    T& operator[](int i) { return t[i + n]; }
    void build() { for (int i = n - 1; i >= 1; --i) t[i] = op(t[2 * i], t[2 * i + 1]); }
    void apply(U f, int i) {
        ap(f, t[i]);
        if (i < n) cp(f, u[i]);
    }
    void push(int i) {
        if (u[i] == id()) return;
        apply(u[i], 2 * i);
        apply(u[i], 2 * i + 1);
        u[i] = id();
    }
    void push(int l, int r) {
        for (int hl = __lg(l + n), hr = __lg(r - 1 + n); hr > 0; --hl, --hr) {
            int al = (l + n) >> hl, ar = (r - 1 + n) >> hr;
            if (al < n) push(al);
            if (ar != al) push(ar);
        }
    }
    T acc(int l, int r) {
        push(l, r);
        T resl = e(), resr = e();
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resl = op(resl, t[l++]);
            if (r & 1) resr = op(t[--r], resr);
        }
        return op(resl, resr);
    }
    void act(int l, int r, U f) {
        push(l, r);
        for (int i = l + n, j = r + n; i < j; i >>= 1, j >>= 1) {
            if (i & 1) apply(f, i++);
            if (j & 1) apply(f, --j);
        }
        l = (l + n) >> __builtin_ctz(l + n);
        while (l >>= 1) t[l] = op(t[2 * l], t[2 * l + 1]);
        r = (r + n) >> __builtin_ctz(r + n);
        while (r >>= 1) t[r] = op(t[2 * r], t[2 * r + 1]);
    }
};

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    V<> vx, vy;
    int n0; cin >> n0;
    V<> x0(n0), y0(n0);
    for (int i = 0; i < n0; ++i) {
        cin >> x0[i] >> y0[i];
        vx.push_back(x0[i]);
        vy.push_back(y0[i]);
    }
    int n1; cin >> n1;
    V<> x1(n1), y1(n1);
    for (int i = 0; i < n1; ++i) {
        cin >> x1[i] >> y1[i];
        vx.push_back(x1[i]);
        vy.push_back(y1[i]);
    }
    sort(begin(vx), end(vx));
    sort(begin(vy), end(vy));
    for (auto&& x : x0) x = lower_bound(begin(vx), end(vx), x) - begin(vx);
    for (auto&& x : x1) x = lower_bound(begin(vx), end(vx), x) - begin(vx);
    for (auto&& y : y0) y = lower_bound(begin(vy), end(vy), y) - begin(vy);
    for (auto&& y : y1) y = lower_bound(begin(vy), end(vy), y) - begin(vy);
    auto x = x0, y = y0;
    x.insert(end(x), begin(x1), end(x1));
    y.insert(end(y), begin(y1), end(y1));
    int n = n0 + n1;
    int c0, c1; cin >> c0 >> c1;
    V<> c(n, c0);
    fill(begin(c) + n0, end(c), -c1);
    V<> x_ord(n);
    iota(begin(x_ord), end(x_ord), 0);
    sort(begin(x_ord), end(x_ord), [&](int i, int j) { return x[i] < x[j]; });
    V<> y_ord(n);
    iota(begin(y_ord), end(y_ord), 0);
    sort(begin(y_ord), end(y_ord), [&](int i, int j) { return y[i] < y[j]; });

    int res = 0;
    V<> cum(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        cum[i] = c[y_ord[i]] + cum[i + 1];
    }
    for (int l = 0; l < n; ++l) {
        SegmentTree st(n + 1);
        for (int i = 0; i <= n; ++i) {
            st[i] = {0, 0};
        }
        st.build();
        set<int> se;
        for (int r = l; r < n; ++r) {
            int i = x_ord[r];
            se.insert(y[i]);
            st.act(0, y[i] + 1, c[i]);
            int mn = *begin(se);
            int mx = *rbegin(se);
//            int crr = cum[mn] - cum[mx + 1];
            int crr = st.acc(0, mn + 1).max - st.acc(mx + 1, n + 1).min;
            res = max(res, crr);
        }
//        int i = x_ord[l];
//        se.erase(y[i]);
//        st.act(0, y[i] + 1, -c[i]);
    }
    cout << res << endl;
    for (int i = 0; i < n; ++i) {
//        cerr << x[i] << ' ' << y[i] << ' ' << c[i] << endl;
    }
}