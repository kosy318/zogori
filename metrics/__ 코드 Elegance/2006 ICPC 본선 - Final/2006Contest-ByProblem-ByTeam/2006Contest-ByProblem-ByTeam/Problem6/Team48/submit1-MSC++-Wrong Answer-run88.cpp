#include <cstdio>

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
	int st = 0, en = 101001;
	while (st + 1 < en) {
		int t = (st + en) / 2;
		int mm = 0;
		for (int i = 0; i < n; ++i)
			mm += (t - b[i]) / a[i];
		if (mm > m)
			en = t;
		else
			st = t;
	}
	for (int i = 0; i < n; ++i)
		if ((st - b[i]) % a[i] != 0)
			return 0;
	return st;
}
