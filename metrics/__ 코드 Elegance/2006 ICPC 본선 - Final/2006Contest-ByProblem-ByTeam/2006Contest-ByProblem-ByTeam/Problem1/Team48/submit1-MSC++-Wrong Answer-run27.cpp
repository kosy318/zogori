#include <stdio.h>

int chk(int x) {
	if (x % 100 >= 60) return 0;
	if ((x/100) % 100 >= 60) return 0;
	if (x/10000 >= 24) return 0;
	return 1;
}

int main() {
	int s1, s2, s3, e1, e2, e3;
	int cwcw, ss, ee, cnt;
	scanf("%d", &cwcw);
	while(cwcw--) {
		scanf("%d:%d:%d %d:%d:%d", &s1, &s2, &s3, &e1, &e2, &e3);
		cnt = 0;
		ss = s1 * 10000 + s2 * 100 + s3;
		ee = e1 * 10000 + e2 * 100 + e3;
		while(1) {
			if (chk(ss) == 1) {
				if (ss % 3 == 0) cnt++;
			}
			if (ss / 10000 >=24) ss -= 240000;
			ss ++;
			if (ss == ee) break;
		}
		printf("%d\n", cnt);
	}
	return 0;
}