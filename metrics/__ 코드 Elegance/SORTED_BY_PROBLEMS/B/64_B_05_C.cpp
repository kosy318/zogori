#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
int N;
vector<l_l> paths[100050];
ll parent[100500];
ll plen[100500];
vector<l_l> children[100050];
ll SIZE[100500];
ll dp[100050];
ll ans = 0;
ll numleaf = 0;
void dfs1(int now) {
    SIZE[now] = 0;
    //cerr << now << " " << SIZE[now] << endl;
    for(auto to : paths[now]) {
        if(to.first == parent[now]) continue;
        parent[to.first] = now;
        plen[to.first] = to.second;
        children[now].push_back(to);
        dfs1(to.first);
        SIZE[now] += SIZE[to.first];
    }
    if(children[now].size() <= 0) SIZE[now]++;
    //cerr << now << " " << SIZE[now] << endl;
}

void dfs2(int now) {
    for(auto tmp : children[now]) {
        int to = tmp.first;
        ll l = tmp.second;
        ans += (numleaf  - SIZE[to]) * SIZE[to] * l * l;
        //cerr << now << " " << to << " " << (numleaf  - SIZE[to]) * SIZE[to] * l * l << endl;

        dfs2(to);
        //if(children[to].empty()) dp[to] += SIZE[to] * l;
        ans += 2 * (numleaf - SIZE[to])  * l * dp[to];
        //cout << now << " " << to << " " << 2 * (numleaf - SIZE[to])  * l * dp[to] << endl;
        dp[to] += l * SIZE[to];
        //cerr << to << " " << dp[to] << endl;
    }
    for(int i = 0; i < children[now].size(); i++) {
        for (int j = i + 1; j < children[now].size(); j++) {
            int v1 = children[now][i].first;
            int v2 = children[now][j].first;
            ans += 2 * dp[v1] * dp[v2];
            //cout << v1 << " " << v2 << " " <<  2 * dp[v1] * dp[v2] << endl;
            //cerr << v1 << " " << v2 << " " << 2 * dp[v1] * dp[v2] << endl;
        }
    }
    for(int i = 0; i < children[now].size(); i++) {
        int v1 = children[now][i].first;
        dp[now] += dp[v1];
    }
    //cout << "dp:" << now << " " << dp[now] << endl;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i < N; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        paths[u].emplace_back(v, l);
        paths[v].emplace_back(u, l);
    }
    parent[1] = -1;
    dfs1(1);
    numleaf = SIZE[1];
    if(children[1].size() <= 1) numleaf++;
    ///cerr << ans << endl;
    dfs2(1);
    cout << ans << endl;
    return 0;
}