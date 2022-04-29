#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX=110;

int n;
struct pos{
    int x, y, z;
    long long int val;
    bool operator<(const pos &p)const{
        return val < p.val;
    }
};

long double ans=1e30;
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
            for(int l=j+1;l<n;l++) {
                int x1=p[i].x-p[j].x;
                int y1=p[i].y-p[j].y;
                int z1=p[i].z-p[j].z;
                int x2=p[i].x-p[l].x;
                int y2=p[i].y-p[l].y;
                int z2=p[i].z-p[l].z;
                int ux=y1*z2-y2*z1;
                int uy=z1*x2-z2*x1;
                int uz=x1*y2-x2*y1;
                ll cmp = 1LL * ux * p[i].x + 1LL * uy * p[i].y + 1LL * uz * p[i].z;

                int sx1=0, sy1=0, sz1=0, c1=0;
                int sx2=0, sy2=0, sz2=0, c2=0;
                for(int k=0;k<n;k++){
                    ll q = 1LL * ux * p[k].x + 1LL * uy * p[k].y + 1LL * uz * p[k].z;
                    if(q < cmp) c1++, sx1 += p[k].x, sy1 += p[k].y, sz1 += p[k].z;
                    else if(q > cmp) c2++, sx2 += p[k].x, sy2 += p[k].y, sz2 += p[k].z;
                }
                for(int t=0; t<8; t++) {
                    int _c1 = c1, _c2 = c2;
                    int _sx1 = sx1, _sy1 = sy1, _sz1 = sz1;
                    int _sx2 = sx2, _sy2 = sy2, _sz2 = sz2;
                    if(t & 1) _c1++, _sx1+=p[i].x, _sy1+=p[i].y, _sz1+=p[i].z;
                    else _c2++, _sx2+=p[i].x, _sy2+=p[i].y, _sz2+=p[i].z;

                    if(t & 2) _c1++, _sx1+=p[j].x, _sy1+=p[j].y, _sz1+=p[j].z;
                    else _c2++, _sx2+=p[j].x, _sy2+=p[j].y, _sz2+=p[j].z;

                    if(t & 4) _c1++, _sx1+=p[l].x, _sy1+=p[l].y, _sz1+=p[l].z;
                    else _c2++, _sx2+=p[l].x, _sy2+=p[l].y, _sz2+=p[l].z;

                    if(_c1!=0 && _c2!=0){
                        ans=min((long double) -(1.0 * _sx1 * _sx1 + 1.0 * _sy1 * _sy1 + 1.0 * _sz1 * _sz1)/(_c1)-(1.0 * _sx2 * _sx2 + 1.0 * _sy2 * _sy2 + 1.0 * _sz2 * _sz2) / (_c2)+sxx+syy+szz, ans);
                    }
                }
            }
        }
    }

    long double ans2 = 0;
    ans2=(long double)-(sx*sx+sy*sy+sz*sz) / n + sxx + syy + szz;
    if(K==1) printf("%.6Lf\n", ans2);
    else printf("%.6Lf\n", min(ans, ans2));
    return 0;
}
