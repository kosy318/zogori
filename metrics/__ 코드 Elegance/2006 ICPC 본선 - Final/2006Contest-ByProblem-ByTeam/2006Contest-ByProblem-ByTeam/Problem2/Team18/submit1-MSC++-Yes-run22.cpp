#include <cstdio>

void main() {
	int allcnt = 0;
	scanf("%d", &allcnt);
	for (int i = 0; i < allcnt; i++) {
		int err = 0;
		int cnt, lng;
		scanf("%d%d", &cnt, &lng);
		char **stn = new char*[cnt];
		for (int j = 0; j < cnt; j++) {
			stn[j] = new char[lng + 1];
			scanf("%s", stn[j]);
		}
		char *output = new char[lng + 1];
		int outn = 0;

		for (int k = 0; k < lng; k++) {
			int charn['Z'-'A'];
			for (int c= 0 ; c < 'Z'-'A'; c++) {
				charn[c] = 0;
			}

			for (int j = 0; j < cnt; j++) {
				charn[stn[j][k] - 'A']++;
			}
			char maxc;
			int maxn = 0;
			for (int c= 0 ; c < 'Z'-'A'; c++) {
				if (charn[c] > maxn) {
					maxc = c;
					maxn = charn[c];
				}
			}
			err += cnt - maxn;
			output[outn++] = maxc + 'A'; 
		}
		output[outn++] = 0;
		printf("%s\n", output);
		printf("%d\n", err);
	}
}