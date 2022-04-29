#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

const int N = 2005, L = 2048, inf = 1e9+7;

int n, n1, n2, c1, c2, ans;

int x[N], y[N], c[N];

vector<int> xcp, ycp;
vector<pii> v[N];

void compress (vector<int> &V) {
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
}

int getcp (vector<int> &V, int P) {
    return lower_bound(V.begin(), V.end(), P) - V.begin();
}

struct Val {
    int pf, sf, sm, op;
};

Val Merge (Val &A, Val &B) {
    Val R;
    R.pf = max(A.pf, A.sm + B.pf);
    R.sf = max(B.sf, B.sm + A.sf);
    R.sm = A.sm + B.sm;
    R.op = max({A.op, B.op, A.sf + B.pf});
    return R;
}

struct Seg{
    Val v[2*L];
    void init () {
        for(int i=2*L;--i;) {
            v[i] = {0, 0, 0, 0};
        }
    }
    void upd (int P, int V) {
        P += L;
        v[P].sm += V;
        V = max(0, v[P].sm);
        v[P].pf = v[P].sf = v[P].op = V;
        P /= 2;
        while(P) {
            v[P] = Merge(v[2*P], v[2*P+1]);
            P /= 2;
        }
    }
} seg;

int main()
{
    scanf("%d",&n1);
    for(int i=1;i<=n1;i++) {
        scanf("%d%d",&x[i],&y[i]);
        xcp.push_back(x[i]);
        ycp.push_back(y[i]);
    }
    scanf("%d",&n2);
    for(int i=n1+1;i<=n1+n2;i++) {
        scanf("%d%d",&x[i],&y[i]);
        xcp.push_back(x[i]);
        ycp.push_back(y[i]);
    }
    n = n1 + n2;
    compress(xcp);
    compress(ycp);
    scanf("%d%d",&c1,&c2);
    for(int i=1;i<=n1+n2;i++) {
        x[i] = getcp(xcp, x[i]);
        y[i] = getcp(ycp, y[i]);
        c[i] = (i <= n1 ? c1 : -c2);
        v[y[i]].push_back({x[i], c[i]});
    }
    for(int i=0;i<ycp.size();i++) {
        seg.init();
        for(int j=i;j<ycp.size();j++) {
            for(auto &T : v[j]) {
                int A, B;
                tie(A, B) = T;
                seg.upd(A, B);
            }
            ans = max(ans, seg.v[1].op);
        }
    }
    printf("%d\n", ans);
}
