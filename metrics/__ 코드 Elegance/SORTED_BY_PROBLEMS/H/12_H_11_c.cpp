#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Pt {
    int x, y;
    bool color;
    bool operator<(const Pt &o) const {
        return x < o.x;
    }
};

struct Seg {
    struct Node {
        Node() {
            premx = 0;
            sufmx = 0;
            submx = 0;
            sum = 0;
        }
        int premx;
        int sufmx;
        int submx;
        int sum;
    };

    int p2;
    int n;
    vector<Node> nodes;

    Seg(int n) : n(n) {
        p2 = 1;
        while(p2 < n) p2 *= 2;
        nodes.resize(2*p2);
    }

    void update(int x, int v) {
        x += p2 - 1;
        nodes[x].premx += v;
        nodes[x].sufmx += v;
        nodes[x].submx += v;
        nodes[x].sum += v;
        x /= 2;

        while(x) {
            nodes[x].premx = max(nodes[2*x].premx, nodes[2*x].sum + nodes[2*x+1].premx);
            nodes[x].sufmx = max(nodes[2*x+1].sufmx, nodes[2*x+1].sum + nodes[2*x].sufmx);
            nodes[x].submx = max({nodes[2*x].submx, nodes[2*x+1].submx, nodes[2*x].sufmx + nodes[2*x+1].premx});
            nodes[x].sum += v;
            x /= 2;
        }
    }
};

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif // LOCAL

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<Pt> pts;
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        int x, y; cin >> x >> y;
        pts.push_back({x, y, 0});
    }

    int m; cin >> m;
    for(int i=0; i<m; i++) {
        int x, y; cin >> x >> y;
        pts.push_back({x, y, 1});
    }

    int a, b; cin >> a >> b;

    sort(pts.begin(), pts.end());

    vector<int> ys;
    for(Pt &p : pts) ys.push_back(p.y);
    sort(ys.begin(), ys.end());

    n = pts.size();
    int res = 0;
    for(int i=0; i<n; i++) {
        Seg T(n+10);
        for(int j=i; j<n; j++) {
            int k = lower_bound(ys.begin(), ys.end(), pts[j].y)-ys.begin()+1;
            T.update(k, pts[j].color == 0 ? a : -b);
            res = max(res, T.nodes[1].submx);
        }
    }

    cout << res << endl;

    return 0;
}
