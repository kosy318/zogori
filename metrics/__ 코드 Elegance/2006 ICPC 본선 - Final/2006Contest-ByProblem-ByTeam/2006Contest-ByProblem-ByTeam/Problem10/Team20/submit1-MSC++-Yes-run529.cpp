#include <stdio.h>
#include <stdlib.h>

#define MAXN 10000

int n, k;
int num[MAXN+1];

int Cmp(const void *a, const void *b)
{
	return *(const int *)a - *(const int *)b;
}

void Solve()
{
	int i, j;
	int last, ans;
	last = 0;
	ans = 1;
	qsort(&num[1], n, sizeof(num[0]), Cmp);
	for(i=1;i<=n;i++)
	{
		if(i == 1 || num[i] - num[i-1] > k)
		{
			if(ans < last) ans = last;
			last = 1;
		}
		else
		{
			last ++;
			if(i < n && num[i+1] - num[i-1] > k)
			{
				if(ans < last) ans = last;
				last = 1;
			}
		}
	}
	if(last > ans) ans = last;
	printf("%d\n", ans);
}

int main()
{
	int i;
	int ca;
	scanf("%d", &ca);
	while(ca-- > 0)
	{
		scanf("%d %d", &n, &k);
		for(i=1;i<=n;i++)
		{
			scanf("%d", &num[i]);
		}
		Solve();
	}

	return 0;
}