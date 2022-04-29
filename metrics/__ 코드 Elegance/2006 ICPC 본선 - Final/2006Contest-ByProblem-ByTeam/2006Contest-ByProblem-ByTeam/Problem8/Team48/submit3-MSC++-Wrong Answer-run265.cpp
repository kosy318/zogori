#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

int n, m;
char str1[101], str2[6001];
int table[101][6001];
bool seen[101][6001], call[101][6001];

int solve();
int recur(int i, int j, int k);

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
	static int table[101][6001];
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= m; ++j)
			seen[i][j] = false;
	table[0][0] = 0, seen[0][0] = true;
	for (int i = 1; i <= n; ++i)
		table[i][0] = i, seen[i][0] = true;
	for (int j = 1; j <= m; ++j)
		table[0][j] = j, seen[0][j] = true;
	return recur(n, m, m);
}

int recur(int i, int j, int k) {
	if (seen[i][j])
		return table[i][j];
	if (call[i][j])
		return INT_MAX;
	call[i][j] = true;
	int a = i - 1, b = j - 1;
	//if (i == 1 && j != 1 && j < k)
	if (i == 1 && j != 1)
		a = n;
	if (i == 1 && j == 3)
		a = a;
	if (str1[i] == str2[j])
		table[i][j] = std::min(recur(i - 1, b, k), recur(a, b, k));
	else
		table[i][j] = std::min(recur(i - 1, b, k),
		std::min(recur(i - 1, j, k),
		std::min(recur(a, b, k),
		std::min(recur(a, j, j), recur(i, b, k))))) + 1;
	seen[i][j] = true;
	call[i][j] = false;
	return table[i][j];
}
