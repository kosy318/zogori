#include <bits/stdc++.h>
using namespace std;

int n;
const int MX=1e5+5;
int p[MX][20];
int dth[MX];
long long sz[MX];
int visit[MX];
long long sq[MX];
int dist[MX];
vector<pair<int,int>> a[MX];
int deg[MX];
long long ss[MX];
long long dp[MX];
long long cnt[MX];

inline int lca(int v,int u){
    int i,j;
    if(dth[v]>dth[u])swap(u,v);
    for(i=19 ; i>=0 ; i--)if(dth[u]-dth[v]>=(1<<i))u=p[u][i];
    if(u==v)return v;
    for(i=19 ; i>=0 ; i--){
        if(p[u][i]!=p[v][i]){
            u=p[u][i];
            v=p[v][i];
        }
    }
    return p[v][0];
}

void dfs(int v,int p){

    visit[v]=1;
    for(auto u: a[v]){
        if(!visit[u.first]){
            dth[u.first]=dth[v]+1;
            dist[u.first]=dist[v]+u.second;
            dfs(u.first,v);
            cnt[v]+=cnt[u.first];
        }
    }
    if(deg[v]==1)cnt[v]++;
    long long t=0;
    for(auto u: a[v]){
        int k=u.first;
        if(k==p)continue;
        long long l=u.second;
        dp[v]+=dp[k];
        dp[v]+=(sq[k]+l*l*cnt[k]+2*l*ss[k])*(cnt[v]-cnt[k]);
        sq[v]+=sq[k]+l*l*cnt[k]+2*l*ss[k];
        ss[v]+=ss[k]+l*cnt[k];

    }
  ///  cout<<dp[v]<<endl;
    for(auto u: a[v]){
        int k=u.first;
        if(k==p)continue;
        long long l=u.second;
        dp[v]+=(ss[k]+l*cnt[k])*(ss[v]-ss[k]-l*cnt[k]);
    }
   /// cout<<dp[v]<<endl;


}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    int i,j;
    for(i=1 ; i<n ; i++){
        int u,v,c;
        cin>>u>>v>>c;
        a[u].push_back({v,c});
        a[v].push_back({u,c});
        deg[u]++;
        deg[v]++;
    }
    int r=0;
    for(i=1 ; i<=n ; i++){
        if(deg[i]>=2){
            r=i;
            break;
        }
    }
    dfs(r,0);

    cout<<dp[r];
    return 0;
}
