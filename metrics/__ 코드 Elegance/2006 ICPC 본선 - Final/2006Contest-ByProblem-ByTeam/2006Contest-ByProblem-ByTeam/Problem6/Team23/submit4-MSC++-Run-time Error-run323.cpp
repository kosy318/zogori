#include <stdio.h>

int main ()
{
	int a[20], b[20];
	int m;
	int t;

	int n;
	int i,j;
	int cnt, max, k;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++) 
			scanf("%d %d", &a[i], &b[i]);

		scanf("%d", &m);

		max = 0;
		for (i=1; i<n; i++)
			if (b[max] < b[i]) max = i;

		for (i=0; i<=m; i++)
		{
			k = b[max] + a[max] * i;
			cnt = 0;

			for (j=0; j<n; j++)
				if (((k - b[j]) % a[j]) != 0) {
					cnt = -1; 
					break;
				}
				else 
					cnt = cnt + (k - b[j]) / a[j];
			
			if (cnt >= m) break;
		}

		if (cnt != m) printf("0\n"); else printf("%d\n", k);
	}
}

