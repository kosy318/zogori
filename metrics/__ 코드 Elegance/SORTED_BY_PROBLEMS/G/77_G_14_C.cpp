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

int n, m;
ll P[100005];
ll C[100005];
ll D[100005];
ll F[100005];
vector<ll> dp[100005];
int main(){
	fio;
	cin >> m >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> P[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> C[i];
		if (C[i - 1] != C[i]) F[i] = 1;
		F[i] += F[i - 1];
	}
	D[0] = 1;
	for (int i = 1; i <= n; ++i) {
		if (C[i] != C[1]) {
			D[i] = -1;
			dp[i].push_back(~1);
			break;
		}
	}
	multiset<ll> sp;
	sp.insert(1);
	ll ans = 1e9;
	for (int i = 1; i <= n; ++i) {
		D[i] += D[i - 1];
		for (ll j : dp[i]) {
			if (j < 0) sp.erase(sp.find(~j));
			else sp.insert(j);
		}
		if (!D[i]) continue;
		ll val = *sp.begin();
		int L = i + 1, R = n + 1;
		int p1 = lower_bound(F, F + n + 1, F[i] + 1) - F - 1;
		int p2 = lower_bound(F, F + n + 1, F[i] + 2) - F - 1;
		if (p1 < n) {
			L = max(L, int(lower_bound(P + 1, P + n + 1, P[p1] + (P[p1] - P[i])) - P));
			R = min(R, int(lower_bound(P + 1, P + n + 1, P[p1 + 1] + (P[p1 + 1] - P[i]) + 1) - P));
			R = min(R, p2 + 1);
			if (L <= R) {
				++D[L], --D[R];
				dp[L].push_back(val + 1);
				dp[R].push_back(~(val + 1));
			}
		}
		else ans = min(ans, val);
		++D[i + 1];
		--D[p1 + 1];
		dp[i + 1].push_back(val + 1);
		dp[p1 + 1].push_back(~(val + 1));
	}
	printf("%lld\n", ans);
	return 0;
}
