#include <cstdio>

using namespace std;

int a1, b1, c1, a2, b2, c2;
int st, et;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int count = 0;
		scanf(" %d:%d:%d %d:%d:%d", &a1, &b1, &c1, &a2, &b2, &c2);
		st = a1 * 10000 + b1 * 100 + c1;
		et = a2 * 10000 + b2 * 100 + c2;
		while (st != et) {
			if (st % 3 == 0) count++;
			st++;
			if (st % 100 == 60) {
				st += 100;
				st -= 60;
			}
			if ((st / 100) % 100 == 60) {
				st += 10000;
				st -= 6000;
			}
			if (st == 240000) st = 0;
		}
		if (et % 3 == 0) count++;
		printf("%d\n", count);
	}
}
