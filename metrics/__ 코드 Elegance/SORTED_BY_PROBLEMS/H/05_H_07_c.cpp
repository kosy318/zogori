#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define xx first
#define yy second
#define ft first
#define sd second

const int MAX = 2222;
struct node{
    int all_sum, m_asum, m_lsum, m_rsum;
    node(){
        all_sum = m_asum = m_lsum = m_rsum = 0;
    }
};
struct segtree{
    node seg[MAX*4];
    void init(){
        fill(seg, seg+MAX*4, node());
    }
    node merge(node a, node b){
        node ret;
        ret.all_sum = a.all_sum + b.all_sum;
        ret.m_lsum = max(a.m_lsum, a.all_sum + b.m_lsum);
        ret.m_rsum = max(b.m_rsum, a.m_rsum + b.all_sum);
        ret.m_asum = max({a.m_asum, b.m_asum, a.m_rsum + b.m_lsum});
        return ret;
    }
    node query(int l, int r, int no, int nodeL, int nodeR){
        if(r < nodeL || nodeR < l) return node();
        if(l <= nodeL && nodeR <= r) return seg[no];
        int mid = (nodeL + nodeR)/2;
        return merge(query(l, r, no*2, nodeL, mid), query(l, r, no*2+1, mid+1, nodeR));
    }
    int query(int l, int r){
        return query(l, r, 1, 0, MAX-1).m_asum;
    }
    node update(int idx, int value, int no, int nodeL, int nodeR){
        if(idx < nodeL || nodeR < idx) return seg[no];
        if(nodeL == nodeR) {
            seg[no].all_sum += value;
            seg[no].m_asum = seg[no].m_lsum = seg[no].m_rsum = max(seg[no].all_sum , 0);
            return seg[no];
        }
        int mid = (nodeL+nodeR)/2;
        return seg[no] = merge(update(idx, value, no*2, nodeL, mid),update(idx, value, no*2+1, mid+1, nodeR));
    }
    void update(int idx, int value){
        update(idx, value, 1, 0, MAX-1);
    }
} S;

int n1, n2, c1, c2;
vector<pii> o_G1, o_G2;
vector<int> xzip, yzip;
vector<int> G1[MAX], G2[MAX];


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input1.txt", "r", stdin);
    //input
    cin >> n1;
    for(int i=0; i<n1; ++i){
        int x, y;
        cin >> x >> y;
        xzip.push_back(x);
        yzip.push_back(y);
        o_G1.push_back({x,y});
    }
    cin >> n2;
    for(int i=0; i<n2; ++i){
        int x, y;
        cin >> x >> y;
        xzip.push_back(x);
        yzip.push_back(y);
        o_G2.push_back({x,y});
    }
    cin >> c1 >> c2;

    //zip
    sort(xzip.begin(), xzip.end());
    xzip.erase(unique(xzip.begin(), xzip.end()), xzip.end());

    sort(yzip.begin(), yzip.end());
    yzip.erase(unique(yzip.begin(), yzip.end()), yzip.end());

    for(auto &p : o_G1){
        p.xx = lower_bound(xzip.begin(), xzip.end(), p.xx) - xzip.begin();
        p.yy = lower_bound(yzip.begin(), yzip.end(), p.yy) - yzip.begin();
        G1[p.xx].push_back(p.yy);
    }
    for(auto &p : o_G2){
        p.xx = lower_bound(xzip.begin(), xzip.end(), p.xx) - xzip.begin();
        p.yy = lower_bound(yzip.begin(), yzip.end(), p.yy) - yzip.begin();
        G2[p.xx].push_back(p.yy);
    }

    int ans = 0;
    //query
    int xs = xzip.size();
    int ys = yzip.size();

    for(int i=0; i<xs; ++i){
        S.init();
        for(int j=i; j<xs; ++j){
            //update x = j
            for(auto &p : G1[j])
                S.update(p, c1);
            for(auto &p : G2[j])
                S.update(p, -c2);
            /*
            for(int k=0; k<ys; ++k)
                cout << S.query(k, k) << ' ';
            cout << endl;
            cout << i << ' ' << j << ": " << S.query(0, MAX-1) << endl;
            */
            ans = max(ans, S.query(0, MAX-1));
        }
    }
    cout << ans;

}
