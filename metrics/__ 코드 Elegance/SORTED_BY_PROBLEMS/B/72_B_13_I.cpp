
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int max_n = 100005;
ll N;
ll cache[30][max_n];
ll cost[30][max_n];
vector<pair<ll,ll> > adj[max_n];
vector<ll> childs;
ll depth[max_n];
ll visited[max_n];

void dfs(ll root, ll cnt) {
    visited[root] = 1;
    depth[root] = cnt;
    for(int i = 0; i < adj[root].size(); i++) {
        ll next = adj[root][i].first;
        if(!visited[next]) dfs(next, cnt + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    memset(cache, -1, sizeof(cache));


    queue<ll> q;
    for(int i = 0; i < N; i++) {
        if(adj[i].size() == 1) {
            cache[0][i] = adj[i][0].first; // parent setting
            cost[0][i] = adj[i][0].second; // cost setting
            childs.push_back(i);
            q.push(i);
        }
    }

    while(!q.empty()) {
        ll curr = q.front();
        q.pop();

        if(visited[curr]) continue;
        visited[curr] = 1;

        for(int i = 0; i < adj[curr].size(); i++) {
            ll next = adj[curr][i].first;
            ll next_cost = adj[curr][i].second;

            if(!visited[next]){
                cache[0][curr] = next; // parent setting
                cost[0][curr] = next_cost; // cost setting
                q.push(next);
            }
        }
    }

    for(int i = 1; i <= 20; i++) { // 2^n
        for(int j = 0; j < N; j++) {
            if(cache[i - 1][cache[i - 1][j]] != -1) {
                cost[i][j] += cost[i - 1][cache[i - 1][j]];
                cache[i][j] = cache[i - 1][cache[i - 1][j]];
            }
        }
    }

    ll root = -1;
    for(int i = 0; i < N; i++){
        if(cache[0][i] == -1) {
            root = i;
            break;
        }
    }
    memset(visited, 0, sizeof(visited));

    dfs(root, 1);

    ll ans = 0;

    for(int i = 0; i < childs.size(); i++) {
        for(int j = i + 1; j < childs.size(); j++) {
            ll sum = 0;
            ll l = childs[i];
            ll r = childs[j];
            ll l_depth = depth[l];
            ll r_depth = depth[r];
            if (l_depth > r_depth) {
                swap(l_depth, r_depth);
                swap(l, r);
            }
            ll diff = r_depth - l_depth;
            for(int k = 20; diff > 0 & k >= 0; k--) {
                if(diff & (1 << k)) {
                    sum += cost[k][r];
                    r = cache[k][r];
                }
            }

            for(int k = 20; k >= 0; k--) {
                if(cache[k][l] != cache[k][r]) {
                    sum += cost[k][l];
                    sum += cost[k][r];
                    l = cache[k][l];
                    r = cache[k][r];
                }
            }
            sum += cost[0][l] + cost[0][r];
            ans += (sum * sum);
        }
    }
    cout << ans;
    return 0;
}


/*
#include <bits/stdc++.h>

using namespace std;

int arr[1001][1001];
pair <int, int> s[1001];
pair <int, int> b[1001];
int n,m,c1,c2;
int yy1,y2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i].first >> s[i].second;
    cin >> m;
    for(int i = 0; i < m; i++) cin >> b[i].first >> b[i].second;
    cin >> c1 >> c2;

    sort(s,s+n);
    sort(b, b+m);
    int it;
    int scnt = 0, bcnt = 0, ret = c1;
    for(int i = 0; i < n ; i++){
        for(int j = i + 1; j < n; j++){
        yy1 = max(s[i].second,s[j].second);
        y2 = min(s[i].second,s[j].second);
        scnt = bcnt = 0;
        it = lower_bound(s,s+n, s[i]) - s;
        for(int k = it; k < n && s[k].first <= s[j].first; k++){
            if(yy1 >= s[k].second && y2 <= s[k].second) scnt++;
        }
        it = lower_bound(b,b+m, b[i]) - b;
        for(int k = it; k < m && b[k].first <= s[j].first; k++){
            if(yy1 >= b[k].second && y2 <= b[k].second) bcnt++;
        }

        ret = max(ret,(scnt * c1) - (bcnt*c2));
        }
    }
    cout << ret;

    return 0;
}
*/
/*
2
1 1
1 2
*/
