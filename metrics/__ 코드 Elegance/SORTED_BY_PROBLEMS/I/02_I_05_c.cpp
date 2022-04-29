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

pll in[100001];
int n;

bool chk(ll d) {
	ll x = in[0].Fi;
	for(int i=1; i<n; i++) {
		x += d;
		if(x < in[i].Fi) x = in[i].Fi;
		if(x > in[i].Fi + in[i].Se) return false;
	}
	return true;
}

int main () {
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%lld%lld", &in[i].Fi, &in[i].Se);
	}
	sort(in, in+n);
	ll f = 0, r = 20000000010ll, m;
	while(f<r) {
		m = (f+r+1)/2;
		if(chk(m)) f = m;
		else r = m-1;
	}
	printf("%lld\n", f);
	return 0;
}
