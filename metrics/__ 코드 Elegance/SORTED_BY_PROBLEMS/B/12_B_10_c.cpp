#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct edge {
    int v, l;
};

vector<edge> edges[101010];

map<int, ll> A[101010]; // sum of square ai
map<int, ll> B[101010]; // sum of ai
map<int, ll> C[101010]; // # of leaf nodes
map<pair<int, int>, char> visit;

void dfs(int u, int p = -1) {
    if(edges[u].size() == 1 && p != -1) {
        A[u][p] = 0;
        B[u][p] = 0;
        C[u][p] = 1;
        return;
    }

    if(visit[{u, p}]) return;
    visit[{u, p}] = true;

    C[u][p] = 0;
    for(edge &e : edges[u]) {
        if(e.v == p) continue;
        dfs(e.v, u);
        C[u][p] += C[e.v][u];
    }

    B[u][p] = 0;
    for(edge &e : edges[u]) {
        if(e.v == p) continue;
        B[u][p] += B[e.v][u] + e.l*C[e.v][u];
    }

    A[u][p] = 0;
    for(edge &e : edges[u]) {
        if(e.v == p) continue;
        A[u][p] += A[e.v][u] + 2LL*e.l*B[e.v][u] + e.l*e.l*C[e.v][u];
    }

    /*
    cout << u << ' ' << p << endl;
    cout << A[u][p] << ' ';
    cout << B[u][p] << ' ';
    cout << C[u][p] << endl;
    */
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif // LOCAL

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for(int i=0; i<n-1; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    ll res = 0;
    for(int i=1; i<=n; i++) {
        if(edges[i].size() == 1) {
            dfs(i, -1);
            res += A[i][-1];
        }
    }

    cout << res/2 << endl;

    return 0;
}
