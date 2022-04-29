#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
ll ba[200];
struct data{
    ll x,y,z;
    inline bool operator<(const data &temp)const{
        return y<temp.y;
    }
}b[20000];
ll it[400000],t=1;
ll fin(ll s,ll e,ll i,ll x){
    if(s>x) return 0;
    if(e<=x) return it[i];
    return max(fin(s,(s+e)/2,i*2,x),fin((s+e)/2+1,e,i*2+1,x));
}
void up(ll i,ll x){
    if(it[i]>=x) return;
    it[i]=x;
    while(i!=1){
        i/=2;
        it[i]=max(it[i*2],it[i*2+1]);
    }
}
int main() {
    ll n,m,i;
    scanf("%lld %lld",&n,&m);
    while(t<15000) t<<=1;
    for(i=1;i<=n;i++){
        scanf("%lld",&ba[i]);
    }
    for(i=1;i<=m;i++){
        scanf("%lld %lld %lld",&b[i].x,&b[i].y,&b[i].z);
        b[i].z=(b[i].y-b[i].x)*ba[b[i].z];
    }
    sort(b+1,b+m+1);
    ll mmax=-1;
    for(i=1;i<=m;i++){
        ll m=fin(1,t,1,b[i].x);
        if(mmax<m+b[i].z)mmax=m+b[i].z;
        up(t-1+b[i].y,m+b[i].z);
    }
    printf("%lld",mmax);
    return 0;
}