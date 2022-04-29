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

struct segTree{
	int n;
	vector<ll> v;
	void init (int x) {
		n = 1;
		while ( n < x ) n *= 2;
		v.resize(n * 2 + 10);
		for(auto &e : v) e = 1e18;
	}
	void update(int l, int r, ll val){
		for (l += n-1, r += n-1; l <=r; l>>=1, r>>=1) {
			if ( l&1 ) {
				v[l] = min(v[l], val);
				l++;
			}
			if ( !(r&1) ){
				v[r] = min(v[r], val);
				r--;
			}
		}
	}
	ll query (int p) {
		p += n-1;
		ll res = 1e18;
		while( p > 0 ) {
			res = min(res, v[p]);
			p >>= 1;
		}
		return res;
	}
};


int M, N;
ll x[500500];
int c[500500];
int s[500500], e[500500];
vector<ll> idx;
segTree dp;
int main () {

	scanf("%d%d",&M, &N);
	repp (i, N) scanf("%lld", &x[i]);
	repp (i, N) scanf("%d", &c[i]);
	dp.init(N);
	idx.push_back(-1e18);
	repp(i,N) idx.push_back(x[i]);
	repp(i,N) s[i] = e[i] = i;
	for (int i = 2; i <= N; i++) {
		if ( c[i] == c[i-1] ) s[i] = s[i-1];
	}
	for (int i = N-1; i >= 1; i-- ) {
		if ( c[i] == c[i+1] ) e[i] = e[i+1];
	}
	dp.update(1, e[1], 1);
	for (int i = 1; i <= N; i++) {
		ll val = dp.query(i);
		dp.update(i+1, e[i], val+1);

		if ( e[i] == N ) continue;
		
		ll X = x[i];
		int l = lower_bound(all(idx), 2 * x[e[i]] - x[i]) - idx.begin();
		int r = upper_bound(all(idx), 2 * x[e[i]+1] - x[i]) - idx.begin();
		r = r - 1;
		l = max(l, e[i]+1);
		r = min(r, e[e[i]+1]);
		//printf("%d [%d,%d]\n", i, l, r);
		dp.update(l, r, val+1);
	}

	ll ans = 1e18;

	for (int i = s[N]; i <= N; i++) ans = min(ans, dp.query(i));
	printf("%lld\n",ans);
}
