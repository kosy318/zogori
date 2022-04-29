#include <bits/stdc++.h>
using namespace std;

#define int long long

using pint = pair<int, int>;
#define x first
#define y second

int n;
pint a[100004];

bool possible(int k) {
	int x = -1e9;
	for (int i=0; i<n; i++) {
		if (x > a[i].y) return false;
		if (x < a[i].x) x = a[i].x;
		x += k;
	}
	return true;
}

main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i].x >> a[i].y, a[i].y += a[i].x;
	
	sort(a, a+n);
	
	int l = -1, r = 1e9 + 7;
	while (l+1<r) {
		int m = (l+r) / 2;
		if (possible(m)) l = m;
		else r = m;
	}
	
	cout << l << '\n';
}
