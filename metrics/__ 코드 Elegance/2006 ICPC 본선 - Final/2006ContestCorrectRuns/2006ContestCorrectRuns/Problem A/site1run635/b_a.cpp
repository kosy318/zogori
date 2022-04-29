#include <cstdio>
#include <cstring>
#include <cstdlib>

int f(int a, int b) {
	//if (b >= 240000) b -= 240000;
	int m = (b - a + 1) % 3;
	int d = (b - a + 1) / 3;
	if (m == 0)
		return(d);

	if (a % 3 == 0 || b % 3 == 0)
		return(d + 1);
	else
		return(d);
}

void main() {
	int allcnt = 0;
	scanf("%d", &allcnt);
	for (int i = 0; i < allcnt; i++) {
		char tmp[256], tmp2[256];;
		scanf("%s%s", &tmp, &tmp2);
		tmp[2] = 0; tmp[5] = 0; tmp2[2] = 0; tmp2[5] = 0; 
		int houra = atoi(&tmp[0]);
		int mina = atoi(&tmp[3]);
		int seca = atoi(&tmp[6]);
		int cal_a = houra * 10000 + mina * 100 + seca;
		int hourb = atoi(&tmp2[0]);
		int minb = atoi(&tmp2[3]);
		int secb = atoi(&tmp2[6]);
		int cal_b = hourb * 10000 + minb * 100 + secb;
		
		int count = 0;

		if (cal_b < cal_a) cal_b += 240000;

		if (houra == hourb && mina == minb) {
			count = f(seca, secb);
		}
		else {
			int f1 = f(cal_a, cal_a + 60 - seca - 1); 
			int f2 = f(cal_b - secb, cal_b);

			if (++mina == 60) { mina = 0; houra++; }

			int mindis = (minb - mina < 0) ? minb + 60 - mina : minb - mina;
			int f4 = mindis * 20;
			hourb += 24;
			int hourdis = (minb - mina < 0) ? hourb - houra - 1 : hourb - houra;
			if (hourdis >= 24) hourdis -= 24;
			int f3 = hourdis * 1200;

			count = f1 + f2 + f3 + f4;
		}

		printf("%d\n", count);
	}
}