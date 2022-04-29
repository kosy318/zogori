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

vector<int> leaf;
vector<pii> g[MAXN];
bool isLeaf[MAXN];
int deg[MAXN];
int L[MAXN];
int par[MAXN];
int P[MAXN][31];
ll dist[MAXN];
int n;

void dfs(int u, int level)
{
    L[u] = level;
    for (int i = 0; i < g[u].size(); ++i)
    {
        int v = g[u][i].fi, len = g[u][i].se;
        if (par[v] == -1)
        {
            dist[v] = dist[u] + len;
            par[v] = u, dfs(v, level + 1);
        }
    }
}

void build_lca()
{
    for (int i = 0; i <= n; ++i)
        for (int j = 1; j <= trunc(log2(n)); ++j)  P[i][j] = -1;
    for (int i = 1; i <=n ;++i) P[i][0] = par[i];
    for (int j = 1; j <= trunc(log2(n)); ++j)
        for (int i = 0; i <= n; ++i)
            if (P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
}

int lca(int u, int v)
{
    if (L[u] < L[v]) swap(u, v);
    int x = 1;
    while (x <= log2(L[u])) ++x;
    --x;

    for (int i = x; i >= 0; --i)
        if (L[u] - (1 << i) >= L[v]) u = P[u][i];
    if (u == v) return u;

    for (int i = x; i >= 0; --i)
        if (P[u][i] != -1 && P[u][i] != P[v][i])
            u = P[u][i], v = P[v][i];
    return par[u];
}

int main()
{
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
    #endif
    cin >> n;

    REP(i, n - 1)
    {
        int u, v;
        int len;
        cin >> u >> v >> len;
        g[u].emplace_back(v, len), g[v].emplace_back(u, len);
        ++deg[u], ++deg[v];
    }

    FOR(u, 1, n) if (deg[u] == 1)
    {
        isLeaf[u] = true;
        leaf.emplace_back(u);
    }
    int root = leaf[0];
    memset(par, -1, sizeof(par));
    par[root] = root;
    dfs(root, 1);

    build_lca();
    ll res = 0;

    REP(i, leaf.size())
        FOR(j, i + 1, leaf.size() - 1)
        {
            int u = leaf[i], v = leaf[j];
            ll w = lca(u, v);
            ll add = dist[u] + dist[v] - dist[w] * 2;
            res += add * add;
        }
    cout << res << endl;
    return 0;
}
