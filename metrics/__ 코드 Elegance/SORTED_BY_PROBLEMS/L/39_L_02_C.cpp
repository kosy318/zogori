#include <bits/stdc++.h>
using namespace std;
#define rrep(i,n) for(int i=1; i<=n; ++i)

int n, m;

int price[200];

using t3=tuple<int,int,int>;
t3 occ[10001];

long long dp[20001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	rrep(i, m) cin >> price[i];

	rrep(i, n) {
		int s, t, x;
		cin >>s >>t>>x;
		occ[i] = {t, s, x};
	}

	sort(occ+1, occ+n+1);
	int idx = 0;

	for(int t=1; t<=15000; ++t) {
		dp[t] = dp[t-1];
		while(idx<n && get<0>(occ[idx+1]) == t) {
			int s, x; tie(ignore, s, x) = occ[++idx];
			dp[t] = max(dp[t], dp[s]+price[x]*1ll*(t-s));
		}
	}

	cout << dp[15000] << endl;

	return 0;
}
