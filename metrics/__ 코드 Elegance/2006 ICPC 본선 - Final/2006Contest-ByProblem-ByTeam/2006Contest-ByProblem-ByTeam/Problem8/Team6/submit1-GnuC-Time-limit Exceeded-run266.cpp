#include <cstdio>
#include <cstring>

#define max(a, b) (((a) > (b)) ? (a) : (b))

using namespace std;

const int Maxn = 5010;
const int Maxm = 60;

char x[Maxm];
char y[Maxn];
short table[Maxn][Maxm];
int ans[Maxn];

int main() {
	int T;
	scanf("%d", &T);
	scanf(" ");

	int ny, nx;
	for(int q = 0; q < T; q++) {
		memset(ans, 0, sizeof(ans));
		memset(y, 0, sizeof(y));
		memset(x, 0, sizeof(x));
		scanf("%s", y);
		scanf("%s", x);
		ny = strlen(y);
		nx = strlen(x);
		int n2y = 2 * ny;
		for (int i = 0; i < 5000; i++) {
			table[i][0] = i;
			ans[i] = ny + 1;
		}
		for(int i = 0; i < 60; i++) {
			table[0][i] = i;
		}
		ans[0] = 0;
		for (int i = 0; i < nx; i++) {
			for (int j = 0; j < ny; j++) {
				for (int k = 0; k < n2y; k++) {
					if (i + k >= nx) break;
					if (y[j] == x[i + k]) {
						table[j + 1][k + 1] = table[j][k];
					} else {
						if (table[j + 1][k] > table[j][k + 1]) {
							table[j + 1][k + 1] = table[j][k + 1] + 1;
						} else {
							table[j + 1][k + 1] = table[j + 1][k] + 1;
						}
						if (table[j + 1][k + 1] > table[j][k] + 1) {
							table[j + 1][k + 1] = table[j][k] + 1;
						}
					}
				}
			}
/*			for(int j = 0; j <= ny; j++) {
				for(int k = 0; k <= n2y; k++) {
					if (i + k >= nx) break;
					printf("%d ", table[j][k]);
				}
				printf("\n");
			}
			printf("\n");*/
			for(int j = 1; j < n2y; j++) {
				if (i + j > nx) break;
				int gg = table[ny][j];
//				if (j < ny) gg += ny - j;
//				printf("%d ", gg);
				if (ans[i + j] > max(ans[i], gg)) ans[i + j] = max(ans[i], gg);
			}
//			printf("%d\n", ans[i]);
		}
		printf("%d\n", ans[nx]);
	}
	return 0;
}
