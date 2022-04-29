#include <bits/stdc++.h>
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef pair<int, int> pii;

pii red[1000];
pii blue[1000];
vector<int> xx, yy;

// same node?
struct node {
    int x, y, c;
    bool operator< (const node &v2) const {
        if (x != v2.x) return x < v2.x;
        if (y != v2.y) return y < v2.y;
        return c < v2.c;
    };
};
vector<node> v;

struct tnode{
    int lmav, rmav, sum, mav;
};

tnode tree[4096];

// left, right
tnode merge(tnode &a, tnode &b) {
    tnode ret = {0, 0, 0, 0};
    ret.sum = a.sum + b.sum;
    ret.lmav = max(a.lmav, a.sum + b.lmav);
    ret.rmav = max(b.rmav, a.rmav + b.sum);
    ret.mav = max(max(a.mav, b.mav), a.rmav + b.lmav);
    ret.mav = max(ret.mav, max(ret.lmav, ret.rmav));
    return ret;
}

int szz = 1 << 11;
void update(int i, int val) {
    i += szz;
    tree[i] = {val, val, val, val};
    i /= 2;
    while (i) {
        tree[i] = merge(tree[i * 2], tree[i * 2 + 1]);
        i /= 2;
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &red[i].first, &red[i].second);
        xx.push_back(red[i].first);
        yy.push_back(red[i].second);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &blue[i].first, &blue[i].second);
        xx.push_back(blue[i].first);
        yy.push_back(blue[i].second);
    }

    sort(all(xx));
    sort(all(yy));

    xx.erase(unique(all(xx)), xx.end());
    yy.erase(unique(all(yy)), yy.end());

    int c1, c2;
    scanf("%d %d", &c1, &c2);

    for (int i = 0; i < n; i++) {
        int t = lower_bound(all(xx), red[i].first) - xx.begin();
        int tt = lower_bound(all(yy), red[i].second) - yy.begin();
        v.push_back({t, tt, c1});
    }

    for (int i = 0; i < m; i++) {
        int t = lower_bound(all(xx), blue[i].first) - xx.begin();
        int tt = lower_bound(all(yy), blue[i].second) - yy.begin();
        v.push_back({t, tt, -c2});
    }
    sort(all(v));

    int pre = v[0].x;
    int mav = 0;
    for (node i : v) {
        if (pre != i.x) mav = max(mav, tree[1].mav);
        update(i.y, i.c);
    }
    mav = max(mav, tree[1].mav);
    printf("%d", mav);
}
