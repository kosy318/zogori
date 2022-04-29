#define LOCAL
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast, no-stack-protector")
#pragma GCC target("avx")
#include<chrono>
#define FOR(i, a, b) for (int i = (a), _b=(b); i <= _b; i++)
#define FORD(i, a, b) for (int i  = (a), _b = (b); i >= _b; i--)
#define REP(i, a) for (int i = 0, _a = (a); i <_a; ++i)
#define REPD(i, a) for (int i = (a) - 1; i >=0; --i)
#define PI (2 * acos((double)0))
#define fi first
#define se second
#define sec(x) 1.0 / cos((x))
#define asec(x) acos(1.0 / (x))
template<class T> int getbit(T s, int i) {return (s >> i ) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) {return __builtin_popcountll(s); }
template<class T> T gcd(T a, T b){ T r; while(b != 0){ r = a % b; a = b; b = r;} return a;}
template<class T> T lcm(T a, T b) {return a / gcd(a, b) * b;}
#define IOS ios_base::sync_with_stdio(0), cin.tie(0);
#define sqr(x) ((x) * (x))
#define unify(x) x.erase(unique(x.begin(), x.end()), x.end())
#define __builtin_popcount __builtin_popcountll
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 100;

vector<pii> segment;
int n;

bool possible(int dist)
{
    // min is dist
    vector<int> p(n);
    p[0] = segment[0].fi;
    int last = p[0];
    int res = 2e9;
    FOR(i, 1, n - 1)
    {
        int l = segment[i].fi, r = segment[i].se;
        if (last + dist > r) return false;
        int tmp = max(l, last + dist);
        p[i] = tmp;
        res = min(p[i] - last, res);
        last = p[i];
    }
    return res >= dist;
}

int main()
{
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
    #endif
    cin >> n;
    segment.resize(n);
    REP(i, n)
    {
        int from, len;
        cin >> from >> len;
        segment[i] = {from, from + len};
    }
    sort(begin(segment), end(segment));

    int min_dist = 2e9;
    FOR(i, 1, n - 1) min_dist = min(min_dist, segment[i].fi - segment[i - 1].fi);

    int l = min_dist, r = 2e9;
    int res = 0;
    do
    {
        int mid = (l + r) >> 1;
        if (possible(mid)) l = mid;
        else r = mid - 1;
    } while (l + 1 < r);
    res = l;
    if (possible(r)) res = r;
    cout << res << endl;
    return 0;
}
