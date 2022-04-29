#include <bits/stdc++.h>
#define fs first
#define se second
#define va first
#define vb second
#define y0 qweriuot
#define y1 asdfjklhaks
#define fio ios_base::sync_with_stdio(0);cin.tie(0);
#define lb lower_bound
#define ub upper_bound
#define pp push_back
#define ep emplace_back

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
using ll = long long; using llong = long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<ld,ld>;

int m, n;
ll V[105];
vector<pll> L[15005];
ll dp[15005];
int main(){
	fio;
	cin >> m >> n;
	for (int i = 1; i <= m; ++i) cin >> V[i];
	for (int i = 1; i <= n; ++i) {
		int s, e, v;
		cin >> s >> e >> v;
		L[s].emplace_back(e, V[v] * (e - s));
	}
	ll ans = 0;
	for (int i = 1; i < 15003; ++i) {
		dp[i] = max(dp[i], dp[i - 1]);
		ans = max(ans, dp[i]);
		for (auto j : L[i]) {
			dp[j.fs] = max(dp[j.fs], dp[i] + j.se);
		}
	}
	printf("%lld\n", ans);
}
