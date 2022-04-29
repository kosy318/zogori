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
using ld = long double;

struct rgb {
	ll r, g, b;
	ll norm() {
		return r*r+g*g+b*b;
	}
};

rgb A[100];

rgb operator-(const rgb &a, const rgb &b) {
	return {a.r-b.r, a.g-b.g, a.b-b.b};
}
rgb operator+(const rgb &a, const rgb &b) {
	return {a.r+b.r, a.g+b.g, a.b+b.b};
}

int N, K;

ld _pow(ld a) {return a*a;}

void go() {
	ll sr = 0, sg = 0, sb = 0;
	rep(i, N) {
		sr += A[i].r;
		sg += A[i].g;
		sb += A[i].b;
	}
	
	ld vr = (ld)sr/N;
	ld vg = (ld)sg/N;
	ld vb = (ld)sb/N;
	
	ld res = 0;
	rep(i, N) {
		res += _pow(A[i].r-vr);
		res += _pow(A[i].g-vg);
		res += _pow(A[i].b-vb);
	}
	
	cout << fixed << setprecision(6) << res << '\n';
	
	exit(0);
}

ld calc(int cnt, rgb sum, rgb dsum) {
	ld pr = (ld)sum.r/cnt;
	ld pg = (ld)sum.g/cnt;
	ld pb = (ld)sum.b/cnt;
	
	ld ret = dsum.r + dsum.g + dsum.b;
	ret += -2*pr*sum.r -2*pg*sum.g -2*pb*sum.b;
	ret += (pr*pr + pg*pg + pb*pb)*cnt;
	
	return ret;
}

rgb pre[101], suf[101];
rgb dpre[101], dsuf[101];

ld doit(int i, int j) {
	swap(A[0], A[i]);
	swap(A[1], A[j]);
	
	sort(A+2, A+N, [](rgb &a, rgb &b) {
		ld v1 = (a-A[0]).norm();
		ld v2 = (b-A[0]).norm();
		return v1 < v2;
	});
	
	pre[1] = A[0];
	dpre[1] = {A[0].r*A[0].r + A[0].g*A[0].g + A[0].b*A[0].b};
	suf[N] = A[1];
	dsuf[N] = {A[1].r*A[1].r + A[1].g*A[1].g + A[1].b*A[1].b};
	
	
	repp(i, 2, N) {
		pre[i] = pre[i-1]+A[i];
		rgb v = {A[i].r*A[i].r, A[i].g*A[i].g, A[i].b*A[i].b};
		dpre[i] = dpre[i-1]+v;
	}
	for (int i = N-1; i >= 2; i--) {
		suf[i] = suf[i+1]+A[i];
		rgb v = {A[i].r*A[i].r, A[i].g*A[i].g, A[i].b*A[i].b};
		dsuf[i] = dsuf[i+1]+v;
	}
	
	ld res = 1e100;
	for (int i = 1; i < N; i++) {
		ld v1 = calc(i,   pre[i],   dpre[i]);
		ld v2 = calc(N-i, suf[i+1], dsuf[i+1]); 
		res = min(res, v1+v2);
	}
	
	return res;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> K;
	rep(i, N) {
		int r, g, b; cin >> r >> g >> b;
		A[i] = {r, g, b};
	}
	
	if (N <= K) {
		cout << "0.000000" << '\n';
		return 0;
	}
	
	if (K == 1) go();
	
	ld res = 1e100;
	rep(i, N) repp(j, i+1, N) {
		res = min(res, doit(i, j));
	}
	
	cout << fixed << setprecision(6) << res << '\n';
}	













