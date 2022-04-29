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


int main(){
	fio;
	int n;
	cin >> n;
	if (n == 3) cout << 0;
	else if (n == 4) cout << 1;
	else for (int d = 2; d <= 100; ++d) {
		int val = 3 * (1 << d / 2 - 1) + 1;
		if (d & 1) val += 1 << d / 2 + 1;
		if (n - 2 <= val) {
			cout << d;
			return 0;
		}
	}
	return 0;
}
