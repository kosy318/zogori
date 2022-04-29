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

int n;
vector<int> yy;
struct point { int x, y, c; } ps[2005];

struct node {
	ll L, R, S, M;
	node() : L(0), R(0), S(0), M(0) {}
	node operator+(const node &p) const {
		node ret;
		ret.L = max(L, S + p.L);
		ret.R = max(p.R, p.S + R);
		ret.S = S + p.S;
		ret.M = max({ M, p.M, R + p.L });
		return ret;
	}
	void add(ll v) {
		L += v;
		R += v;
		S += v;
		M += v;
	}
} seg[1 << 15];

void init(int i, int s, int e) {
	seg[i] = node();
	if (s == e) return;
	int m = s + e >> 1;
	init(i << 1, s, m);
	init(i << 1 | 1, m + 1, e);
}

void update(int i, int s, int e, int x, int v) {
	if (s == e) {
		seg[i].add(v);
		return;
	}
	int m = s + e >> 1;
	if (x <= yy[m]) update(i << 1, s, m, x, v);
	else update(i << 1 | 1, m + 1, e, x, v);
	seg[i] = seg[i << 1] + seg[i << 1 | 1];
}

int main(){
	fio;
	int n1, n2, c1, c2;
	cin >> n1;
	for (int i = 0; i < n1; ++i) cin >> ps[i].x >> ps[i].y;
	cin >> n2; n = n1 + n2;
	for (int i = n1; i < n; ++i) cin >> ps[i].x >> ps[i].y;
	cin >> c1 >> c2;
	for (int i = 0; i < n1; ++i) ps[i].c = c1;
	for (int i = n1; i < n; ++i) ps[i].c = -c2;
	for (int i = 0; i < n; ++i) yy.push_back(ps[i].y);
	sort(yy.begin(), yy.end());
	sort(ps, ps + n, [&](point a, point b) { return a.x < b.x; });
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		init(1, 0, n - 1);
		for (int j = i; j < n; ++j) {
			update(1, 0, n - 1, ps[j].y, ps[j].c);
			ans = max(ans, seg[1].M);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
