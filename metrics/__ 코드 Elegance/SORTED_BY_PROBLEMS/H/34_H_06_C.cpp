#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N1, N2, N, C1, C2;
const int N_ = 2050;

struct point {
    int x, y, c;
} points[N_];

using lint = int;

struct Node {
    lint pref, suff, tot, ans;
    Node operator* (const Node &nd) const {
        Node ret = Node{
                max(pref, tot + nd.pref),
                max(nd.suff, suff + nd.tot),
                tot + nd.tot,
                0
        };
        ret.ans = max({
                              ans, nd.ans,
                              ret.pref, ret.suff, ret.tot,
                              suff + nd.pref
                      });
        return ret;
    }
};

const int LEAF = 2047;

Node tree[LEAF + LEAF];

void update (int x, int v) {
    x += LEAF;
    tree[x] = Node{v, v, v, v};
    while(x >>= 1) {
        tree[x] = tree[x+x] * tree[x+x+1];
    }
}

vector<pair<int,int>> ys; int Y;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    scanf("%d", &N1);
    for(int i = 1; i <= N1; i++) {
        point &p = points[i];
        scanf("%d%d", &p.x, &p.y);
        ys.emplace_back(p.y, i);
    }
    scanf("%d", &N2);
    for(int i = 1; i <= N2; i++) {
        point &p = points[i+N1];
        scanf("%d%d", &p.x, &p.y);
        ys.emplace_back(p.y, i+N1);
    }
    sort(ys.begin(), ys.end());
    for(int i = 0; i < ys.size(); ) {
        int j = i;
        Y += 1;
        while(j < ys.size() && ys[i].first == ys[j].first) {
            points[ys[j].second].y = Y;
            j++;
        }
        i = j;
    }
    scanf("%d%d", &C1, &C2);

    N = N1 + N2;
    for(int i = 1; i <= N; i++) {
        points[i].c = (i <= N1) ? C1 : -C2;
    }

    sort(points + 1, points + N + 1, [&](const point &p1, const point &p2) {
        return p1.x < p2.x;
    });

    lint ans = -1e18;

    for(int i = 1; i <= N;) {
        memset(tree, 0, sizeof tree);
        for(int j = i; j <= N; ) {
            int k = j;
            while(k <= N && points[j].x == points[k].x) {
                update(points[k].y, points[k].c);
                k++;
            }
            j = k;
            ans = max(ans, tree[1].ans);
        }

        int j = i;
        while(j <= N && points[i].x == points[j].x) j++;
        i = j;
    }

    printf("%lld\n", ans);
}