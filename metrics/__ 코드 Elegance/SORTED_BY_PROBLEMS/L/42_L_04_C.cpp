
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

const int MAXN = 110;
const int MAXM = 10100;
struct ore {
    int s, t, type;
} ;
vector<ore> segment;
ll dp[MAXM];

bool cmp(ore a, ore b) {
    return a.s < b.s || (a.s == b.s && a.t < b.t);
}

int main()
{
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;
    vector<int> value(n);
    REP(i, n) cin >> value[i];
    REP(i, m)
    {
        int s, t, type;
        cin >> s >> t >> type;
        segment.push_back({s, t, type});
    }
    sort(begin(segment), end(segment), cmp);

    ll res = 0;
    REP(i, m)
    {
        // max value at segment i
        int type = segment[i].type - 1;
        int l = segment[i].s, r = segment[i].t;
        ll add = 1LL * value[type] * (r - l);
        dp[i] = add;

        REP(j, i)
        {
            int ll = segment[j].s, rr = segment[j].t;
            int type2 = segment[j].type - 1;
            if (rr <= l)
                dp[i] = max(dp[i], dp[j] + add);
        }
        res = max(res, dp[i]);
    }
    cout << res << endl;
    return 0;
}
