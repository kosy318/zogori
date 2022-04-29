#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

int n, m, k;
char str1[101], str2[6001];
int table[101][6001];
bool seen[101][6001], call[101][6001];

int solve();
int recur(int i, int j);

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%s%s", str1 + 1, str2 + 1);
		n = (int)strlen(str1 + 1);
		m = (int)strlen(str2 + 1);
		int ans = solve();
		printf("%d\n", ans);
	}
}

int solve() {
	int st = -1, en = n + m;
	while (st + 1 < en) {
		k = (st + en) / 2;
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= m; ++j)
				seen[i][j] = false;
		table[0][0] = 0, seen[0][0] = true;
		for (int i = 1; i <= n; ++i)
			table[i][0] = i, seen[i][0] = true;
		for (int j = 1; j <= m; ++j)
			table[0][j] = j, seen[0][j] = true;
		if (recur(n, m) <= k)
			en = k;
		else
			st = k;
	}
	return en;
}

int recur(int i, int j) {
	if (seen[i][j])
		return table[i][j];
	if (call[i][j])
		return n + m + 1;
	call[i][j] = true;
	if (str1[i] == str2[j])
		table[i][j] = recur(i - 1, j - 1);
	else
		table[i][j] = std::min(recur(i - 1, j - 1),
		std::min(recur(i - 1, j), recur(i, j - 1))) + 1;
	if (i == 1 && j > 1) {
		if (str1[i] == str2[j]) {
			if (recur(n, j - 1) <= k)
				table[i][j] = 0;
		} else {
			if (recur(n, j - 1) <= k)
				table[i][j] = std::min(table[i][j], 1);
			if (recur(n, j) <= k)
				table[i][j] = std::min(table[i][j], 1);
		}
	}
	seen[i][j] = true;
	call[i][j] = false;
	return table[i][j];
}
