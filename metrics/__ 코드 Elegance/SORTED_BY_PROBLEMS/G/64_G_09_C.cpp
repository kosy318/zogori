#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int M, N;
int x[100500];
int color[100050];
int LastSame[100050];
ll dp[100050];
ll ans = 1e8;

const int INF = 1e9;

struct SegmentTree {
    int n;
    vector<int> node;
    SegmentTree() {
        int sz = 100050;
        n = 1;
        while(n < sz) n = n * 2;
        node.resize(2*n-1, INF);
        for(int i = 0; i < sz; i++) {
            node[i+n-1] = INF;
        }
        for(int i = n - 2; i >= 0; i--) {
            node[i] = min(node[2*i+1], node[2*i+2]);
        }
    }
    void update(int x, int val) {
        x += n - 1;
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = min(node[2*x+1], node[2*x+2]);
        }
    }
    int getmin(int a, int b, int k = 0, int l = 0, int r = -1) {
        if(r < 0) r = n;
        if(r <= a or b <= l) return INF;
        if(a <= l && r <= b) return node[k];
        int vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};

bool chmin(ll &a, ll b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

SegmentTree seg;

ll MyMin(ll l, ll r) {
    return seg.getmin(l, r);
}

int DeterminLeft(int index) {
    int ok = LastSame[index] - 1;
    int ng = LastSame[ok] - 1;
    int border = ok;
    while(ok - ng > 1) {
        int mid = (ok + ng) / 2;
        if(abs(x[index] - x[border]) >= abs(x[mid] - x[border])) ok = mid;
        else ng = mid;
    }
    return ok;
}

int DeterminRight(int index) {
    int ng = LastSame[index];
    int ok = LastSame[LastSame[index] - 1] - 1;
    int border = LastSame[index];
    while(ng - ok > 1) {
        int mid = (ok + ng) / 2;
        if(abs(x[border] - x[index]) <= abs(x[mid] - x[border])) ok = mid;
        else ng = mid;
    }
    if(ok == LastSame[LastSame[index] - 1] - 1) {
        ok = -1;
    }
    return ok;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin >> M >> N;
    for(int i = 0; i < N; i++) {
        cin >> x[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> color[i];
        if(i == 0 or color[i] != color[i-1]) {
            LastSame[i] = i;
        } else {
            LastSame[i] = LastSame[i-1];
        }
    }
    for(int i = 0; i < N; i++) {
        if (LastSame[i] == 0) {
            dp[i] = 1;
            seg.update(i, 1);
            continue;
        }
        dp[i] = MyMin(LastSame[i], i) + 1;
        int l = DeterminLeft(i);
        int r = DeterminRight(i);
        if (r != -1) chmin(dp[i], MyMin(l, r + 1) + 1);
        seg.update(i, dp[i]);
        //cout << " " << i << " " << l << " " << r << " " << dp[i] << endl;
    }
    for(int i = LastSame[N-1]; i < N; i++) {
        chmin(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}