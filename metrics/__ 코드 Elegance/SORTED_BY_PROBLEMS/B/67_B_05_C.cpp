#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

vector<pii> v[200000];
ll n;
struct data{
    ll x,y,z;
}d[200000];
void dfs(ll i,ll p){
    ll j,t=0;
    for(j=0;j<v[i].size();j++){
        if(v[i][j].first==p) continue;
        t=1;
        dfs(v[i][j].first,i);
    }
    ll cnt=0,cnt1=0,cnt2=0;
    for(j=0;j<v[i].size();j++){
        if(v[i][j].first==p) continue;
        cnt+=d[v[i][j].first].x+v[i][j].second*d[v[i][j].first].y;
        cnt1+=d[v[i][j].first].y;
        cnt2+=d[v[i][j].first].y*v[i][j].second*v[i][j].second+d[v[i][j].first].z+2*v[i][j].second*d[v[i][j].first].x;
    }
    d[i].x=cnt;
    d[i].y=cnt1;
    d[i].z=cnt2;
    if(v[i].size()==1)d[i].y++;
}
void ddfs(ll i,ll p,ll g){
    if(p!=0){
        ll cnt=0,cnt1=0,su=0;
        cnt=d[p].x-(d[i].x+d[i].y*g)+(d[p].y-d[i].y)*g;
        su=d[p].x-(d[i].x+d[i].y*g);
        cnt1=d[p].z-(g*g*d[i].y+d[i].z+2*g*d[i].x)+(d[p].y-d[i].y)*g*g+2*g*su;
        d[i].x+=cnt;
        d[i].y=d[p].y;
        d[i].z+=cnt1;
    }
    ll j;
    for(j=0;j<v[i].size();j++){
        if(v[i][j].first==p) continue;
        ddfs(v[i][j].first,i,v[i][j].second);
    }
}
int main() {
    ll i;
    scanf("%lld",&n);
    for(i=1;i<n;i++){
        ll x,y,z;
        scanf("%lld %lld %lld",&x,&y,&z);
        v[x].push_back({y,z});
        v[y].push_back({x,z});
    }
    dfs(1,0);
    ddfs(1,0,0);
    ll cnt=0;
    for(i=1;i<=n;i++){
        if(v[i].size()==1) cnt+=d[i].z;
    }
    printf("%lld",cnt/2);
    return 0;
}