#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans;
ll types[105];
ll dp[10002][10002];
struct Ore{
    ll values;
    ll starts;
    ll ends;
    ll types;
};
Ore ore[10005];
bool napsack[10005];
bool cmp(Ore a, Ore b){
    if(a.ends != b.ends){
        return a.ends>b.ends;
    }
    else if(a.starts != b.starts){
        return a.starts>b.starts;
    }
    else{
        return a.values>=b.values;
    }
}
void chk(ll x){
    queue<ll> q;
    ll tmp = 0;
    for(ll i = 0;i<=x-1;i++){
        if(ore[x].starts<ore[i].ends || ore[x].ends > ore[i].starts){
            q.push(i);
            tmp+=ore[i].values;
        }
    }
}
int main(){
    scanf("%lld%lld",&m,&n);
    for(ll i = 1;i<=m;i++){
        scanf("%lld",&types[i]);
    }
    for(ll i = 1;i<=n;i++){
        scanf("%lld%lld%lld",&ore[i].starts, &ore[i].ends, &ore[i].types);
        ore[i].values = (ore[i].ends-ore[i].starts)*types[ore[i].types];
    }
    ore[0].starts = 99999;
    sort(ore+1,ore+n+1,cmp);
    for(ll i = 0;i<=n;i++){
        for(ll j = i;j<=n;j++){
            dp[i][j+1] = dp[i][j];
            if(ore[i].starts>=ore[j+1].ends){
                dp[j+1][j+1] = max(dp[j+1][j+1],dp[i][j]+ore[j+1].values);
            }
        }
    }
    for(int i = 0;i<=n;i++){
        ans = max(ans,dp[i][n]);
    }
    printf("%lld",ans);
}
