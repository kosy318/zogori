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

pll t[100005];
int n;

bool pro(ll x){
	//cout << "x = " << x << '\n';
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	set<pll> S;
	for(int i = 0; i < n; i++){
		pq.emplace(t[i].va, i);
		S.emplace(t[i].vb, i);
	}
	ll s = 0;
	for(int i = 0; i < n; i++){
		pll q = pq.top(); pq.pop();
		S.erase(pll(t[q.vb].vb, q.vb));
		ll t = max(q.va, s);
		//cout << "s = " << s << ", t = " << t << ", beg = " << S.begin() -> va << '\n';
		if(S.size() && S.begin() -> va < t + x) return false;
		s = t + x;
	}
	//cout << "ok\n";
	return true;
}
int main(){
	fio;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> t[i].va >> t[i].vb;
		t[i].vb += t[i].va;
	}
	sort(t,t+n);
	ll lo = 0, mi, hi = 2e9;
	while(lo < hi){
		mi = (lo + hi + 1) >> 1;
		if(pro(mi)) lo = mi;
		else hi = mi - 1;
	}
	cout << lo << '\n';
}
