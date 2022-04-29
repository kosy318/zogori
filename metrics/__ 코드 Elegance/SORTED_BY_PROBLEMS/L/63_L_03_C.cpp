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
int a[107];
LL dp[15007];
vector<PII> st[15007];
int main(){
	int m, n; scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= n; i++) {
		int l, r, c; scanf("%d %d %d", &l, &r, &c);
		st[l].pb({r, c});
	}
	for (int i = 1; i <= 15000; i++) {
		dp[i] = max(dp[i], dp[i-1]);
		for (PII x : st[i]) {
			dp[x.F] = max(dp[x.F], dp[i] + (x.F - i)*1ll*a[x.S]);
		}
	}
	printf("%lld\n", dp[15000]);
	return 0;
}

