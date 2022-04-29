#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	char buf[100], buf2[100];
	int a, b, c;
	int i;
	int cnt, temp;
	int t1, t2, h, m , s;
	scanf("%d", &t);
	while (t--) {
		scanf("%d:%d:%d", &a, &b, &c);
		t1 = c;
		t1 += b * 60;
		t1 += a * 60 * 60;
		scanf("%d:%d:%d", &a, &b, &c);
		t2 = c;
		t2 += b*60;
		t2 += a * 60 * 60;
		if (t2 < t1)
			t2 += 24 * 60 * 60;
		cnt = 0;
		for (i = t1; i <= t2; i++) {
			temp = i;
			h = temp / 3600;
			temp %= 3600;
			m = temp / 60;
			temp %= 60;
			s = temp;
			if (h > 24)
				h -= 24;
			sprintf(buf, "%02d%02d%02d", h, m, s);
			a = atoi(buf);
			if (a % 3 == 0)
				cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
