#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int a1, a2, a3;
	int b1, b2, b3;
	int n;
	int i, j, k;
	int count, res;
	char buf1[10], buf2[10];

	scanf("%d", &n);
	for (i=0; i<n; i++) {
		scanf("%s %s", buf1, buf2);
		a1 = atoi(&buf1[0]);
		a2 = atoi(&buf1[3]);
		a3 = atoi(&buf1[6]);
		b1 = atoi(&buf2[0]);
		b2 = atoi(&buf2[3]);
		b3 = atoi(&buf2[6]);

		count = 0;
		if (a3 > b3) {
			b3 += 60;
			a2++;
			if (a2 >= 60) {

				a2++;
				a2 = a2%60;
				a1++;
				if (a1 >= 24) {
					a1++;
					a1 = a1%24;
				}
			}
		}
		count += b3 - a3;

		if (a2 > b2) {
			b2 += 60;
			a1++;
			if (a1 >= 24) {
				a1++;
				a1 = a1%24;
			}
		}
		count += (b2 - a2) * 60;

		if (a1 > b1) {
			b1 += 24;
		}
		if ((b1 - a1) != 24) 
			count += (b1 - a1) * 60 * 60;
        
		res = count / 3;
		if (count % 3) res++;

		printf("%d\n", res);
	}

	return 0;
}