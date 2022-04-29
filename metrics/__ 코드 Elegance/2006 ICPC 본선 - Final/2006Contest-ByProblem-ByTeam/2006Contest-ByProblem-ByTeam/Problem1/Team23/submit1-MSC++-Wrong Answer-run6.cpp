#include <stdio.h>

int shh, smm, sss;
int ehh,emm, ess;

int main ()
{
	int t;
	int n;
	int cnt;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d:%d:%d", &shh, &smm, &sss);
		scanf("%d:%d:%d", &ehh, &emm, &ess);

		cnt = 0;
		while (1) 
		{
			if (shh == ehh && smm == emm && sss == ess) break;

			n = shh *10000 + smm * 100 + sss;
			
			if (n % 3 == 0) cnt ++;

			sss++;
			if (sss >= 60) {
				sss = sss - 60;
				smm++;
			}
			
			if (smm >= 60) {
				smm = smm - 60;
				shh++;
			}

			if (shh >= 24) {
				shh = shh - 24;
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}