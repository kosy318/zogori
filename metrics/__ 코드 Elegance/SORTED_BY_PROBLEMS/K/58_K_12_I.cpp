#include <bits/stdc++.h>
using namespace std;
struct Data{
    long long r,g,b;
    void input(){scanf("%lld%lld%lld",&r,&g,&b);}
}a[110];
Data vec(Data x,Data y){return {y.r-x.r,y.g-x.g,y.b-x.b};}
Data cross(Data x,Data y){return {x.g*y.b-x.b*y.g,x.b*y.r-x.r*y.b,x.r*y.g-x.g*y.r};}
int dot(Data x,Data y){return x.r*y.r+x.g*y.g+x.b*y.b>0;}
long long r,g,b,R,G,B,s;
long double ans=1e18;
int main(){
    int i,j,k,l,n,m,cnt;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)a[i].input(),R+=a[i].r,G+=a[i].g,B+=a[i].b,s+=a[i].r*a[i].r+a[i].g*a[i].g+a[i].b*a[i].b;
    ans=s-(long double)(R*R+G*G+B*B)/n;
    if(m==1){
        printf("%.6lf",(double)ans);
        return 0;
    }
    for(i=1;i<n-1;++i){
        for(j=i+1;j<n;++j){
            for(k=j+1;k<=n;++k){
                Data nv=cross(vec(a[i],a[j]),vec(a[i],a[k]));
                r=g=b=cnt=0;
                for(l=1;l<=n;++l)if(dot(vec(a[i],a[l]),nv))r+=a[l].r,g+=a[l].g,b+=a[l].b,++cnt;
                long long rr,gg,bb,ccnt;
                for(l=0;l<8;++l){
                    rr=r,gg=g,bb=b,ccnt=cnt;
                    if(l&1)rr+=a[i].r,gg+=a[i].g,bb+=a[i].b,++ccnt;
                    if(l&2)rr+=a[j].r,gg+=a[j].g,bb+=a[j].b,++ccnt;
                    if(l&4)rr+=a[k].r,gg+=a[k].g,bb+=a[k].b,++ccnt;
                    if(ccnt&&ccnt<n)ans=min(ans,s-(long double)(rr*rr+gg*gg+bb*bb)/ccnt-(long double)((R-rr)*(R-rr)+(G-gg)*(G-gg)+(B-bb)*(B-bb))/(n-ccnt));
                }
            }
        }
    }
    printf("%.6lf",(double)ans);
    return 0;
}
/*
3 2
93 50 26
40 0 77
99 10 29
*/
