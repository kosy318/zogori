#include <cstdio>
#include <cstring>

using namespace std;

char a[55][1005];
char ans[1005];
char c[6] = "ACGT";

int main() {
	int T, n, m;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				scanf(" %c", &a[i][j]);
			}
		memset(ans, 0, sizeof(ans));
		int sol = 0;
		for (int i = 0; i < m; i++) {
			int max = -1;
			for (int j = 0; j < 4; j++) {
				int count = 0;
				for (int k = 0; k < n; k++) {
					if (a[k][i] == c[j]) count++;
				}
				if (count > max) {
					max = count;
					ans[i] = c[j];
				}
			}
			sol += (n - max);
		}
		printf("%s\n%d\n", ans, sol);
	}
}
