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
using pii = pair<int, int>;


int N, M;
vector<int> v1, v2;
pii A[1000], B[1000];

struct Point {
	int x, y;
	int val;
};

namespace SEG {
	const int N = 1<<11;
	struct Block {
		int sum;
		int lrmax, lmax, rmax;
	};
	
	Block operator+(Block a, Block b) {
		Block ret;
		ret.sum = a.sum+b.sum;
		ret.lmax = max(a.lmax, a.sum+b.lmax);
		ret.rmax = max(b.rmax, b.sum+a.rmax);
		ret.lrmax = max({a.lrmax, b.lrmax, a.rmax, b.lmax});
		return ret;
	}
	Block tree[N<<1];
	
	void init() {
		rep(i, N*2) tree[i] = {0, 0, 0, 0};
	}
	
	void update(int p, int vv) {
		p += N;
		int v = tree[p].sum+vv;
		tree[p] = {v, max(v, 0), max(v, 0), max(v, 0)};
		for (p >>= 1; p; p >>= 1) tree[p] = tree[p<<1]+tree[p<<1|1];
	}
	
	int query() {
		return tree[1].lrmax;
	}
}

int pa, pb;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N;
	rep(i, N) {
		int a, b; cin >> a >> b;
		A[i] = {a, b};
		v1.push_back(a);
		v2.push_back(b);
	}
	
	cin >> M;
	rep(i, M) {
		int a, b; cin >> a >> b;
		B[i] = {a, b};
		v1.push_back(a);
		v2.push_back(b);
	}		
	
	cin >> pa >> pb;
	
	sort(v1.begin(), v1.end());
	v1.erase(unique(v1.begin(), v1.end()), v1.end());
	sort(v2.begin(), v2.end());
	v2.erase(unique(v2.begin(), v2.end()), v2.end());
	
	auto conv = [](int &v, vector<int> &t) {
		v = lower_bound(t.begin(), t.end(), v)-t.begin();
	};
	
	vector<Point> pt;
	rep(i, N) {
		conv(A[i].first, v1);
		conv(A[i].second, v2);
		pt.push_back({A[i].first, A[i].second, pa});
	}
	
	rep(i, M) {
		conv(B[i].first, v1);
		conv(B[i].second, v2);
		pt.push_back({B[i].first, B[i].second, -pb});
	}
	
	sort(pt.begin(), pt.end(), [](auto &a, auto &b) {
		return a.x < b.x;		
	});
	
	int res = 0;
	for (int i = 0, p = 0; i < pt.size(); i = p) {
		SEG::init();
		for (int j = i, q = 0; j < pt.size(); j = q) {
			while(q < pt.size() and pt[j].x == pt[q].x) {
				SEG::update(pt[q].y, pt[q].val);
				q++;	
			}
			res = max(res, SEG::query());
		}
		
		while(p < pt.size() and pt[i].x == pt[p].x) p++;
	}
	
	cout << res << '\n';
}	













