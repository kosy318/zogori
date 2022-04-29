#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ALL(X) (X).begin(), (X).end()
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define pb push_back
typedef long long LL;
typedef double DB;
typedef long double LDB;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
const int MXN = (int)1e5 + 7;
PII a[MXN], b[MXN];
vector<int> segx, segy;
vector<PII> stx[MXN];
int ll[MXN], rr[MXN];
int lv[MXN], rv[MXN];
int val[MXN], sum[MXN];
#define ls p<<1
#define rs p<<1|1
void bd(int l, int r, int p) {
	ll[p] = l, rr[p] = r;
	lv[p] = rv[p] = val[p] = sum[p] = 0;
	if (l == r) {
		return ;
	}
	int mid = (l + r) >> 1;
	bd(l, mid, ls);
	bd(mid+1, r, rs);
}
void merge(int p) {
	lv[p] = max(lv[ls], lv[rs] + sum[ls]);
	rv[p] = max(rv[rs], rv[ls] + sum[rs]);
	sum[p] = sum[ls] + sum[rs];
	val[p] = max(val[ls], val[rs]);
	val[p] = max(val[p], rv[ls] + lv[rs]);
	val[p] = max(val[p], max(lv[p], rv[p]));
	return ;
}
void md(int pp, int v, int p) {
	if (ll[p] == rr[p]) {
		sum[p] += v;
		lv[p] = max(0, sum[p]);
		rv[p] = max(0, sum[p]);
		val[p] = max(0, sum[p]);
		return ;
	}
	int mid = (ll[p] + rr[p]) >> 1;
	if (pp <= mid) md(pp, v, ls);
	else md(pp, v, rs);
	merge(p);
}
int main(){
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &a[i].F, &a[i].S);
		segx.pb(a[i].F);
		segy.pb(a[i].S);
	}
	int m; scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &b[i].F, &b[i].S);
		segx.pb(b[i].S);
		segy.pb(b[i].S);
	}
	sort(ALL(segx)); segx.resize(unique(ALL(segx)) - segx.begin());
	sort(ALL(segy)); segy.resize(unique(ALL(segy)) - segy.begin());
	int v1, v2; scanf("%d %d", &v1, &v2);
	for (int i = 1; i <= n; i++) {
		int x = lower_bound(ALL(segx), a[i].F) - segx.begin();
		int y = lower_bound(ALL(segy), a[i].S) - segy.begin();
		stx[x].pb({y, v1});
	}
	for (int i = 1; i <= m; i++) {
		int x = lower_bound(ALL(segx), b[i].F) - segx.begin();
		int y = lower_bound(ALL(segy), b[i].S) - segy.begin();
		stx[x].pb({y, -v2});
	}
	int k = SZ(segx);
	int ans = 0;
	for (int i = 0; i < k; i++) {
		int k2 = SZ(segy) - 1;
		bd(0, k2, 1);
		for (int j = i; j < k; j++) {
			for (PII x : stx[j]) 
				md(x.F, x.S, 1);
			ans = max(ans, val[1]);
		}
	}
	printf("%d\n", ans);
	return 0;
}

