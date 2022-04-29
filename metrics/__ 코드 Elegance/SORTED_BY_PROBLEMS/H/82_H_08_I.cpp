#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 123;

struct Node {
    int max_prefix;
    int max_suffix;
    int sum;
    int max_sum;
    Node() {
        max_prefix = max_suffix = max_sum = sum = 0;
    }
};

Node t[4 * N];

Node combine(Node a, Node b) {
    Node res;
    res.max_prefix = max(a.max_prefix, a.sum + b.max_prefix);
    res.max_suffix = max(b.max_suffix, b.sum + a.max_suffix);
    res.sum = a.sum + b.sum;

    res.max_sum = max(a.max_sum, b.max_sum);
    res.max_sum = max(res.max_sum, a.max_suffix + b.max_prefix);
    return res;
}

void build(int v = 1, int tl = 1, int tr = 2000) {
    if (tl == tr) {
        t[v] = Node();
    } else {
        int mid = (tl + tr) / 2;
        build(v + v, tl, mid);
        build(v + v + 1, mid + 1, tr);
        t[v] = Node();
    }
}

void add(int pos, int val, int v = 1, int tl = 1, int tr = 2000) {
    if (tl == tr) {
        t[v].sum += val;
        t[v].max_prefix = max(0, t[v].sum);
        t[v].max_suffix = max(0, t[v].sum);
        t[v].max_sum = max(0, t[v].sum);
    } else {
        int mid = (tl + tr) / 2;
        if (pos <= mid) add(pos, val, v + v, tl, mid);
        else add(pos, val, v + v + 1, mid + 1, tr);
        t[v] = combine(t[v + v], t[v + v + 1]);
    }
}

struct Point {
    int x, y;
};

int n, m;
int c1, c2;
Point a[N];
Point b[N];
vector<pair<int, int>> with_x[N];

int main() {
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    #endif // LOCAL


    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> xs, ys;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
        xs.push_back(a[i].x);
        ys.push_back(a[i].y);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i].x >> b[i].y;
        xs.push_back(b[i].x);
        ys.push_back(b[i].y);
    }

    cin >> c1 >> c2;

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    for (int i = 1; i <= n; i++) {
        a[i].x = upper_bound(xs.begin(), xs.end(), a[i].x) - xs.begin();
        a[i].y = upper_bound(ys.begin(), ys.end(), a[i].y) - ys.begin();
        with_x[a[i].x].push_back(make_pair(a[i].y, c1));
    }
    for (int i = 1; i <= m; i++) {
        b[i].x = upper_bound(xs.begin(), xs.end(), b[i].x) - xs.begin();
        b[i].y = upper_bound(ys.begin(), ys.end(), b[i].y) - ys.begin();
        with_x[b[i].x].push_back(make_pair(b[i].y, -c2));
    }

    int ans = 0;
    for (int upper_x = 1; upper_x <= 2000; upper_x++) {
        build();
        for (int lower_x = 1; lower_x <= 2000; lower_x++) {
            for (auto it : with_x[lower_x]) {
                //cout << "adding " << it.first << ' ' << it.second << endl;
                add(it.first, it.second);
            }
            ans = max(ans, t[1].max_sum);
        }
    }
    cout << ans;
    return 0;
}
