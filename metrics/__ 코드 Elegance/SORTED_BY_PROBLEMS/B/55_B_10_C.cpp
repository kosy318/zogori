#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define ff first
#define ss second
#define N 100010

int n,vis[N],lf[N];
ll ans,tot,leaf,dap;
list<pii> ed[N];

ll dfs(int p,int w)
{
    if(vis[p]) return 0;
    vis[p]=1;
    ll ret=0;
    for(auto i:ed[p]) ret+=dfs(i.ff,i.ss);
    if(ed[p].size()==1) ret++;
    lf[p]=ret;
    tot+=(ll)w*ret;
    return ret;
}

ll dfss(int p,int w,ll t)
{
    if(vis[p]) return 0;
    vis[p]=1;
    t+=(ll)w*lf[p];
    ll ret=0;
    for(auto i:ed[p]) ret+=dfss(i.ff,i.ss,t);
    ans+=ret*w*(leaf-lf[p])*2+(ll)w*(tot-ret-t)*lf[p]+(ll)w*w*lf[p]*(leaf-lf[p]);
    //printf("%d %lld %lld\n",p,ret*w*(leaf-lf[p])*2,(ll)w*(tot-ret-t)*lf[p]);
    return ret+w*lf[p];
}

int main()
{
    //freopen("i8nput","r",stdin);
    cin>>n;
    for(int i=n-1,s,e,t;i--;)
        scanf("%d %d %d",&s,&e,&t),ed[s].pb({e,t}),ed[e].pb({s,t});//ans+=(ll)t*t;
    int tmp=1;
    for(int i=1;i<=n;i++)
        if(ed[i].size()==1) leaf++;
        else tmp=i;
    dfs(1,0);
    memset(vis,0,sizeof(vis));
    dfss(1,0,0);
    cout<<ans;
//    printf("%lld",tot+((ans*ans-tot)<<1));
    return 0;
}
