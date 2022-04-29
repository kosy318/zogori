// H

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;
#define pb push_back

constexpr int MAXN = 2004;

static int N;
static int bs, cs;
static tuple<int,int,bool> dat[MAXN];

static vector<int> Xs;
static vector<int> Ys;

struct Segnode {
    int sum;
    int left, right;
    int ms;
};

class Segtree {
    vector<Segnode> v;

public:
    Segtree() : v(4096) {}

    void clear() {
        for (int i = 0; i < v.size(); ++i) {
            v[i].sum = v[i].left = v[i].right = v[i].ms = 0;
        }
    }

    void insert(int wh, int k) {
        wh += 2048;
        v[wh].sum += k;
        v[wh].left = v[wh].right = v[wh].ms = max(0, v[wh].sum);

        while (wh > 1) {
            wh /= 2;
            v[wh].left = max(v[wh*2].left, v[wh*2].sum+v[wh*2+1].left);
            v[wh].right = max(v[wh*2+1].right, v[wh*2+1].sum+v[wh*2].right);
            v[wh].ms = max({v[wh*2].ms, v[wh*2+1].ms, v[wh*2].right+v[wh*2+1].left});
            v[wh].sum = v[wh*2].sum + v[wh*2+1].sum;
        }
    }

    int getmax() const { return v[1].ms; }
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n1, n2;
    cin >> n1;
    for (int i = 0; i < n1; ++i) {
        int x, y;
        cin >> x >> y;
        dat[i] = {x, y, true};
    }

    cin >> n2;
    for (int i = 0; i < n2; ++i) {
        int x, y;
        cin >> x >> y;
        dat[i+n1] = {x, y, false};
    }

    cin >> bs >> cs;
    N = n1 + n2;

    // process
    sort(dat, dat + N);
    Xs.reserve(N);
    Ys.reserve(N);

    for (int i = 0; i < N; ++i) {
        int x, y;
        tie(x, y, ignore) = dat[i];
        Xs.push_back(x);
        Ys.push_back(y);
    }

    sort(Xs.begin(), Xs.end());
    Xs.resize(unique(Xs.begin(), Xs.end()) - Xs.begin());
    sort(Ys.begin(), Ys.end());
    Ys.resize(unique(Ys.begin(), Ys.end()) - Ys.begin());

    for (int i = 0; i < N; ++i) {
        int x, y;
        bool p;
        tie(x, y, p) = dat[i];
        x = int(lower_bound(Xs.begin(), Xs.end(), x) - Xs.begin());
        y = int(lower_bound(Ys.begin(), Ys.end(), y) - Ys.begin());
        dat[i] = {x, y, p};
    }

    int ans = 0;
    Segtree seg;

    for (int i = 0; i < N; ++i) {
        if (i > 0 && get<0>(dat[i]) == get<0>(dat[i-1])) continue;
        seg.clear();
        for (int j = i; j < N; ++j) {
            int x;
            bool y;
            tie(ignore, x, y) = dat[j];

            const int k = (y ? bs : -cs);
            seg.insert(x, k);

            if (j != N-1 && get<0>(dat[j]) == get<0>(dat[j+1])) continue;
            const int m = seg.getmax();
            ans = max(ans, m);
        }
    }

    cout << ans << "\n";
}
