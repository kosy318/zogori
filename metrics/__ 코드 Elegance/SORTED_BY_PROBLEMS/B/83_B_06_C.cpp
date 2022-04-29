#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int visit[100010];
long long dp1[100010], dp2[100010], dp3[100010];
vector<int> e[100010], c[100010];

long long ans = 0;

void dfs(int u) {
    int son = 0;
    visit[u] = 1;

    vector<int> vv, vc;
    for(int i = 0; i < e[u].size(); i++) {
        int v = e[u][i];
        long long d = c[u][i];
        if (visit[v]) continue;
        son++;
        dfs(v);

        if(dp3[u]) {
            long long tmpd = d * dp3[v] + dp2[v];
            long long joind = dp1[v] + d * d * ((dp3[v] - 1) * dp3[v]) / 2 + d * dp2[v] * (dp3[v] - 1);

            ans += tmpd * tmpd * dp3[u] + dp2[u] * dp2[u] * dp3[v];
            ans -= 2 * (joind * dp3[u] + dp1[u] * dp3[v]);
            ans += (tmpd * dp2[u]) * 2;
        }

        dp1[u] += dp1[v] + d * d * ((dp3[v] - 1) * dp3[v]) / 2 + d * dp2[v] * (dp3[v] - 1);
        dp1[u] += dp2[u] * (d * dp3[v] + dp2[v]); // (a + b + c) * (d + e + f)
        dp2[u] += d * dp3[v] + dp2[v]; // add distance
        dp3[u] += dp3[v]; // add leaf node
        vv.push_back(v);
        vc.push_back(d);
    }

    if(son == 0) {
        dp1[u] = 0;
        dp2[u] = 0;
        dp3[u] = 1;
        return;
    }

    if(son == 1 && u == 1) {
        ans += (dp2[u] * dp2[u]) - 2 * dp1[u];
    }

    vv.clear();
    vc.clear();
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        e[x].push_back(y);
        c[x].push_back(z);
        e[y].push_back(x);
        c[y].push_back(z);
    }
    dfs(1);

    printf("%lld\n", ans);
    return 0;
}