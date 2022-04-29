#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int max_n = 100005;
int N;
int cache[20][max_n];
int cost[20][max_n];
vector<pair<int,int> > adj[max_n];
vector<int> childs;
int depth[max_n];
int visited[max_n];
bool isChilds[max_n];
void dfs(int root, int cnt) {
    visited[root] = 1;
    depth[root] = cnt;
    for(int i = 0; i < adj[root].size(); i++) {
        int next = adj[root][i].first;
        if(!visited[next]) dfs(next, cnt + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    memset(cache, -1, sizeof(cache));


    for(int i = 0; i < N; i++) {
        sort(adj[i].begin(), adj[i].end());
        if(adj[i].size() == 1) {
            cache[0][i] = adj[i][0].first; // parent setting
            cost[0][i] = adj[i][0].second; // cost setting
            childs.push_back(i);
            isChilds[i] = true;
        }
    }
    memset(isChilds, 0, sizeof(isChilds));
    queue<int> q;
    for(int i = 0; i < childs.size(); i++) {
        q.push(childs[i]);
    }
    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        if(isChilds[curr]) continue;
        isChilds[curr] = 1;

        for(int i = 0; i < adj[curr].size(); i++) {
            int next = adj[curr][i].first;
            int next_cost = adj[curr][i].second;

            if(!isChilds[next]){
                cache[0][curr] = next; // parent setting
                cost[0][curr] = next_cost; // cost setting
                q.push(next);
            }
        }
    }

    for(int i = 1; i < 20; i++) { // 2^n
        for(int j = 0; j < N; j++) {
            if(cache[i - 1][cache[i - 1][j]] != -1) {

                cost[i][j] += cost[i - 1][cache[i - 1][j]];
                cache[i][j] = cache[i - 1][cache[i - 1][j]];
            }
        }
    }

    int root = childs[0];
    while(1) {
        if(cache[0][root] == -1) break;
        root = cache[0][root];
    }

    dfs(root, 1);

    ll ans = 0;
    for(int i = 0; i < childs.size(); i++) {
        for(int j = i + 1; j < childs.size(); j++) {
            int l = childs[i];
            int r = childs[j];
            int sum = 0;

            int l_depth = depth[l];
            int r_depth = depth[r];
            if (l_depth > r_depth) {
                swap(l_depth, r_depth);
                swap(l, r);
            }

            int diff = r_depth - l_depth;
            for(int k = 0; k < 20; k++) {
                if(diff & (1 << k)) {

                    sum += cost[k][r];
                    r = cache[k][r];
                }
            }

            for(int k = 20 - 1; k >= 0; k--) {
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
typedef long long ll;

int arr[1001][1001];
pair <int, int> xy[1001];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    return 0;
}
*/
