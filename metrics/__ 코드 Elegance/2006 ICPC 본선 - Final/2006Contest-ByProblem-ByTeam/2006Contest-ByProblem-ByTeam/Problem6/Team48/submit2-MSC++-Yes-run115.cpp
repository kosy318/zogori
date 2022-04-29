#include <cstdio>
#include <cmath>

int n, m, a[100], b[100];
int solve();

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &a[i], &b[i]);
		scanf("%d", &m);
		int ans = solve();
		printf("%d\n", ans);
	}
}

int solve() {
	//int st = 0, en = 101001;
	double st = 0, en = 101001;
	//while (st + 1 < en) {
	while (en - st >= 1e-7) {
		//int t = (st + en) / 2;
		double t = (st + en) / 2;
		//int mm = 0;
		double mm = 0;
		for (int i = 0; i < n; ++i)
			//mm += (t - b[i]) / a[i];
			mm += double(t - b[i]) / double(a[i]);
		if (mm > m)
			en = t;
		else
			st = t;
	}
	int p = st + 0.5 + 1e-9;
	for (int i = 0; i < n; ++i)
		if ((p - b[i]) % a[i] != 0)
			return 0;
	int temp = 0;
	for (int i = 0; i < n; ++i)
		temp += (p - b[i]) / a[i];
	if (temp != m)
		return false;
	return p;
}
