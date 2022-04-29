#include <cstdio>
#include <cstring>
#include <cstdlib>

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
		int hourb = atoi(&tmp2[0]);
		int minb = atoi(&tmp2[3]);
		int secb = atoi(&tmp2[6]);
		if (hourb < houra) hourb += 24;
		int dist = (hourb - houra) * 3600 +
			(minb - mina) * 60 +
			(secb - seca) + 1;
		dist /= 3;

		printf("%d\n", dist);
	}
}