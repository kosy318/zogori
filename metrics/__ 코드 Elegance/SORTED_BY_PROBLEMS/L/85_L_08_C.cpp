#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MX = 20000;

ll tree[80808];
ll query(int l, int r, int no, int nl, int nr){
    if(r <= nl || nr <= l) return -INF;
    if(l <= nl && nr <= r) return tree[no];
    int mid = (nl+nr)/2;
    return max(query(l, r, 2*no, nl, mid), query(l, r, 2*no+1, mid, nr));
}
ll query(int l, int r, int n){ return query(l, r, 1, 0, n); }
ll update(int idx, ll val, int no, int nl, int nr){
    if(idx < nl || nr <= idx) return tree[no];
    if(nl+1 == nr && nl == idx) return tree[no] = max(tree[no], val);
    int mid = (nl+nr)/2;
    return tree[no] = max(update(idx, val, 2*no, nl, mid), update(idx, val, 2*no+1, mid, nr));
}
ll update(int idx, ll val, int n){ return update(idx, val, 1, 0, n); }


ll dp[20000];

ll cost[100];
vector<pair<pair<ll,ll>, ll> > line;

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    for(int i=0; i<m; i++) scanf("%lld", &cost[i]);
    for(int i=0; i<n; i++){
        int t;
        ll lo, hi;
        ll tmp;

        scanf("%lld %lld %d", &lo, &hi, &t);
        t--;
        tmp = (hi-lo)*cost[t];
        line.push_back({{hi, lo}, tmp});
    }
    sort(line.begin(), line.end());

//    printf("debugging\n");
//    for(auto it : line) printf("%lld ~ %lld %lld\n", it.first.second, it.first.first, it.second);

    for(int i=0; i<line.size(); i++){
//        printf("now : %d\n", i);

        ll lo = line[i].first.second;
        ll hi = line[i].first.first;
        ll profit = line[i].second;
        dp[i] = query(0, lo+1, MX) + profit;
        update(hi, dp[i], MX);

//        printf("dp i %lld\n", dp[i]);
    }
    printf("%lld\n", tree[1]);
    return 0;
}
