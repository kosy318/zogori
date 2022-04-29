#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 123;

int n, root, deg[N], cnt[N];
vector<pair<int,int>> g[N];

long long answer[N], dist[N], f[N];

void dfs(int v, int par = -1) {
    if (deg[v] == 1) {
        cnt[v] = 1;
    } else {
        for (auto it : g[v]) {
            int to = it.first;
            int cost = it.second;
            if (to != par) {

                dfs(to, v);

                long long nDist = dist[to] + 1ll * cnt[to] * cost;
                long long nF = f[to] + 1ll * cnt[to] * cost * cost + 2ll * cost * dist[to];

                answer[v] += 1ll * cnt[v] * nF + 1ll * cnt[to] * f[v] + 2ll * dist[v] * nDist;

                dist[v] += nDist;
                f[v] += nF;
                answer[v] += answer[to];
                cnt[v] += cnt[to];
            }
        }
    }
}

int main() {

    scanf("%d", &n);
    for (int i = 1, u, v, c;i < n;i++) {
        scanf("%d%d%d", &u, &v, &c);
        g[u].push_back({v, c});
        g[v].push_back({u, c});
        deg[u]++;
        deg[v]++;
    }

    root = 1;
    while(deg[root] == 1) root++;

    dfs(root);

    cout << answer[root] << endl;
    return 0;
}
