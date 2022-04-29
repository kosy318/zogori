#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;
#define pb push_back

int n;
vector<pair<int,int> > adj[100001];
ll d1[100001];
ll d2[100001];
int sz[100001];
ll ans = 0;
void dfs(int x, int p){
    //cout << "dfs " <<x << ' ' << p << '\n';
    vector<ll> val1;
    vector<ll> val2;
    vector<ll> mysz;
    if(adj[x].size()==1) sz[x]++;
    ll tot = 0;
    for(auto nn : adj[x]){
        int nxt = nn.X;
        if(nxt == p) continue;
        int dist = nn.Y;
        dfs(nxt, x);
        d1[x] += d1[nxt]+(ll)dist*sz[nxt];
        //cout << x << ' ' << sz[nxt] << ' ' << dist << "-----\n";
        val1.pb(d1[nxt]+(ll)dist*sz[nxt]);
        tot += d1[nxt]+(ll)dist*sz[nxt];
        d2[x] += d2[nxt]+2*dist*d1[nxt]+sz[nxt]*dist*dist;
        val2.pb(d2[nxt]+2*dist*d1[nxt]+sz[nxt]*dist*dist);
        sz[x]+=sz[nxt];
        mysz.pb(sz[nxt]);
    }
    for(int i = 0; i < val1.size(); i++){
        ans += val2[i]*(sz[x]-mysz[i]);
        ans += val1[i]*(d1[x]-val1[i]);
    }
}
int main(void){
    //ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a,b,d;
        cin >> a >> b >> d;
        adj[a].pb({b,d});
        adj[b].pb({a,d});
    }
    int cc = 0;
    for(int i = 1; i <= n; i++){
        if(adj[i].size() != 1) cc = i;
    }

    dfs(cc,0);

    cout << ans << '\n';




}

/*
4
 1 4 1
 4 3 1
 2 4 1

 6
 1 5 1
 5 2 1
 5 6 1
 6 4 3
 6 3 2

 10
 1 2 10
 10 2 7
 3 2 8
 3 9 3
 9 8 2
 7 9 1
6 4 3
 4 5 2
 3 4 4
 */