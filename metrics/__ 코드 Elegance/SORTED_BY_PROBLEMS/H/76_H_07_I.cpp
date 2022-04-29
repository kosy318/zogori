#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;

struct ore {
    ll s, e, t;
    ore(): s(0), e(0), t(0){}
    ore(ll ss, ll ee, ll tt) : s(ss), e(ee), t(tt){}
};

constexpr auto INF = numeric_limits<ll>::max();

struct rmq {
    int n; vi rm;
    rmq(const vi& arr) {
        n = arr.size();
        rm.resize(n*4);
        init(arr, 0, n-1, 1);
    }
    ll init(const vi& arr, int l, int r, int node) {
        if(l == r) return rm[node] = arr[l];
        int m = l + r >> 1;
        auto lmin = init(arr, l, m, node*2);
        auto rmin = init(arr, m+1, r, node*2 + 1);
        return rm[node] = max(lmin, rmin);
    }
    ll query(int l, int r, int node, int nl, int nr) {
        if(r < nl || nr < l) return 0;
        if(l <= nl && nr <= r) return rm[node];
        int m = nl + nr >> 1;
        return max(query(l, r, node*2, nl, m), query(l, r, node*2+1, m+1, nr));
    }
    ll query(int l, int r){
        return query(l, r, 1, 0, n-1);
    }
    ll update(int idx, ll val, int node, int nl, int nr) {
        if(idx < nl || nr < idx) return rm[node];
        if(nl == nr) return rm[node] = val;
        int m = (nl + nr) / 2;
        return rm[node]=max(update(idx, val, node*2, nl, m), update(idx, val, node*2+1, m+1, nr));
    }
    ll update(int idx, ll val) {
        return update(idx, val, 1, 0, n-1);
    }
};

int main() {
    int m, n; cin >> m >> n;
    vi price(m); for(auto&i: price) cin >> i;
    set<ll> indices;
    vector<ore> dat(n); for(auto& i : dat) {
        cin >> i.s >> i.e >> i.t;
        --i.t;
    }
    sort(begin(dat), end(dat), [](const auto& a, const auto& b){return a.s < b.s;});

    vi end_indices; for(auto it : indices) end_indices.push_back(it);
    vi dp(n, -INF); vi arr(15100, 0); rmq q(arr);
    for(int i = 0; i < n; ++i) {
        auto here = (dat[i].e - dat[i].s) * price[dat[i].t];
        auto before = q.query(0, dat[i].s);
        auto cost = here + before;
        q.update(dat[i].e, max(cost, q.query(dat[i].e, dat[i].e)));
    }
    cout << q.query(0, 15090);

    return 0;
}