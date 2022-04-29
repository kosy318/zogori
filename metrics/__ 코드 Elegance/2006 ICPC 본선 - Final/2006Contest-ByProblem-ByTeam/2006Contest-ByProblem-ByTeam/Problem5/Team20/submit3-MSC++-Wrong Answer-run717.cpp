#include <stdio.h>

#define MAXN 50
#define MAXM 300
#define MAXL 200

int n;
int lena[MAXN+1];
int lenb[MAXN+1];
int f[MAXM+1][MAXM+1][2*MAXL+1];
int na, nb;
int a[MAXM+1], b[MAXM+1];



void Solve()
{
	int i, j, k, tmp, out;
	a[0] = b[0] = 0;
	for(i=-MAXL;i<=MAXL;i++)
	{
		f[0][0][i+MAXL] = 0;
	}
	for(i=0;i<=na;i++)
	{
		for(j=0;j<=nb;j++)
		{
			if(i == 0 && j == 0) continue;
			for(k=-MAXL;k<=MAXL;k++) f[i][j][k+MAXL] = -1;
			if(i > 0)
			{
				if(b[j] != a[i])
				{
					tmp = f[i-1][j][-lena[a[i]]+MAXL] + lena[a[i]];
				}
				else
				{
					tmp = f[i-1][j][0+MAXL] + lena[a[i]];
				}
				if(f[i][j][0+MAXL] == -1 || f[i][j][0+MAXL] > tmp)
				{
					f[i][j][0+MAXL] = tmp;
				}
			}
			if(j > 0)
			{
				if(a[i] != b[j])
				{
					tmp = f[i][j-1][lenb[b[j]] + MAXL] + lenb[b[j]];
				}
				else
				{
					tmp = f[i][j-1][0+MAXL] + lenb[b[j]];
				}
				if(f[i][j][0+MAXL] == -1 || f[i][j][0+MAXL] > tmp)
				{
					f[i][j][0+MAXL] = tmp;
				}
			}
			for(k=1;k<=MAXL;k++)
			{
				if(i > 0)
				{
					if(lena[a[i]] <= k)
					{
						tmp = f[i-1][j][0+MAXL];
					}
					else
					{
						if(a[i] != b[j])
						{
							tmp = f[i-1][j][-(lena[a[i]] - k) + MAXL] + (lena[a[i]] - k);
						}
						else
						{
							tmp = f[i-1][j][0+MAXL] + (lena[a[i]] - k);
						}
					}
					if(f[i][j][k+MAXL] == -1 || f[i][j][k+MAXL] > tmp)
					{
						f[i][j][k+MAXL] = tmp;
					}
				}
				if(j > 0)
				{
					tmp = f[i][j-1][0+MAXL] + lenb[b[j]];
					if(f[i][j][k+MAXL] == -1 || f[i][j][k+MAXL] > tmp)
					{
						f[i][j][k+MAXL] = tmp;
					}
				}
			}
			for(k=-MAXL;k<=-1;k++)
			{
				out = - k;
				if(j > 0)
				{
					if(lenb[b[j]] <= out)
					{
						tmp = f[i][j-1][0+MAXL];
					}
					else
					{
						if(a[i] != b[j])
						{
							tmp = f[i][j-1][lenb[b[j]] - out + MAXL] + (lenb[b[j]] - out);
						}
						else
						{
							tmp = f[i][j-1][0 + MAXL] + lenb[b[j]] - out;
						}
					}
					if(f[i][j][k+MAXL] == -1 || f[i][j][k+MAXL] > tmp)
					{
						f[i][j][k+MAXL] = tmp;
					}
				}
				if(i > 0)
				{
					tmp = f[i-1][j][0+MAXL] + lena[a[i]];
					if(f[i][j][k+MAXL] == -1 || f[i][j][k+MAXL] > tmp)
					{
						f[i][j][k+MAXL] = tmp;
					}
				}
			}
		}
	}
	printf("%d\n", f[na][nb][0+MAXL]);
}

int main()
{
	int i;
	int ca;
	scanf("%d", &ca);
	while(ca-- > 0)
	{
		scanf("%d", &n);
		for(i=1;i<=n;i++)
		{
			scanf("%d", &lena[i]);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d", &lenb[i]);
		}
		scanf("%d %d", &na, &nb);
		for(i=1;i<=na;i++)
		{
			scanf("%d", &a[i]);
		}
		for(i=1;i<=nb;i++)
		{
			scanf("%d", &b[i]);
		}
		Solve();
	}
	return 0;
}