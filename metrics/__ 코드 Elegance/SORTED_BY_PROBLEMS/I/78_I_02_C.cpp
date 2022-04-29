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
int N;
vector<PLL> line;
bool possible(int k) {
    ll last = line[0].x;
    rep(i, 1, line.size() - 1) {
        ll x = line[i].x, y = line[i].y;
        if(x <= last + k && last + k <= y) {
            last += k;
        } else if(last + k < x) {
            last = x;
        } else {
            return false;
        }
    }
    return true;
}
int main() {
    fastIO();
    in1(N);
    line.resize(N);
    irrep(i, line) in1(i), i.y += i.x;
    sort(all(line), [](PLL &l, PLL &r){
        if(l.y == r.y) return l.x < r.x;
        return l.y < r.y;
    });
    ll l = 0, r = line[1].y - line[0].x, ans = LINF;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if(possible(mid)) {
            ans = max(ans, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout<<ans;
    return 0;
}