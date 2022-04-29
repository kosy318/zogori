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


ll N;
ll pw2[100100];
ll get(ll X) {
	if ( X == 0 ) return 3;
	if ( X == 1 ) return 4;
	if ( X == 2 ) return 6;
	if ( X % 2 == 0 ) {
		X = X / 2;
		return 3LL * pw2[X];
	}
	else {
		X = (X+1) / 2;
		return 2LL * pw2[X];
	}
}


int main () {
	pw2[0] = 1;
	for (int i = 1; i <= 1000; i++) pw2[i] = pw2[i-1] * 2LL;
	scanf("%lld",&N);
	for (ll i = 3; i <= 100000; i++) {
		if ( get(i) >= N ) {
			printf("%lld\n",i);
			return 0;
		}
	}
}
