#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> ppair;
vector<ppair>v[100010];
long long w[100010],val0,sum0,sum1,sum2,val1,val2,dap,arr[100010][3],x,y,z,n,d1[100010],d2[100010],par[100010],d3[100010],d0[100010];
//d0 : n
//d1 : a1+a2+...+an
//d2 : a1^2+a2^2 +...+an^2
//d3 : answer
void dfs(long long x,long long prev)
{
    long long i;
    par[x]=prev;
    for(i=0;i<v[x].size();i++)
    {
        if(v[x][i].first==prev) continue;
        dfs(v[x][i].first,x);
    }
}
void dfs2(long long x)
{
    long long i;
    if(v[x].size()==1){
        d0[x]=1;
        d1[x]=0;
        d2[x]=0;
        return;
    }
    for(i=0;i<v[x].size();i++)
    {
        if(par[x]==v[x][i].first) continue;
        arr[x][++w[x]]=i;
        dfs2(v[x][i].first);
    }
    d0[x]=d0[v[x][arr[x][1]].first]+d0[v[x][arr[x][2]].first];
    sum1=d1[v[x][arr[x][1]].first]+d0[v[x][arr[x][1]].first]*v[x][arr[x][1]].second;
    sum2=d1[v[x][arr[x][2]].first]+d0[v[x][arr[x][2]].first]*v[x][arr[x][2]].second;
    d1[x]=sum1+sum2;
    val1=d2[v[x][arr[x][1]].first]+v[x][arr[x][1]].second*v[x][arr[x][1]].second*d0[v[x][arr[x][1]].first]+2*v[x][arr[x][1]].second*d1[v[x][arr[x][1]].first];
    val2=d2[v[x][arr[x][2]].first]+v[x][arr[x][2]].second*v[x][arr[x][2]].second*d0[v[x][arr[x][2]].first]+2*v[x][arr[x][2]].second*d1[v[x][arr[x][2]].first];
    d2[x]=val1+val2;
    d3[x]=val1*d0[v[x][arr[x][2]].first]+val2*d0[v[x][arr[x][1]].first]+2*sum1*sum2;
}
int main()
{
    long long i,p;
    //freopen("input.txt","r",stdin);
    scanf("%lld",&n);
    for(i=1;i<n;i++)
    {
        scanf("%lld %lld %lld",&x,&y,&z);
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }
    for(i=1;i<=n;i++)
    {
        if(v[i].size()==3) p=i;
    }
    dfs(p,0);
    dfs2(p);
    for(i=1;i<=n;i++)
    {
        if(i==p) continue;
        dap+=d3[i];
    }
    sum0=d1[v[p][0].first]+d0[v[p][0].first]*v[p][0].second;
    sum1=d1[v[p][1].first]+d0[v[p][1].first]*v[p][1].second;
    sum2=d1[v[p][2].first]+d0[v[p][2].first]*v[p][2].second;

    val0=d2[v[p][0].first]+v[p][0].second*v[p][0].second*d0[v[p][0].first]+2*v[p][0].second*d1[v[p][0].first];
    val1=d2[v[p][1].first]+v[p][1].second*v[p][1].second*d0[v[p][1].first]+2*v[p][1].second*d1[v[p][1].first];
    val2=d2[v[p][2].first]+v[p][2].second*v[p][2].second*d0[v[p][2].first]+2*v[p][2].second*d1[v[p][2].first];

    dap+=((val1*d0[v[p][2].first]+val2*d0[v[p][1].first])+2*sum1*sum2);
    dap+=(val0*d0[v[p][2].first]+val2*d0[v[p][0].first]+2*sum0*sum2);
    dap+=(val0*d0[v[p][1].first]+val1*d0[v[p][0].first]+2*sum0*sum1);

    printf("%lld",dap);
    return 0;
}
/*
6
0 40
10 55
45 28
90 40
83 30
120 30

3
0 20
40 10
100 20
*/

