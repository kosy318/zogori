#include<bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> t3;
typedef long long ll;
int m, n, A[110];
t3 L[10010];
ll dp[10010];

int main(){
	scanf("%d%d", &m, &n);
	for(int i=1;i<=m;i++) scanf("%d", A + i);
	for(int i=1;i<=n;i++) {
		int s, e, x;
		scanf("%d%d%d", &s, &e, &x);
		x = A[x] * (e - s);
		L[i] = t3(e, s, x);
	}
	sort(L+1, L+1+n);
	ll ans = 0;
	for(int i=1;i<=n;i++) {
		int e, s, x;
		tie(e, s, x) = L[i];
		for(int j=1;j<i;j++) {
			int e2 = get<0>(L[j]);
			if(e2 <= s) dp[i] = max(dp[i], dp[j]);
		}
		dp[i] += x;
		ans = max(ans, dp[i]);
	}
	printf("%lld\n", ans);
	return 0;
}