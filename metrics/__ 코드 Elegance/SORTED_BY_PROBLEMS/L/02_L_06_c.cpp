#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int) x.size()
#define rep(i, n) for(int i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define all(x) x.begin(), x.end()

int N,M;

struct ore{
	ll s, e, p;
} ;

ll price[500500];
ll dp[50050];
ll S[500500];
vector<ore> v[50050];

int main () {
	scanf("%d%d",&M, &N);
	repp(i,M){
		scanf("%lld",&price[i]);
	}
	repp(i,N){
		int S,E,T;
		scanf("%d%d%d",&S,&E,&T);
		v[E].push_back({S,E,price[T]});
	}
	ll ans = 0;
	for (int i = 1; i <= 20020; i++) {
		for (auto e : v[i]){
			dp[i] = max(dp[i], S[e.s] + (e.p) * (e.e - e.s));
		}
		ans = max(ans, dp[i]);
		S[i] = max(dp[i], S[i-1]);
		//printf("%d %lld\n", i, dp[i]);
	}

	printf("%lld\n",ans);

}
