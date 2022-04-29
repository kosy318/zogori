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

void go(int v) {
	cout << v << '\n';
	exit(0);
}

int val1(int v) {
	for (int i = 1; i < 23; i++) {
		int calc = ((1<<i)-1)*2;
		if (calc >= v) return 2*i-1;
		//debug(1, i, calc);
	}	
}

int val2(int v) {
	for (int i = 1; i < 23; i++) {
		int calc = 3*((1<<(i-1))-1)+1;
		if (calc >= v) return 2*i-2;
		//debug(2, i, calc);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N; cin >> N;
	N -= 2;
	if (N == 0) go(0);
	
	go(min(val1(N), val2(N)));	
}










