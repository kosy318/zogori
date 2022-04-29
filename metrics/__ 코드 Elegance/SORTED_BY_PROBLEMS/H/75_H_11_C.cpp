#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define INF 1000000000
using namespace std;
using pr = pair<int, int>;

struct Node {
    int l, r, sum, mx;
};

Node maxnode(Node x, Node y) {
    Node res;
    res.l = max(x.l, x.sum + y.l);
    res.r = max(y.r, x.r + y.sum);
    res.sum = x.sum + y.sum;
    res.mx = max({ x.mx, y.mx, x.r + y.l });
    return res;
}

struct segtree {
    Node tree[22222];
    int base;
    void init(int x) {
        for(base=1; base<x; base<<=1);
        for(int i=1; i<=base+base; i++) tree[i] = { 0, 0, 0, 0 };
    }
    void update(int x, int y) {
        x += base - 1;
        tree[x].l += y, tree[x].r += y, tree[x].sum += y, tree[x].mx += y, x >>= 1;
        while(x) {
            tree[x] = maxnode(tree[x+x], tree[x+x+1]), x >>= 1;
        }
    }
    int RMQ(int s, int e) {
        s += base - 1, e += base - 1;
        Node resL = { -INF, -INF, 0, -INF };
        Node resR = { -INF, -INF, 0, -INF };
        while(s < e) {
            if(s & 1) resL = maxnode(resL, tree[s++]);
            if(!(e & 1)) resR = maxnode(tree[e--], resR);
            s >>= 1, e >>= 1;
        }
        if(s == e) resL = maxnode(resL, tree[s]);
        return max({ resL.mx, resR.mx, resL.r + resR.l });
    }
}seg;

int N, M, H, W, C1, C2;
pr A[1005], B[1005];
vector<pr> v[2005];
vector<int> X, Y;

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d %d", &A[i].first, &A[i].second), X.push_back(A[i].first), Y.push_back(A[i].second);
    scanf("%d", &M);
    for(int i=1; i<=M; i++) scanf("%d %d", &B[i].first, &B[i].second), X.push_back(B[i].first), Y.push_back(B[i].second);
    scanf("%d %d", &C1, &C2);
    sort(all(X)), sort(all(Y));
    X.resize(unique(all(X)) - X.begin()), Y.resize(unique(all(Y)) - Y.begin());
    int ans = 0;
    for(int i=1; i<=N; i++) {
        int idx = lower_bound(all(X), A[i].first) - X.begin() + 1;
        int y = lower_bound(all(Y), A[i].second) - Y.begin() + 1;
        v[idx].push_back(pr(y, C1));
    }
    for(int i=1; i<=M; i++) {
        int idx = lower_bound(all(X), B[i].first) - X.begin() + 1;
        int y = lower_bound(all(Y), B[i].second) - Y.begin() + 1;
        v[idx].push_back(pr(y, -C2));
    }
    for(int i=1; i<=sz(X); i++) {
        seg.init(sz(Y));
        for(int j=i; j<=sz(X); j++) {
            for(auto it : v[j]) {
                seg.update(it.first, it.second);
            }
            ans = max(ans, seg.RMQ(1, sz(Y)));
        }
    }
    printf("%d\n", ans);
}
