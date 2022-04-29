#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MAX=110;

ll n;
struct pos{
    ll x, y, z, w;
    ll val;
    bool operator<(const pos &p)const{
        if(val == p.val) return w < p.w;
        return val < p.val;
    }
};

long double ans=1e30;
pos p[MAX], q[MAX];
ll sx, sy, sz;
ll sxx, syy, szz;
ll K;

int main()
{
    scanf("%lld%lld",&n,&K);
    for(ll i=0;i<n;i++){
        scanf("%lld%lld%lld",&p[i].x,&p[i].y,&p[i].z);
        sx+=p[i].x, sy+=p[i].y, sz+=p[i].z;
        q[i].x=p[i].x;
        q[i].y=p[i].y;
        q[i].z=p[i].z;
        sxx+=p[i].x*p[i].x, syy+=p[i].y*p[i].y, szz+=p[i].z*p[i].z;
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++) if(i!=j){
            ll x1=p[i].x-p[j].x;
            ll y1=p[i].y-p[j].y;
            ll z1=p[i].z-p[j].z;
            for(ll k=0;k<n;k++){
                p[k].val=x1*p[k].x+y1*p[k].y+z1*p[k].z;
                p[k].w=0;
            }
            sort(p, p+n);
            ll sx1=0, sy1=0, sz1=0;
            ll sx2=0, sy2=0, sz2=0;
            for(ll k=0;k<n-1;k++){
                sx1+=p[k].x;
                sy1+=p[k].y;
                sz1+=p[k].z;
                sx2=sx-sx1;
                sy2=sy-sy1;
                sz2=sz-sz1;
                ans=min((long double) -(sx1*sx1+sy1*sy1+sz1*sz1)/(k+1)-(sx2*sx2+sy2*sy2+sz2*sz2)/(n-k-1)+sxx+syy+szz, ans);
            }
            for(ll k=0;k<n;k++){
                p[k]=q[k];
            }
        }
    }
    /*
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            for(ll l=0;l<n;l++){
                ll x1=p[i].x-p[j].x;
                ll y1=p[i].y-p[j].y;
                ll z1=p[i].z-p[j].z;
                ll x2=p[i].x-p[l].x;
                ll y2=p[i].y-p[l].y;
                ll z2=p[i].z-p[l].z;
                ll ux=y1*z2-y2*z1;
                ll uy=z1*x2-z2*x1;
                ll uz=x1*y2-x2*y1;
                for(ll k=0;k<n;k++){
                    p[k].val=(long long int)ux*p[k].x+uy*p[k].y+uz*p[k].z;
                }
                sort(p, p+n);
                ll sx1=0, sy1=0, sz1=0;
                ll sx2=0, sy2=0, sz2=0;
                for(ll k=0;k<n-1;k++){
                    sx1+=p[k].x;
                    sy1+=p[k].y;
                    sz1+=p[k].z;
                    sx2=sx-sx1;
                    sy2=sy-sy1;
                    sz2=sz-sz1;
                    ans=min((long double) -(sx1*sx1+sy1*sy1+sz1*sz1)/(k+1)-(sx2*sx2+sy2*sy2+sz2*sz2)/(n-k-1)+sxx+syy+szz, ans);
                }
                for(ll k=0;k<n;k++){
                    p[k]=q[k];
                }
            }
        }
    }
    */

    long double ans2 = 0;
    ans2=(long double)-(sx*sx+sy*sy+sz*sz)/n+sxx+syy+szz;
    if(K==1) printf("%.6Lf\n", ans2);
    else printf("%.6Lf\n", min(ans, ans2));
    return 0;
}
