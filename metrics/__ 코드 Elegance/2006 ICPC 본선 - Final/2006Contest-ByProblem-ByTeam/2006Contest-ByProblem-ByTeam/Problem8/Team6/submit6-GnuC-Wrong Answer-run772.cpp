#include <cstdio>
#include <cstring>

#define max(a, b) (((a) > (b)) ? (a) : (b))

using namespace std;

const int Maxn = 5010;
const int Maxm = 60;

char x[Maxm];
char y[Maxn];
char back[Maxn][Maxn];
short table[Maxn][Maxn];

int main() {
	int T;
	scanf("%d", &T);
	scanf(" ");

	int ny, nx;
	for(int q = 0; q < T; q++) {
		memset(y, 0, sizeof(y));
		memset(x, 0, sizeof(x));
		scanf("%s", y);
		scanf("%s", x);
		ny = strlen(y);
		nx = strlen(x);
		int n2y = 2 * ny;
		for (int i = 0; i < 5000; i++) {
			table[0][i] = 0;
		}
		for(int i = 0; i < 60; i++) {
			table[i][0] = i;
		}
		for (int i = 0; i < nx; i++) {
			for (int j = 0; j < ny; j++) {
				if (y[j] == x[i]) {
					table[j + 1][i + 1] = table[j][i];
					back[j + 1][i + 1] = 0;
				} else {
					if (table[j + 1][i] > table[j][i + 1]) {
						table[j + 1][i + 1] = table[j][i + 1] + 1;
						back[j + 1][i + 1] = 1;
					} else {
						table[j + 1][i + 1] = table[j + 1][i] + 1;
						back[j + 1][i + 1] = 2;
					}
					if (table[j + 1][i + 1] >= table[j][i] + 1) {
						table[j + 1][i + 1] = table[j][i] + 1;
						back[j + 1][i + 1] = 0;
					}
				}
			}
		}
		
		int st = nx;
		int res = 0;
//		printf("%d - ", st);
		while(st > 0) {
			if (res < table[ny][st]) res = table[ny][st];
			int k = ny;
			int bb = st;
			while(k > 0 && st > 0) {
				if (back[k][st] == 0) {
					st--;
					k--;
				}
				else if (back[k][st] == 1) {
					k--;
				}
				else if (back[k][st] == 2) {
					st--;
				}
			}
			if (st == bb) {
				res = ny;
break;
			}
//			printf("%d - ", st);
		}
		printf("%d\n", res);
	}
	return 0;
}
