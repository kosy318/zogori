#include <stdio.h>

int main ()
{
	int a[20], b[20];
	int m;
	int t;

	int n;
	int i,j;
	int min, max, k;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++) 
			scanf("%d %d", &a[i], &b[i]);

		scanf("%d", &m);

		while (m > 0) {
			max = 0; min = 0;

			for (i=1; i<n; i++) {
				if (b[min] > b[i]) min = i;
				if (b[max] < b[i]) max = i;
			}
			
			if (min == max) {
				b[min] = b[min] + a[min];
				m--;
			}

			while (b[min] < b[max]) {
				b[min] = b[min] + a[min];
				m--;
			}
		}

		k = b[0];
		for (i=1; i<n; i++)	if (k != b[i]) k = -1;

		if (k == -1 || m < 0) printf("0\n"); else printf("%d\n", k);
	}
}

