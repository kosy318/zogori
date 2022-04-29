#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
vector<long long> e[maxn],w[maxn];
long long ans[maxn],s[maxn],sz[maxn],sq[maxn];
bool vis[maxn];
int fa[maxn],d[maxn];
void dfs(int x)
{
    if(vis[x])return;
    vis[x]=1;
    long long sum=0;
    if(d[x]==1)sz[x]=1;
    for(int i=0;i<e[x].size();i++)
    {
        int k=e[x][i];
        if(vis[k])continue;
        fa[k]=x;
        dfs(k);
        sz[x]+=sz[k];
        s[x]+=s[k]+sz[k]*w[x][i];
        sq[x]+=sq[k]+2*s[k]*w[x][i]+w[x][i]*w[x][i]*sz[k];
        ans[x]+=ans[k];
    }
    for(int i=0;i<e[x].size();i++)
    {
        int k=e[x][i];
        if(fa[x]==k)continue;
        ans[x]+=(sq[k]+2*s[k]*w[x][i]+w[x][i]*w[x][i]*sz[k])*(sz[x]-sz[k]);
        ans[x]+=(s[k]+sz[k]*w[x][i])*(s[x]-s[k]-sz[k]*w[x][i]);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        long long u,v,wi;
        cin>>u>>v>>wi;
        e[u].push_back(v);
        e[v].push_back(u);
        d[u]++;
        d[v]++;
        w[u].push_back(wi);
        w[v].push_back(wi);
    }
    int root=1;
    for(int i=1;i<=n;i++)
    {
        if(d[i]!=1)
        {
            root=i;
            break;
        }
    }
    dfs(root);
    cout<<ans[root]<<endl;
    return 0;
}
