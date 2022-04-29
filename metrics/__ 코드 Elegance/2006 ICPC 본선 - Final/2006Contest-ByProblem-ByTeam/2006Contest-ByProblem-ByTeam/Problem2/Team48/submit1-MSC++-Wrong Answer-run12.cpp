#include <cstdio>
#include <algorithm>

int n, m, ansn;
char str[100][2000];
char ans[2000];

void solve();

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			scanf("%s", str[i]);
		solve();
		printf("%s\n%d\n", ans, ansn);
	}
}

int to_int(char c) {
	if (c == 'A')
		return 0;
	else if (c == 'T')
		return 1;
	else if (c == 'G')
		return 2;
	else if (c == 'C')
		return 3;
	return -1;
}

char to_char(int i) {
	const char str[5] = "ATGC";
	return str[i];
}

void solve() {
	ansn = 0;
	for (int j = 0; j < m; ++j) {
		int cnt[100];
		std::fill(cnt, cnt + 4, 0);
		for (int i = 0; i < n; ++i)
			++cnt[to_int(str[i][j])];
		int max = -1, maxk;
		for (int k = 0; k < 4; ++k) {
			if (cnt[k] > max)
				maxk = k, max = cnt[k];
		}
		ans[j] = to_char(maxk);
		ansn += i - max;
	}
}
