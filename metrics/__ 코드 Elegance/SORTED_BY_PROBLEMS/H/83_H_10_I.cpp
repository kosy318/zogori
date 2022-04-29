#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

struct node {
    int x;
    int y;
    long long cost;
    const bool operator< (const node &a) const {
        return y < a.y;
    }
};

int xs[2020];
int ys[2020];

node o[1010], u[1010];

node h[2020];

struct tnode {
    long long lmax;
    long long rmax;
    long long sum;
    long long maxd;
};

tnode tree[8020];

void update(int cur, int l, int r, int t, int val) {
    if(t < l || r < t) return;
    if(l == r) {
        tree[cur].sum += val;
        tree[cur].maxd = tree[cur].sum;
        tree[cur].lmax = tree[cur].sum;
        tree[cur].rmax = tree[cur].sum;
        return;
    }
    int mid = (l + r) >> 1;
    int left = cur << 1;
    int right = left + 1;
    update(left, l, mid, t, val);
    update(right, mid + 1, r, t, val);

    tree[cur].lmax = max(tree[right].lmax + tree[left].sum, tree[left].lmax);
    tree[cur].lmax = max(tree[cur].lmax, tree[left].sum);

    tree[cur].rmax = max(tree[left].rmax + tree[right].sum, tree[right].rmax);
    tree[cur].rmax = max(tree[cur].rmax, tree[right].sum);

    tree[cur].sum = tree[left].sum + tree[right].sum;

    tree[cur].maxd = max({tree[left].maxd, tree[right].maxd, tree[cur].lmax, tree[cur].rmax, tree[cur].sum});
}

int main() {
    int xk = 0, yk = 0;
    int k = 0;
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &o[i].x, &o[i].y);
        ys[yk++] = o[i].y;
        xs[xk++] = o[i].x;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u[i].x, &u[i].y);
        ys[yk++] = u[i].y;
        xs[xk++] = u[i].x;
    }

    sort(ys, ys + yk);
    yk = unique(ys, ys + yk) - ys;

    sort(xs, xs + xk);
    xk = unique(xs, xs + xk) - xs;

    map<int, int> tr;
    for(int i = 0; i < xk; i++) tr[xs[i]] = i + 1;

    int s, b;
    scanf("%d %d", &s, &b);

    for(int i = 0; i < n; i++) {
        h[k] = o[i];
        h[k].x = tr[h[k].x];
        h[k++].cost = s;
    }
    for(int i = 0; i < m; i++) {
        h[k] = u[i];
        h[k].x = tr[h[k].x];
        h[k++].cost = -b;
    }

    sort(h, h + k);

    long long ans = -(1ll << 60);
    for(int i = 0; i < yk; i++) {
        for(int j = 0; j < 8020; j++) tree[j] = { -(1ll << 60), -(1ll << 60), 0, -(1ll << 60) };
        int l = 0;
        while(l < k && h[l].y < ys[i]) l++;
        for(int j = i; j < yk; j++) {
            while(l < k && h[l].y == ys[j]) {
                update(1, 1, xk, h[l].x, h[l].cost);
                l++;
            }
            if(ans < tree[1].maxd) ans = tree[1].maxd;
        }
    }
    printf("%lld\n", ans);
    return 0;
}