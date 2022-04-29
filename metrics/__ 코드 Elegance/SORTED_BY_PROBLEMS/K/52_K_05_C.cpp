#include <bits/stdc++.h>
#define SQ(x) ((x)*(x))

using namespace std;
typedef pair<int,int> pii;
typedef long double ld;

struct point {
    int x,y,z;
};

int n,K;
point p[110];
bool grp[110];

int main()
{
    int i,j,k;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++) {
        scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
    }
    if(K==1) {
        ld sx=0, sy=0, sz=0;
        for(i=1;i<=n;i++) {
            sx+=p[i].x;
            sy+=p[i].y;
            sz+=p[i].z;
        }
        sx/=n; sy/=n; sz/=n;
        ld ans=0;
        for(i=1;i<=n;i++) {
            ans+=SQ(sx-p[i].x)+SQ(sy-p[i].y)+SQ(sz-p[i].z);
        }
        printf("%.6Lf",ans);
        return 0;
    }
    if(n<=2) {
        puts("0.000000");
        return 0;
    }
    point d;
    int x1,y1,z1,x2,y2,z2;
    int t;
    int i1,i2,i3;
    ld s1,s2;
    ld ans=9e18;
    for(i=1;i<=n;i++) {
        for(j=i+1;j<=n;j++) {
            for(k=j+1;k<=n;k++) {
                x1=p[j].x-p[i].x;
                y1=p[j].y-p[i].y;
                z1=p[j].z-p[i].z;
                x2=p[k].x-p[i].x;
                y2=p[k].y-p[i].y;
                z2=p[k].z-p[i].z;
                d.x=y1*z2-y2*z1;
                d.y=x2*z1-x1*z2;
                d.z=x1*y2-x2*y1;
                ld sx1=0, sy1=0, sz1=0;
                ld sx2=0, sy2=0, sz2=0;
                ld tx1=0, ty1=0, tz1=0;
                ld tx2=0, ty2=0, tz2=0;
                int tc1=0,tc2=0,sc1=0,sc2=0;
                for(t=1;t<=n;t++) {
                    if(t==i||t==j||t==k) continue;
                    if(d.x*(p[k].x-p[t].x)+d.y*(p[k].y-p[t].y)+d.z*(p[k].z-p[t].z) >= 0) {
                        sx1+=p[t].x;
                        sy1+=p[t].y;
                        sz1+=p[t].z;
                        sc1++;
                        grp[t]=0;
                    } else {
                        sx2+=p[t].x;
                        sy2+=p[t].y;
                        sz2+=p[t].z;
                        sc2++;
                        grp[t]=1;
                    }
                }
                for(i1=0;i1<2;i1++) {
                    for(i2=0;i2<2;i2++) {
                        for(i3=0;i3<2;i3++) {
                            tx1=sx1; ty1=sy1; tz1=sz1;
                            tx2=sx2; ty2=sy2; tz2=sz2;
                            tc1=sc1; tc2=sc2;
                            if(i1==0) {
                                tx1+=p[i].x;
                                ty1+=p[i].y;
                                tz1+=p[i].z;tc1++;
                                grp[i]=0;
                            }
                            else {
                                tx2+=p[i].x;
                                ty2+=p[i].y;
                                tz2+=p[i].z;tc2++;
                                grp[i]=1;
                            }
                            if(i2==0) {
                                tx1+=p[j].x;
                                ty1+=p[j].y;
                                tz1+=p[j].z;tc1++;
                                grp[j]=0;
                            }
                            else {
                                tx2+=p[j].x;
                                ty2+=p[j].y;
                                tz2+=p[j].z;tc2++;
                                grp[j]=1;
                            }
                            if(i3==0) {
                                tx1+=p[k].x;
                                ty1+=p[k].y;
                                tz1+=p[k].z;tc1++;
                                grp[k]=0;
                            }
                            else {
                                tx2+=p[k].x;
                                ty2+=p[k].y;
                                tz2+=p[k].z;tc2++;
                                grp[k]=1;
                            }
                            if(tc1) tx1/=tc1; ty1/=tc1; tz1/=tc1;
                            if(tc2) tx2/=tc2; ty2/=tc2; tz2/=tc2;
                            s1=0; s2=0;
                            for(t=1;t<=n;t++) {
                                if(grp[t]==0) {
                                    s1+=SQ(tx1-p[t].x)+SQ(ty1-p[t].y)+SQ(tz1-p[t].z);
                                } else {
                                    s2+=SQ(tx2-p[t].x)+SQ(ty2-p[t].y)+SQ(tz2-p[t].z);
                                }
                            }
                            if(s1+s2<ans) ans=s1+s2;
                        }
                    }
                }
            }
        }
    }
    printf("%.6Lf",ans);
    return 0;
}

/*
2 1
36 16 85
74 87 38

1 2
12 26 90

3 2
93 50 26
40 0 77
99 10 29
*/
