#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#define N 100000

using namespace std;

typedef long long ll;

bool vis[N+5];
ll in[N+5];
ll node_cnt[N+5], node_cnt2[N+5];
ll leaf;

ll level[N+5];
ll upcost[N+5], downcost[N+5];
vector< pair<ll, ll>> edge[N+5];
queue< ll > que;

struct Edge
{
    ll x, y, d;
} input[N+5];

int n;
int main (void)
{
    ll x, y, d;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("input.txt","r",stdin);

    cin >> n;
    for(int i=1;i<n;i++){
        cin >> x >> y >> d;
        input[i] = {x, y, d};
        edge[x].push_back({y,d});
        edge[y].push_back({x,d});
    }

    for(int i=1;i<=n;i++){
        //leaf
        if(edge[i].size() == 1){
            que.push(i);
            node_cnt[i] = 1;
            vis[i] = true;
            level[i] = 1;
            leaf++;
        }
    }

    // a^2

    ll maxlevel = 1;
    while(!que.empty()){
        int p = que.front(); que.pop();

        // only one root
        if(in[p] == edge[p].size()){
            continue;
        }

        for(auto e: edge[p]){
            if(level[e.first] != 0 && level[e.first] <= level[p]) continue;

            in[e.first]++;
            node_cnt[e.first] += node_cnt[p];

            upcost[e.first] += (ll)node_cnt[p] * e.second + upcost[p];
            level[e.first] = max(level[e.first], level[p] + 1);

            maxlevel = max(maxlevel, level[e.first]);

            // to upper
            if(in[e.first] == edge[e.first].size() - 1){
                que.push(e.first);
                vis[e.first] = true;
            }
        }
    }



    ll sq = 0;

    memset(vis, 0, sizeof(vis));

    for(int i=1;i<n;i++){
        x = input[i].x;
        y = input[i].y;
        d = input[i].d;

        if(level[x] > level[y]) swap(x,y);

        sq += (node_cnt[x] * (ll)(leaf - node_cnt[x])) * d*d;

        if(level[x] == maxlevel && !vis[x]){
            que.push(x);
            node_cnt2[x] = leaf;
            vis[x] = true;
        }
        if(level[y] == maxlevel && !vis[y]){
            que.push(y);
            node_cnt2[y] = leaf;
            vis[y] = true;
        }
        if(level[x] == level[y] && level[x] == maxlevel){
            downcost[x] = upcost[y] + (node_cnt[y] * d);
            node_cnt2[x] = leaf;
            downcost[y] = upcost[x] + (node_cnt[x] * d);
            node_cnt2[y] = leaf;
        }
    }

    while(!que.empty()){
        int p = que.front(); que.pop();

        for(auto e: edge[p]){
            if(level[e.first] >= level[p])
                continue;

            downcost[e.first] = downcost[p] + upcost[p] - (node_cnt[e.first] * e.second) - upcost[e.first] + ((leaf - node_cnt[e.first]) * e.second);
            node_cnt2[e.first] = leaf - node_cnt[e.first];
            if(level[e.first] != 1) que.push(e.first);
        }
    }

    ll ab = 0;
    for(int i=1;i<n;i++){
        x = input[i].x;
        y = input[i].y;
        d = input[i].d;

        if(level[x] < level[y]) swap(x,y);

        if(level[x] == level[y]){
            ll res = ((upcost[x] * node_cnt[y]) + (upcost[y] * node_cnt[x])) * d;
            ab += res;
            continue;
        }
        ll res = (((leaf - node_cnt[y]) * upcost[y] + (node_cnt[y] * (downcost[x] + upcost[x] - node_cnt[y]*d - upcost[y]))) * d);
        //cout << "ab " << x << ' ' << y << ' ' << (node_cnt[y] * (downcost[x] + upcost[x] - node_cnt[y]*d - upcost[y])) * upcost[y] << ':' << res  << endl;
        ab += res;

    }

    cout << ab + sq << endl;

    return 0;
}
