#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <cstring>
using namespace std;

#define md ((s + e) >> 1)
#define lch n * 2, s, md
#define rch n * 2 + 1, md + 1, e

typedef long long ll;
typedef pair<int, int> pii;

struct Crd{ int x, y; };
Crd crd1[1005], crd2[1005];
int cum[2005][2005], minc[2005][2005];
vector<int> xs, ys;

struct Node {
    ll lmax, rmax, sum, max;
} tree[8006];

Node merge(Node L, Node R) {
    Node ret = {max(L.lmax, L.sum + R.lmax), max(R.rmax, R.sum + L.rmax), L.sum + R.sum};
    ret.max = max({L.max, R.max, ret.lmax, ret.rmax, R.lmax + L.rmax});
    return ret;
}
void update(int i, ll v, int n = 1, int s = 1, int e = 2000) {
    if (i < s || e < i) return;
    if (s != e) {
        update(i, v, lch);
        update(i, v, rch);
        tree[n] = merge(tree[n * 2], tree[n * 2  + 1]);
    }
    else {
        tree[n] = {v, v, v, v};
    }
}

//pii count(int x1, int x2, int y1, int y2){
////    printf("%d %d %d %d\n", x1, x2, y1, y2);
//    return make_pair(cum1[x2][y2] - cum1[x1 - 1][y2] - cum1[x2][y1 - 1] + cum1[x1 - 1][y1 - 1],
//                     cum2[x2][y2] - cum2[x1 - 1][y2] - cum2[x2][y1 - 1] + cum2[x1 - 1][y1 - 1]);
//}
struct Str {
    int x; ll cost;
};

vector<Str> v[2005];

int main()
{
    int N1, N2; scanf("%d", &N1);
    for(int i = 0; i < N1; i++){
        scanf("%d %d", &crd1[i].x, &crd1[i].y);
        xs.push_back(crd1[i].x);
        ys.push_back(crd1[i].y);
    }
    scanf("%d", &N2);
    for(int i = 0; i < N2; i++){
        scanf("%d %d", &crd2[i].x, &crd2[i].y);
        xs.push_back(crd2[i].x);
        ys.push_back(crd2[i].y);
    }

    ll C1, C2; scanf("%lld %lld", &C1, &C2);
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    int X = 0, Y = 0;
    map<int, int> xidx, yidx;
    xidx[xs[0]] = ++X;
    for(int i = 1; i < xs.size(); i++)
        if(xs[i] != xs[i - 1]) xidx[xs[i]] = ++X;
    yidx[ys[0]] = ++Y;
    for(int i = 1; i < ys.size(); i++)
        if(ys[i] != ys[i - 1]) yidx[ys[i]] = ++Y;

    for(int i = 0; i < N1; i++) {
        crd1[i].x = xidx[crd1[i].x], crd1[i].y = yidx[crd1[i].y];
        v[crd1[i].y].push_back({crd1[i].x, C1});
    }
    for(int i = 0; i < N2; i++) {
        crd2[i].x = xidx[crd2[i].x], crd2[i].y = yidx[crd2[i].y];
        v[crd2[i].y].push_back({crd2[i].x, -C2});
    }
//    for(int i = 0; i < N1; i++)
//        cum[crd1[i].x][crd1[i].y] += C1;
//    for(int i = 0; i < N2; i++)
//        cum[crd2[i].x][crd2[i].y] -= C2;
//
//    for(int i = 1; i <= X; i++)
//        for(int j = 1; j <= Y; j++){
//            cum[i][j] += cum[i - 1][j] + cum[i][j - 1] - cum[i - 1][j - 1];
//        }
    ll ans = max(C1, C2);

    for (int y1 = 1; y1 <= 2000; y1++) {
        memset(tree, 0, sizeof tree);
        for (int y2 = y1; y2 <= 2000; y2++) {
            for (Str x : v[y2]) {
                update(x.x, x.cost);
            }
        }
        ans = max(ans, tree[1].max);
    }

    printf("%lld\n", ans);

    return 0;
}

