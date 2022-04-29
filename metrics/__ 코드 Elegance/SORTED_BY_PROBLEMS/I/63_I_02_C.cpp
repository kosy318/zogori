#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ALL(X) (X).begin(), (X).end()
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define pb push_back
typedef long long LL;
typedef double DB;
typedef long double LDB;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
const int MXN = (int)1e6 + 7;
pair<LL, LL> a[MXN];
int n;
bool ok(LL dis) {
	LL p1 = a[1].F;
	for (int i = 2; i <= n; i++) {
		if (p1 + dis > a[i].S) return false;
		p1 = max(p1 + dis, a[i].F);
	}
	return true;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld %lld", &a[i].F, &a[i].S);
		a[i].S += a[i].F;
	}
	sort(a + 1, a + n + 1);
	LL ll = 0, rr = 2000000000ll, ans = 0;
	while (ll <= rr) {
		LL mid = (ll + rr) >> 1;
		if (ok(mid)) {
			ll = mid + 1;
			ans = mid;
		} else {
			rr = mid - 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

