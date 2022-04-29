#include <bits/stdc++.h>

#define rep(i, e) for (int i = 0, _##i = (e); i < _##i; i++)
#define repp(i, s, e) for (int i = (s), _##i = (e); i < _##i; i++)

using namespace std;

using ll = long long;
using pii = pair<int, int>;

#ifdef ONLINE_JUDGE
#define debug(...) 0
#define endl '\n'
#else
#define debug(...) cout << " [-] ", _dbg(#__VA_ARGS__, __VA_ARGS__)
template<class TH> void _dbg(const char *sdbg, TH h) {cout << sdbg << '=' << h << endl;}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
	while(*sdbg != ',') cout << *sdbg++;
	cout << '=' << (h) << ',';
	_dbg(sdbg+1, a...);
}
#endif

using namespace std;

struct Block {
	int cnt;
	ll dep1;
	ll dep2;
};

int N;
ll res;
vector<pair<int, int>> adj[100001];

Block dp(int p, int c) {
	Block ret = {0, 0, 0};
	if (adj[c].size() == 1) ret.cnt = 1;
	
	for (auto &t : adj[c]) if (t.first != p) {
		Block x = dp(c, t.first);
		x.dep2 += (ll)t.second*t.second*x.cnt;
		x.dep2 += (ll)2*x.dep1*t.second;
		x.dep1 += (ll)x.cnt*t.second;
		
		res += 2*ret.dep1*x.dep1;
		res += ret.dep2*x.cnt;
		res += ret.cnt *x.dep2;
		
		ret.cnt  += x.cnt;
		ret.dep1 += x.dep1;
		ret.dep2 += x.dep2;
	}
	
	
	return ret;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N;
	rep(i, N-1) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}
	
	dp(0, 1);
	cout << res << '\n';
}







