#include <bits/stdc++.h>
#define fastIO() ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define in1(x) cin >> x
#define in2(x, y) cin >> x >> y
#define in3(x, y, z) cin >> x >> y >> z
#define in4(x, y, z, r) cin >> x >> y >> z >> r
#define rep(i, x, y) for(int i=x; i<=y; i++)
#define rrep(i, x, y) for(int i=y; i>=x; i--)
#define irep(item, items) for(auto item : items)
#define irrep(item, items) for(auto &item : items)
#define all(x) x.begin(), x.end()
#define abss(x) ((x)>0?(x):(-(x)))
#define dpow(x) ((x)*(x))
#define INF ((1LL << 31) - 1)
#define LINF (1<<61)
#define PQ priority_queue
#define Umap unordered_map
#define Uset unordered_set
#define MAXN 15000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lb;
const int DX[] = {1, 0, -1, 0}, DY[] = {0, 1, 0, -1};
template <class T1, class T2> class Pair {
public:
    T1 x;
    T2 y;
    Pair(T1 x_=T1(), T2 y_=T2()) : x(x_), y(y_) {}
    bool operator<(const Pair &p) const {
        if(x == p.x) return y < p.y;
        return x < p.x;
    }
    bool operator>(const Pair &p) const {
        if(x == p.x) return y > p.y;
        return x > p.x;
    }
    bool operator!=(const Pair &p) const {
        return x != p.x || y != p.y;
    }
    friend istream &operator>>(istream &stream, Pair &p) {
        stream >> p.x >> p.y;
        return stream;
    }
};
typedef Pair<int, int> PII;
typedef Pair<ll, ll> PLL;
typedef vector<int> vi;
typedef vector<ll> vl;
template <class T> T CCW(Pair<T, T> &a, Pair<T, T> &b, Pair<T, T> &c) {return (b.x - a.x) * (c.y - b.y) - (c.x - b.x) * (b.y - a.y);}
template<class T> T dist(Pair<T, T> &a, Pair<T, T> &b) {return dpow(a.x - b.x) + dpow(a.y - b.y);}
///////////////////////////////////////////////////////////////////////////////////////
typedef Pair<PII, int> Work;
int N, M;
vi mineral;
vector<Work> work;
int dp[MAXN + 10];
vi seg;
int build(int node, int l, int r) {
    if(l == r) return seg[node] = dp[l];
    int mid = (l + r) >> 1;
    return seg[node] = max(build(node << 1, l, mid), build(node << 1 | 1, mid + 1, r));
}
int update(int node, int l, int r, int idx, int value) {
    if(idx < l || r < idx) return seg[node];
    if(l == r) return seg[node] = dp[idx] = value;
    int mid = (l + r) >> 1;
    return seg[node] = max(update(node << 1, l, mid, idx, value), update(node << 1 | 1, mid + 1, r, idx, value));
}
int query(int node, int l, int r, int ql, int qr) {
    if(qr < l || r < ql) return -(INF / 2);
    if(ql <= l && r <= qr) return seg[node];
    int mid = (l + r) >> 1;
    return max(query(node << 1, l, mid, ql, qr), query(node << 1 | 1, mid + 1, r, ql, qr));
}
int main() {
    fastIO();
    in2(N, M);
    mineral.resize(N);
    irrep(i, mineral) in1(i);
    work.resize(M);
    irrep(i, work) in1(i);
    sort(all(work), [](const Work &l, const Work &r) {
        if (l.x.x == r.x.x) return l.x.y < r.x.y;
        return l.x.x < r.x.x;
    });
    fill(dp, dp + MAXN + 10, -(INF / 2));
    seg.resize(4 * (MAXN + 1));
    build(1, 1, MAXN);
    dp[MAXN + 1] = 0;
    update(1, 1, MAXN + 1, MAXN + 1, dp[MAXN + 1]);
    rrep(i, 0, M - 1) {
        int x = work[i].x.x, y = work[i].x.y, cost = work[i].y;
        cost = mineral[cost - 1] * (y - x);
        int Max = query(1, 1, MAXN + 1, y, MAXN + 1);
        update(1, 1, MAXN + 1, x, max(dp[x], Max + cost));
    }
    cout << query(1, 1, MAXN + 1, 1, MAXN + 1);
    return 0;
}