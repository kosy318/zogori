#include <bits/stdc++.h>
#define sz(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
struct point {
    int x,y; ll v;
};
struct node {
    ll sum, mx, lmax, rmax;
    node() {
        sum = mx = lmax = rmax = 0;
    }
};
struct segtree {
    node tree[4*2010];
    void update(int h,int tl,int tr,int p,int x) {
        if(tr < p || p < tl) return;
        if(tl == tr) {
            tree[h].sum += x;
            tree[h].lmax = tree[h].rmax = tree[h].mx = tree[h].sum;
            if(x < 0) {
            //printf("h:%d\n",h);
            }
            return;
        }
        int mid = (tl + tr) / 2;
        update(h*2, tl, mid, p, x);
        update(h*2+1, mid+1, tr, p, x);
        tree[h].lmax = max(tree[h*2].lmax, tree[h*2].sum + tree[h*2+1].lmax);
        tree[h].rmax = max(tree[h*2+1].rmax, tree[h*2+1].sum + tree[h*2].rmax);
        tree[h].mx = max(tree[h*2].mx, tree[h*2+1].mx);
        tree[h].mx = max(tree[h].mx, tree[h*2].rmax + tree[h*2+1].lmax);
        tree[h].sum = tree[h*2].sum + tree[h*2+1].sum;
    }
    ll query() {
        return tree[1].mx;
    }
    void clear() {
        int i;
        for(i=0;i<4*2010;i++) {
            tree[i].sum = tree[i].mx = tree[i].lmax = tree[i].rmax = 0;
        }
    }
} st;

int n1, n2, n;
ll c1, c2;
point p[2010];

int main()
{
    int i,j;
    scanf("%d",&n1);
    vector<int> vy;
    for(i=1;i<=n1;i++) {
        scanf("%d%d",&p[i].x,&p[i].y);
        vy.push_back(p[i].y);
    }
    scanf("%d",&n2);
    n=n1+n2;
    for(i=1;i<=n2;i++){
        scanf("%d%d",&p[n1+i].x,&p[n1+i].y);
        vy.push_back(p[n1+i].y);
    }
    scanf("%lld%lld",&c1,&c2);
    for(i=1;i<=n1;i++) p[i].v = c1;
    for(i=n1+1;i<=n;i++) p[i].v = -c2;
    sort(vy.begin(), vy.end());
    vy.erase(unique(vy.begin(),vy.end()),vy.end());
    sort(p+1,p+n+1,[&](const point& a,const point& b) {
        return a.x==b.x ? a.y<b.y : a.x<b.x;
    });
    for(i=1;i<=n;i++) {
        p[i].y = lower_bound(vy.begin(),vy.end(),p[i].y) - vy.begin() + 1;
    }

    ll ans = 0;
    for(i=1;i<=n;i++) {
        if(i!=1 && p[i].x==p[i-1].x) continue;
        st.clear();
        for(j=i;j<=n;j++) {
        //printf("p[%d]:%lld\n",j,p[j].v);
            st.update(1,1,sz(vy),p[j].y,p[j].v);
            if(j==n || p[j].x != p[j+1].x) {
                ans = max(ans, st.query());
                //printf("i:%d, j:%d(%d,%d), mx:(%lld %lld %lld %lld %lld %lld %lld)\n",i,j,p[j].x,p[j].y,st.query(),st.tree[2].mx, st.tree[3].mx, st.tree[4].mx, st.tree[5].mx, st.tree[6].mx, st.tree[7].mx);
            }
        }
    }
    printf("%lld", ans);
    return 0;
}

/*
2
-1 -1
4 4
2
0 0
2 2
5 2

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
