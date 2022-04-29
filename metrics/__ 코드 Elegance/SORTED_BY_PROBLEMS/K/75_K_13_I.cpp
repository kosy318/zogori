#include <bits/stdc++.h>

using namespace std;

const int MAX=110;

int n;
struct pos{
    int x, y, z, val;
    bool operator<(const pos &p)const{
        return val < p.val;
    }
};

double ans=1e30;
pos p[MAX];
int sx, sy, sz;
int sxx, syy, szz;
int K;

int main()
{
    scanf("%d%d",&n,&K);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
        sx+=p[i].x, sy+=p[i].y, sz+=p[i].z;
        sxx+=p[i].x*p[i].x, syy+=p[i].y*p[i].y, szz+=p[i].z*p[i].z;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int x1=p[i].x-p[j].x;
            int y1=p[i].y-p[j].y;
            int z1=p[i].z-p[j].z;
            for(int k=0;k<n;k++){
                p[k].val=x1*p[k].x+y1*p[k].y+z1*p[k].z;
            }
            sort(p, p+n);
            int sx1=0, sy1=0, sz1=0;
            int sx2=0, sy2=0, sz2=0;
            for(int k=0;k<n-1;k++){
                sx1+=p[k].x;
                sy1+=p[k].y;
                sz1+=p[k].z;
                sx2=sx-sx1;
                sy2=sy-sy1;
                sz2=sz-sz1;
                //sxx1+=p[k].x*p[k].x;
                //syy1+=p[k].y*p[k].y;
                //szz1+=p[k].z*p[k].z;
                //sxx2=sxx-sxx1;
                //syy2=syy-syy1;
                //szz2=szz-szz1;
                ans=min((double) -(sx1*sx1+sy1*sy1+sz1*sz1)/(k+1)-(sx2*sx2+sy2*sy2+sz2*sz2)/(n-k-1)+sxx+syy+szz, ans);
            }
        }
    }
    double ans2 = 0;
    ans2=(double)-(sx*sx+sy*sy+sz*sz)/n+sxx+syy+szz;
    if(K==1) printf("%.10f\n", ans2);
    else printf("%.10f\n", min(ans, ans2));
    return 0;
}
