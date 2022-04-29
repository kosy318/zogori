#include <stdio.h>

int main()
{
	int tc;
	int n;
	int a[25], b[25];
	int ap[25], bp[25];
	int i, j;
	int resk, resc, res;
	int tmp;

	scanf("%d", &tc);
	for (i=0; i<tc; i++) {
		scanf("%d", &n);
		for (j=0; j<n; j++) {
			scanf("%d %d", &a[j], &b[j]);
			ap[j] = a[j];
			bp[j] = b[j];
		}
		scanf("%d", &res);

		tmp = 1;
		for (j=0; j<n; j++) {
			tmp *= a[j];
		}

		for (j=0; j<n; j++) {
			ap[j] = tmp / a[j];
			bp[j] *= tmp / a[j];
		}
		res *= tmp;

		resk = 0;
		resc = 0;
		for (j=0; j<n; j++) {
			resk += ap[j];
			resc += bp[j];
		}
		
		tmp = res + resc;
		if (tmp % resk) printf("0\n");
		else
			printf("%d\n", tmp / resk);

	}

	return 0;
}