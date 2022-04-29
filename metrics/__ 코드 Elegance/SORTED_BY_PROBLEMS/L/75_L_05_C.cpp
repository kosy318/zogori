#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MAX=15002;

ll w[MAX], dp[MAX], ans;

struct mine{
    ll x, y, z;
};

ll mr, n;

mine m[MAX];

int main()
{
    scanf("%lld%lld",&mr,&n);
    for(ll i=0;i<mr;i++){
        scanf("%d",&w[i]);
    }
    for(ll i=0;i<n;i++){
        scanf("%lld%lld%lld",&m[i].x,&m[i].y,&m[i].z);
        m[i].z=w[m[i].z-1]*(m[i].y-m[i].x);
    }
    for(ll i=0;i<15000;i++){
        for(ll j=0;j<n;j++) if(m[j].x>=i){
            dp[m[j].y]=max(dp[m[j].y], dp[i]+m[j].z);
        }
    }
    for(ll i=0;i<15000;i++){
        ans=max(ans, dp[i]);
    }
    printf("%lld\n",ans);
    return 0;
}
