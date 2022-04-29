#include <cstdio>
#include <algorithm>

using namespace std;

const int Maxn = 5005;

int T;
int n, m;
int table[Maxn];

int main() {
	int i;
	scanf("%d", &T);
	for(int q = 0; q < T; q++) {
		scanf("%d%d", &n, &m);
		for(i = 0; i < n; i++) {
			scanf("%d", &table[i]);
		}
		sort(table, table + n);

		int a = -1, b = -1, s = 0;
		int res = 0;
		for(i = 0; i < n; i++) {
			if (a + b == -2) {
				a = i;
				s = 1;
			}
			else if (b == -1) {
				if (table[a] + m >= table[i]) {
					b = i;
					s = 2;
				}
				else {
					a = i;
					s = 1;
				}
			}
			else {
				if (table[a] + m >= table[i]) {
					a = b;
					b = i;
					s++;
				}
				else if (table[b] + m >= table[i]) {
					a = b;
					b = i;
					s = 2;
				}
				else {
					a = i;
					b = -1;
					s = 1;
				}
			}
			if (s > res) res = s;
		}

		printf("%d\n", res);
	}
	return 0;
}
