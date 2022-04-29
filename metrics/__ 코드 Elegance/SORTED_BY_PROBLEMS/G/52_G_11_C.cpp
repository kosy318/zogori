#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

const int maxn=100010;
const int INF=1e9;

struct segtree {
    int tree[4*maxn];
    void init() {
        int i;
        for(i=0;i<4*maxn;i++) tree[i]=INF;
    }
    void update(int h,int tl,int tr,int p,int x) {
        if(tr < p || p < tl) return;
        if(tl == tr) {
            tree[h] = x;
            return;
        }
        int mid=(tl+tr)/2;
        update(h*2,tl,mid,p,x);
        update(h*2+1,mid+1,tr,p,x);
        tree[h]=min(tree[h*2],tree[h*2+1]);
    }
    int query(int h,int tl,int tr,int l,int r) {
        if(l > r) return INF;
        if(tr < l || r < tl) return INF;
        if(l <= tl && tr <= r) return tree[h];
        int mid = (tl+tr)/2;
        return min(query(h*2, tl, mid, l, r), query(h*2+1, mid+1, tr, l, r));
    }
} st;

int m, n;
int p[100010], c[100010];
int D[100010], E[100010];
int fir[100010];
int main()
{
    int i,j;
    scanf("%d%d", &m,&n);
    for(i=1;i<=n;i++) {
        scanf("%d", p+i);
    }
    for(i=1;i<=n;i++) {
        scanf("%d", c+i);
        if(i==1) fir[i]=1;
        else {
            if(c[i]==c[i-1]) fir[i]=fir[i-1];
            else fir[i]=i;
        }
    }

    int mn = INF;
    for(i=1;i<=n;i++) {
        if(fir[i]==1) {
            D[i] = 0;
            mn = min(mn, D[i]-i+1);
        } else {
            D[i] = st.query(1,1,n,fir[i], i-1);
            int i1 = lower_bound(p+1, p+i, 2*p[fir[i]-1]-p[i])-p;
            int i2 = lower_bound(p+1, p+i, 2*p[fir[i]]-p[i]+1)-p-1;
            i1 = max(i1, fir[fir[i]-1]);
            i2 = min(i2, fir[i]-1);
            D[i] = min(D[i], st.query(1,1,n,i1, i2));
            if(D[i] != INF) mn = min(mn, D[i]-i+1);
        }
        E[i] = mn + i;
        st.update(1,1,n,i, E[i]);
    }
    int ans = INF;
    for(i=n;i>=1;i--) {
        if(c[i] != c[n]) break;
        ans = min(ans, E[i]);
    }
    printf("%d", ans);
    return 0;
}

/*
2 6
0 3 4 7 8 11
1 1 1 2 2 1

2 6
0 3 4 7 8 11
1 2 1 2 2 1


*/
