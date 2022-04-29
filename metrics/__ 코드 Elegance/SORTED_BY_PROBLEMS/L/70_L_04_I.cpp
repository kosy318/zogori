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

typedef pair<ll, ll> pll;
typedef pair<ll, ll> pll;

int M, N;
ll A[110];

struct X{
	ll s, e, val;
};

bool operator < (X x, X y){
	return x.e < y.e;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> M >> N;
	for(int i = 1 ; i <= M ; i++) cin >> A[i];		
	
	vector<X> V;
	for(int i = 0 ; i < N ; i++){
		ll a, b, c;
		cin >> a >> b >> c;
		c = A[c] * (b - a);
		V.push_back((X){a, b, c});
	}
	
	map<ll, ll> mp;
	for(auto val : V){
		ll s = val.s, e = val.e, x = val.val;
		
		auto it = mp.upper_bound(s);
		ll xxx = 0;
		if(it == mp.begin()) xxx = 0;
		else{
			it--;
			xxx = it->second;
		}
		
		xxx += x;
		it = mp.upper_bound(e);
		if(it == mp.begin()) mp[e] = xxx;
		else{
			it--;
			if(it->second < xxx) mp[e] = xxx;		
		}
	}	
	
	cout << mp.rbegin()->second << '\n';
	return 0;
}
