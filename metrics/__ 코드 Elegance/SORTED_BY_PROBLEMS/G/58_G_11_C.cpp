#include <bits/stdc++.h>
const int INF = 2000000000;
using namespace std;

struct data{
    int x, c, idx;
    bool operator<(const data &d1) const{
        return x < d1.x;
    }
};
int m, n, cnt, res;
int tree[400010], dp[100010];
data arr[100010];
deque <data> dq[100010];

void update(int a, int nl, int nr, int l, int r, int v){
    int mid = (nl + nr) / 2;
    if(nr < l || r < nl) return;
    if(l <= nl && nr <= r){ tree[a] = v; return; }
    update(a * 2, nl, mid, l, r, v);
    update(a * 2 + 1, mid + 1, nr, l, r, v);
    tree[a] = min(tree[a * 2], tree[a * 2 + 1]);
}
int f(int a, int nl, int nr, int l, int r){
    int mid = (nl + nr) / 2;
    if(nl > nr) return INF;
    if(l <= nl && nr <= r) return tree[a];
    if(nr < l || r < nl) return INF;
    return min(f(a * 2, nl, mid, l, r), f(a * 2 + 1, mid + 1, nr, l, r));
}
int lowb(int a, int s){
    int l = 0, r = dq[a].size() - 1, mid, now = n + 1;
    while(l <= r){
        mid = (l + r) / 2;
        if(dq[a][mid].x < s) l = mid + 1;
        else r = mid - 1, now = min(now, mid);
    }
    if(now == n + 1) now = n + 1;
    else now = dq[a][now].idx;
    return now;
}
int upb(int a, int s){
    int l = 0, r = dq[a].size() - 1, mid, now = -1;
    while(l <= r){
        mid = (l + r) / 2;
        if(dq[a][mid].x > s) r = mid - 1;
        else l = mid + 1, now = max(now, mid);
    }
    if(now != -1) now = dq[a][now].idx;
    return now;
}
int main(){
    int i, j, now, nl, nr, na, ns;
    data a;
    scanf("%d %d", &m, &n);
    for(i = 0; i < n; i++) scanf("%d", &arr[i].x);
    for(i = 0; i < n; i++) scanf("%d", &arr[i].c);
    sort(arr, arr + n);
    for(i = 0; i < n; i++) arr[i].idx = i;
    dq[0].push_back(arr[0]);
    for(i = 0; i <= 4 * n + 4; i++) tree[i] = INF;
    for(i = 1; i < n; i++){
        if(arr[i].c != arr[i - 1].c) cnt++;
        dq[cnt].push_back(arr[i]);
    }
    for(i = 0; i < dq[0].size(); i++){
        a = dq[0][i];
        dp[a.idx] = 1;
        update(1, 0, n, a.idx, a.idx, 1);
    }
    for(i = 1; i <= cnt; i++){
        for(j = 0; j < dq[i].size(); j++){
            a = dq[i][j];
            now = INF;
            if(j != 0) now = f(1, 0, n, dq[i][0].idx, a.idx - 1);
            na = 2 * dq[i - 1].back().x;
            ns = 2 * dq[i].front().x;
            na -= a.x; ns -= a.x;
            nl = lowb(i - 1, na);
            nr = upb(i - 1, ns);
            now = min(now, f(1, 0, n, nl, nr));
            update(1, 0, n, a.idx, a.idx, now + 1);
            dp[a.idx] = now + 1;
        }
    }
    res = INF;
    for(i = 0; i < dq[cnt].size(); i++){
        res = min(res, dp[dq[cnt][i].idx]);
    }
    printf("%d", res);
    return 0;
}


/*
2 6
0 3 4 7 8 11
1 1 1 2 2 1

*/







