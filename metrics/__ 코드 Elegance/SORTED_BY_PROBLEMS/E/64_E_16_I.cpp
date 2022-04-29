#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> i_i;
const int INF = 1e9;
struct SegmentTree {
    int n;
    vector<int> node;
    SegmentTree() {
        int sz = 4050;
        n = 1;
        while(n < sz) n = n * 2;
        node.resize(2*n-1, -INF);
        for(int i = 0; i < sz; i++) {
            node[i+n-1] = -INF;
        }
        for(int i = n - 2; i >= 0; i--) {
            node[i] = max(node[2*i+1], node[2*i+2]);
        }
    }
    void update(int x, int val) {
        x += n - 1;
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = max(node[2*x+1], node[2*x+2]);
        }
    }
    int getmax(int a, int b, int k = 0, int l = 0, int r = -1) {
        if(r < 0) r = n;
        if(r <= a or b <= l) return -INF;
        if(a <= l && r <= b) return node[k];
        int vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmax(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }
};

int N;
SegmentTree seg[4001];
vector<int> cmp;
vector<i_i> v;

void print(int l, int r) {
    for(int i = 0; i <= N; i++) {
        cout << "-" << i << "-" << endl;
        for(int j = l; j <= r; j++) {
            cout << seg[i].getmax(j, j + 1) << " ";
        }
        cout << endl;
    }
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
        cmp.push_back(v[i].first);
        cmp.push_back(v[i].second);
    }
    cmp.push_back(-2e9);
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    //for(auto val : cmp) cerr << val << " ";
    //cerr << endl;
    for(int i = 0; i < N; i++) {
        auto itr = lower_bound(cmp.begin(), cmp.end(), v[i].first);
        v[i].first = distance(cmp.begin(), itr);
        itr = lower_bound(cmp.begin(), cmp.end(), v[i].second);
        v[i].second = distance(cmp.begin(), itr);
    }
    /*
    for(int i = 0; i < v.size(); i++) {
        v[i].second *= -1;
    }
     */
    sort(v.begin(), v.end());
    /*
    for(int i = 0; i < v.size(); i++) {
        v[i].second *= -1;
    }
     */
    for(int i = 0; i < v.size(); i++) {
        //cout << v[i].first << " " << v[i].second << endl;
    }
    seg[0].update(0, 0);
    int timer = 0;
    for(auto now : v) {
        //cout << "----" << timer << "----" << " " << now.first << " " << now.second << endl;
        timer++;
        for(int Next = N; Next >= 1; Next--) {
            int val1 = seg[Next-1].getmax(now.first, 4020);
            int val2 = seg[Next-1].getmax(0, now.first) + 1;
            int val = max(val1, val2);
            if(seg[Next].getmax(now.second, now.second + 1) < val) {
                seg[Next].update(now.second, val);
            }
            //cerr << Next << " " << seg[Next].getmax(now.second, now.second + 1) << endl;
        }
        //print(0, 9);
    }
    for(int k = 0; k < N; k++) {
        if(k != 0) cout << " ";
        cout << seg[N-k].getmax(0, 4020);
    }
    cout << endl;
    return 0;
}