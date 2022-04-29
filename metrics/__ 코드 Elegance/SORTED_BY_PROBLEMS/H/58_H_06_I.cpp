#include <bits/stdc++.h>
using namespace std;
struct Data{
    int x,y,t;
    void input(){scanf("%d%d",&x,&y);}
    bool operator<(const Data&r)const{return x<r.x;}
}a[1010];
int x[2010],y[2010],s[2010][2010],mn[2010][2010];
struct Tree{
    int s,lmx,rmx,mx;
}t[1<<11];
void update(int n,int s,int e,int k,int v){
    if(s==e){
        t[n].s+=v;
        if(t[n].s>0)t[n].lmx=t[n].rmx=t[n].mx=t[n].s;
        return;
    }
    int l=n*2,r=l+1,m=(s+e)/2;
    if(k>m)update(r,m+1,e,k,v);
    else update(l,s,m,k,v);
    t[n].s+=v;
    t[n].lmx=max(t[l].lmx,t[l].s+t[r].lmx);
    t[n].rmx=max(t[r].rmx,t[r].s+t[l].rmx);
    t[n].mx=max(max(max(max(t[l].mx,t[r].mx),t[l].rmx+t[r].lmx),t[n].lmx),t[n].rmx);
}
int main(){
    int i,j,n,m,c,d,ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i)a[i].input(),y[i]=a[i].y,a[i].t=1;
    scanf("%d",&m);
    for(i=1;i<=m;++i)a[n+i].input(),y[n+i]=a[n+i].y;
    scanf("%d%d",&c,&d);
    n+=m;
    sort(a+1,a+n+1);
    sort(y+1,y+n+1);
    for(i=1;i<=n;++i){
        a[i].y=lower_bound(y+1,y+n+1,a[i].y)-y;
        memset(t,0,sizeof t);
        for(j=i;j;--j){
            update(1,1,n,a[j].y,a[j].t?c:-d);
            ans=max(ans,t[1].mx);
        }
    }
    printf("%d",ans);
    return 0;
}
/*
3
0 5
3 3
8 -1
3
1 4
6 0
7 1
3 2
*/
