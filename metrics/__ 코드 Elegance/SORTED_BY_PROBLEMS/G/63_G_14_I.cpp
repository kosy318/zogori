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
const int MXN = (int)1e6 + 7;
int a[MXN], b[MXN];
int ll[MXN], rr[MXN], val[MXN];
#define ls p<<1
#define rs p<<1|1
int n;
void bd(int l, int r, int p) {
	ll[p] = l, rr[p] = r, val[p] = n;
	if (l == r) return ;
	int mid = (l + r) >> 1;
	bd(l, mid, ls); bd(mid+1, r, rs);
}
int qy(int l, int r, int p) {
	if (l > rr[p] || ll[p] > r) return n;
	if (l <= ll[p] && rr[p] <= r) return val[p];
	return min(qy(l, r, ls), qy(l, r, rs));
}
void md(int pp, int v, int p) {
	if (ll[p] == rr[p]) {
		val[p] = v;
		return ;
	}
	int mid = (ll[p] + rr[p]) >> 1;
	if (pp <= mid) md(pp, v, ls);
	else md(pp, v, rs);
	val[p] = min(val[ls], val[rs]);
}
int lb[MXN], rb[MXN];
int dp[MXN];
int main(){
	int m; scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		dp[i] = n;
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", b + i);
	int cntp = 0;
	bd(1, n, 1);
	for (int i = 1; i <= n; i++) {
		cntp++;
		int r = i;
		while (r + 1 <= n && b[r + 1] == b[i]) r++;
		lb[cntp] = i, rb[cntp] = r;

		for (int j = i; j <= r; j++) {
			if (cntp == 1) dp[j] = 1;
			else {
				dp[j] = min(dp[j], qy(i, j-1, 1) + 1);
				int dis = a[j] - a[i];
				int lt = lb[cntp-1], rt = rb[cntp-1], ok = -1;
				while (lt <= rt) {
					int mid = (lt + rt) >> 1;
					if (a[i] - a[mid] < dis) {
						rt = mid - 1;
					} else {
						lt = mid + 1;
						ok = mid;
					}
				}
				if (ok != -1) {
					dp[j] = min(dp[j], qy(lb[cntp-1], ok, 1) + 1);
				}
			}
			md(j, dp[j], 1);
		}
		i = r;
	}
	printf("%d\n", dp[n]);
	return 0;
}

