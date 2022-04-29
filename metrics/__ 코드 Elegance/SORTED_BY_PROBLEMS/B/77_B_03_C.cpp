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

int n;
vector<pll> edge[100004];

ll dep[100004], dp0[100004], dp1[100004], dp2[100004];

ll dfs(int x, int p) {
	int cnt = 0;
	ll ret = 0;
	for (auto i : edge[x]) {
		if (i.fs == p) continue;
		++cnt;
		dep[i.fs] = dep[x] + i.se;
		ret += dfs(i.fs, x);
		dp2[i.fs] += dp0[i.fs] * i.se * i.se + dp1[i.fs] * i.se * 2;
		dp1[i.fs] += dp0[i.fs] * i.se;
		ret += dp2[i.fs] * dp0[x];
		ret += dp1[i.fs] * dp1[x] * 2;
		ret += dp0[i.fs] * dp2[x];
		dp0[x] += dp0[i.fs];
		dp1[x] += dp1[i.fs];
		dp2[x] += dp2[i.fs];
	}
	if (cnt == 0) {
		dp0[x] = 1;
	}
	debug("%d : %lld %lld %lld\n", x, dp0[x], dp1[x], dp2[x]);
	return ret;
}

int main(){
	fio;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int x, y, c;
		cin >> x >> y >> c;
		edge[x].emplace_back(y, c);
		edge[y].emplace_back(x, c);
	}
	int v = 1;
	for (int i = 1; i <= n; ++i) if (edge[i].size() != 1) v = i;
	printf("%lld\n", dfs(v, 0));
}
