#include <bits/stdc++.h>

using namespace std;

int n1, n2;
pair<int, int> p1[1005], p2[1005];
set<int> x, y;
map<int, int> xmap, ymap;
int cx, cy;
int c1, c2;

struct point {
    int x, y, c;
};

vector<point> p;

struct node {
    int ls, rs, ms, s;
} sgt[4005];

void build(int l, int r, int i) {
    if (l + 1 == r) {
        sgt[i].ls = sgt[i].rs = sgt[i].ms = sgt[i].s = 0;
        return;
    }
    int m = (l + r) / 2;
    build(l, m, i * 2 + 1);
    build(m, r, i * 2 + 2);
}

void update(int l, int r, int i, int x, int y) {
    if (l + 1 == r) {
        sgt[i].s = y;
        if (y > 0) {
            sgt[i].ls = sgt[i].rs = sgt[i].ms = y;
        } else {
            sgt[i].ls = sgt[i].rs = sgt[i].ms = 0;
        }
        return;
    }
    int m = (l + r) / 2;
    if (x < m) {
        update(l, m, i * 2 + 1, x, y);
    } else {
        update(m, r, i * 2 + 2, x, y);
    }
    sgt[i].ls = max(sgt[i * 2 + 1].ls, sgt[i * 2 + 1].s + sgt[i * 2 + 2].ls);
    sgt[i].rs = max(sgt[i * 2 + 1].rs + sgt[i * 2 + 2].s, sgt[i * 2 + 2].rs);
    sgt[i].ms = max(sgt[i * 2 + 1].rs + sgt[i * 2 + 2].ls, max(sgt[i * 2 + 1].ms, sgt[i * 2 + 2].ms));
    sgt[i].s = sgt[i * 2 + 1].s + sgt[i * 2 + 2].s;
}

int ans;

int main() {
    scanf("%d", &n1);
    for (int i = 1; i <= n1; i++) {
        scanf("%d %d", &p1[i].first, &p1[i].second);
        x.insert(p1[i].first);
        y.insert(p1[i].second);
    }
    scanf("%d", &n2);
    for (int i = 1; i <= n2; i++) {
        scanf("%d %d", &p2[i].first, &p2[i].second);
        x.insert(p2[i].first);
        y.insert(p2[i].second);
    }
    scanf("%d %d", &c1, &c2);
    for (auto it = x.begin(); it != x.end(); ++it) {
        xmap[*it] = ++cx;
    }
    for (auto it = y.begin(); it != y.end(); ++it) {
        ymap[*it] = ++cy;
    }
    for (int i = 1; i <= n1; i++) {
        p.push_back({xmap[p1[i].first], ymap[p1[i].second], c1});
    }
    for (int i = 1; i <= n2; i++) {
        p.push_back({xmap[p2[i].first], ymap[p2[i].second], -c2});
    }
    sort(p.begin(), p.end(), [&] (point x, point y) {
        if (x.y == y.y) {
            return x.x < y.x;
        } else {
            return x.y < y.y;
        }
    });
    for (int i = 0; i < p.size(); i++) {
        build(1, cx + 1, 0);
        for (int j = i; j < p.size(); j++) {
            update(1, cx + 1, 0, p[j].x, p[j].c);
            ans = max(ans, sgt[0].ms);
        }
    }
    printf("%d\n", ans);
}
