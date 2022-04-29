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

const int inf = 1e7;
struct segtree{
	int v[500000];
	int siz;
	
	void init(int n){
		for(siz=1;siz<=n+1;siz<<=1);
		
		for(int i=2*siz-1;i;i--) v[i] = inf;
	}
	
	void update(int pos, int x){
		pos += siz;
		v[pos] = x;
		pos >>= 1;
		while(pos){
			v[pos] = min(v[2*pos], v[2*pos+1]);
			pos >>= 1;
		}
	}
	
	int get_min(int l, int r){
		int ret = inf;
		l += siz;
		r += siz;
		while(l < r){
			if(l % 2 == 1) ret = min(ret, v[l++]);
			if(r % 2 == 0) ret = min(ret, v[r--]);	
			l >>= 1;
			r >>= 1;	
		}
		if(l == r) ret = min(ret, v[r]);
		return ret;
	}
	
};
using namespace std;
int m,n;
int x[100003];
int c[100003];
int head[100003];
segtree seg;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m >> n;
	for(int i=1;i<=n;i++){
		cin >> x[i];
	}
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	int pos = 0;
	for(int i=1;i<=n;i++){
		if(c[pos] != c[i]){
			pos = i;
		}
		head[i] = pos;
	}
	
	seg.init(n+1);
	
	for(int i=1;i<=n;i++){
		if(head[i] == 1) seg.update(i, 1);
		else{
			int h = head[i];
			int ret = inf;
			if(h < i) ret = min(ret, seg.get_min(h, i-1));
			int ph = head[h-1];
			int px = lower_bound(x+1, x+1+n, 2*x[h-1]-x[i]) - x;
			if(ph > px) px = h-1;
			//debug(ph, px);
			ret = min(ret, seg.get_min(ph, px));
			seg.update(i, ret+1);
			//debug(i, ret);
		}
	}
	cout << seg.get_min(n, n);
}	













