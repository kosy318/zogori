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

int n;
struct line{
	ll x, y;	
};
vector<line> v;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for(int i=0;i<n;i++){
		ll a, b;
		cin >> a >> b;
		v.push_back({a, a+b});
	}
	sort(v.begin(), v.end(), [&] (line& A, line& B){
		return A.x < B.x;
	});
	ll l = 0, r = 2e9+2;
	while(l < r){
		//cout << l << ' ' << r << endl;
		ll mid = (l+r)/2;
		ll cur = v[0].x;
		int yes = 1;
		for(int i=1;i<n;i++){
			if(cur + mid <= v[i].x) cur = v[i].x;
			else if(cur + mid > v[i].y){
				yes = 0;
				break;
			}
			else cur += mid;
		}
		if(!yes) r = mid;
		else l = mid+1;
	}
	cout << l-1;
}
