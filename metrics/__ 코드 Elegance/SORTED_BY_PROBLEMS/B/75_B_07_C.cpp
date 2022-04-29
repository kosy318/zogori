#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;
ll n, m;
ll a[100100],b[100100],c[100100],s[100100],r[100100];
vector<ll>v[100100];
vector<ll>len[100100];
vector<ll>d[100100];
vector<ll>l[100100];
void dfs(ll x)
{
    for(ll i=0;i<v[x].size();i++)
    {
        if(r[x]==v[x][i])continue;
        r[v[x][i]]=x;
        d[x].push_back(v[x][i]);
        l[x].push_back(len[x][i]);
        dfs(v[x][i]);
    }
}
void f(ll x)
{
    if(d[x].size()==0)
    {
        a[x]=1;
        return;
    }
    for(ll i=0;i<d[x].size();i++)
    {
        f(d[x][i]);
        a[x]+=a[d[x][i]];
        b[x]+=2*a[d[x][i]]*l[x][i]+b[d[x][i]];
        c[x]+=a[d[x][i]]*l[x][i]*l[x][i]+b[d[x][i]]*l[x][i]+c[d[x][i]];
        s[x]+=s[d[x][i]]+a[d[x][i]]*l[x][i];
    }
    for(ll i=0;i<d[x].size();i++)
    {
        for(ll j=0;j<i;j++)
        {
            if(i==j)continue;
            ll p=l[x][i]+l[x][j];
            m+=a[d[x][i]]*(c[d[x][j]]+2*p*s[d[x][j]]+p*p*a[d[x][j]])+b[d[x][i]]*(s[d[x][j]]+p*a[d[x][j]])+c[d[x][i]]*a[d[x][j]];
        }
    }
}
int main(void)
{
    scanf("%lld",&n);
    for(ll i=0;i<n;i++)r[i]=-1;
    for(ll i=1;i<n;i++)
    {
        ll x,y,z;
        scanf("%lld %lld %lld",&x,&y,&z);
        x--;
        y--;
        v[x].push_back(y);
        v[y].push_back(x);
        len[x].push_back(z);
        len[y].push_back(z);
    }
    dfs(0);
    f(0);
    if(d[0].size()==1)m+=c[0];
    printf("%lld\n",m);
}
