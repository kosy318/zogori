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
#define MAXN 4000
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
int N, M;
vector<PII> strike, ball;
vi X, Y;
vector<vi> SMat(MAXN + 10, vi(MAXN + 10)), BMat(MAXN + 10, vi(MAXN + 10));
int getIdx(vi &v, int data) {return lower_bound(all(v), data) - v.begin();}
int getSum(int ax, int ay, int bx, int by, vector<vi> &vv) {return vv[bx][by] - vv[bx][ay - 1] - vv[ax - 1][by] + vv[ax - 1][ay - 1];}
int main() {
//    fastIO();
    in1(N);
    strike.resize(N);
    irrep(i, strike) in1(i), X.push_back(i.x), Y.push_back(i.y);
    in1(M);
    ball.resize(M);
    irrep(i, ball) in1(i), X.push_back(i.x), Y.push_back(i.y);
    sort(all(X)), sort(all(Y));
    X.erase(unique(all(X)), X.end()), Y.erase(unique(all(Y)), Y.end());
    irrep(i, strike) {
        i.x = getIdx(X, i.x) + 1;
        i.y = getIdx(Y, i.y) + 1;
        SMat[i.x][i.y] = 1;
    }
    irrep(i, ball) {
        i.x = getIdx(X, i.x) + 1;
        i.y = getIdx(Y, i.y) + 1;
        BMat[i.x][i.y] = 1;
    }
    // init //
    rep(i, 1, MAXN) rep(j, 1, MAXN) {
            SMat[i][j] += SMat[i - 1][j] + SMat[i][j - 1] - SMat[i - 1][j - 1];
            BMat[i][j] += BMat[i - 1][j] + BMat[i][j - 1] - BMat[i - 1][j - 1];
        }
    ll S, B;
    in2(S, B);
    ll ans = 0;
    rep(i, 0, strike.size() - 1) rep(j, i, strike.size() - 1) {
            int ax, ay, bx, by;
            ax = min(strike[i].x, strike[j].x);
            ay = min(strike[i].y, strike[j].y);
            bx = max(strike[i].x, strike[j].x);
            by = max(strike[i].y, strike[j].y);
            ll s = 0, b = 0;
            s = getSum(ax, ay, bx, by, SMat);
            b = getSum(ax, ay, bx, by, BMat);
            ans = max(ans, s * S - b * B);
        }
    cout << ans;
    return 0;
}