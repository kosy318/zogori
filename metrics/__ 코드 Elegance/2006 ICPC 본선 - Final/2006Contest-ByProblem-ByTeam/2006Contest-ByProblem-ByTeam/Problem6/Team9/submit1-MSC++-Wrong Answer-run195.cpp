#include <stdio.h>
#include <math.h>
#define N 20

int n, t, m;
int a[N], b[N];
double at, bt, g;

bool isint(double a)
{
	double b = (double)(int)a;

	if(fabs(a-b) < 0.000001)
		return true;
	return false;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);

		at = bt = 0;
		g = 0;

		int i;
		for (i = 0; i < n; i++) {
			scanf("%d %d", &a[i], &b[i]);
			at += 1 / (double)a[i];
			bt += (double)b[i] / (double)a[i];
		}
		scanf("%d", &m);

		g = (m + bt) / at;

		if (!isint(g))
			g = 0;

		double x;
		for (i = 0; i < n && g; i++) {
			x = (g - b[i]) / a[i];
			if (!isint(x))
				g = 0;
		}

		printf("%d\n", (int)g);
	}

	return 0;
}
/*
at = 1.583333333333333333333333333333

*/