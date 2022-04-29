#include <bits/stdc++.h>

using namespace std;

const int MAX=110;

int n;
struct pos{
    int x, y, z;
    long long int val;
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
                ans=min((double) -(sx1*sx1+sy1*sy1+sz1*sz1)/(k+1)-(sx2*sx2+sy2*sy2+sz2*sz2)/(n-k-1)+sxx+syy+szz, ans);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int l=0;l<n;l++){
                int x1=p[i].x-p[j].x;
                int y1=p[i].y-p[j].y;
                int z1=p[i].z-p[j].z;
                int x2=p[i].x-p[l].x;
                int y2=p[i].y-p[l].y;
                int z2=p[i].z-p[l].z;
                int ux=y1*z2-y2*z1;
                int uy=z1*x2-z2*x1;
                int uz=x1*y2-x2*y1;
                for(int k=0;k<n;k++){
                    p[k].val=(long long int)ux*p[k].x+uy*p[k].y+uz*p[k].z;
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
                    ans=min((double) -(sx1*sx1+sy1*sy1+sz1*sz1)/(k+1)-(sx2*sx2+sy2*sy2+sz2*sz2)/(n-k-1)+sxx+syy+szz, ans);
                }
            }
        }
    }
    double ans2 = 0;
    ans2=(double)-(sx*sx+sy*sy+sz*sz)/n+sxx+syy+szz;
    if(K==1) printf("%.10f\n", ans2);
    else printf("%.10f\n", min(ans, ans2));
    return 0;
}
