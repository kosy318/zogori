#include<stdio.h>
#include<string.h>

#define INF 1000000000

char a[5555], b[55];
int D[5001][101][51];
int DD[5001];
int n, m, mm;
int T;
int main(void)
{
	int l1, l2, l3;

//	freopen("h.in","r",stdin);

	for(l1=1;l1<=5000;l1++)
	{
		for(l2=1;l2<=50;l2++)
		{
			D[l1][0][l2] = l2;
		}
		for(l2=1;l2<=100;l2++)
		{
			D[l1][l2][0] = l2;
		}
	}

	for(scanf("%d",&T);T>=1;T--)
	{
		scanf("%s %s",b+1,a+1);
		n = strlen(a+1);
		m = strlen(b+1);
		mm = m + m;

		for(l1=1;l1<=n;l1++)
		{
			for(l2=1;l2<=mm;l2++)
			{
				for(l3=1;l3<=m;l3++)
				{
					D[l1][l2][l3] = D[l1][l2-1][l3-1] + (a[l1+l2-1] != b[l3]);
					if(D[l1][l2][l3] > D[l1][l2-1][l3] + 1)
						D[l1][l2][l3] = D[l1][l2-1][l3] + 1;
					if(D[l1][l2][l3] > D[l1][l2][l3-1] + 1)
						D[l1][l2][l3] = D[l1][l2][l3-1] + 1;
				}
			}
		}
		for(l1=1;l1<=n;l1++)
		{
			DD[l1] = INF;
			for(l2=1;l2<=mm && l1 - l2 >= 0;l2++)
			{
				if(l1 - l2 >= 0)
				{
					int tt = DD[l1-l2];
					if(tt < D[l1-l2+1][l2][m]) tt = D[l1-l2+1][l2][m];
					if(DD[l1] > tt)
						DD[l1] = tt;
				}
			}
		}
		printf("%d\n",DD[n]);
	}
}