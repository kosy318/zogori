#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int n, root;
vector<pii> adj[100010];
ll ans;

struct Info{ ll S, T, M; };
vector<Info> vec[100010];

Info merge(const Info &a, const Info &b, int d){
    ll A1 = a.S, A2 = a.T, M = a.M;
    ll B1 = b.S, B2 = b.T, N = b.M;
    ans += N * A2 + 2 * A1 * B1 + M * B2;
    return {A1 + B1 + (M + N) * d, A2 + B2 + 2*(A1 + B1)*d + (M + N) * d * d, M + N};
}

Info dfs(int now, int par, int d){
    if(adj[now].size() == 1) return {d, d*1ll*d, 1};

    for(pii p: adj[now]){
        int dest = p.first;
        if(dest != par) vec[now].push_back(dfs(dest, now, p.second));
    }

    if(vec[now].size() == 2) return merge(vec[now][0], vec[now][1], d);
    else return merge(merge(vec[now][0], vec[now][1], 0), vec[now][2], 0);
}

int main(){
    scanf("%d", &n);
    for(int i = 1, u, v, x; i < n; i++){
        scanf("%d %d %d", &u, &v, &x);
        adj[u].push_back(make_pair(v, x));
        adj[v].push_back(make_pair(u, x));
    }
    for(int i = 1; i <= n; i++) if(adj[i].size() == 3){ root = i; break; }
    dfs(root, root, 0);
    printf("%lld", ans);
    return 0;
}
