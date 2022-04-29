#include<stdio.h>

unsigned short D[301][301][202];
char Check[301][301][202];
int n, m;
int Time1[51], Time2[51];
int K;
int a[301], b[301];

unsigned short Go(int l1, int l2, int tt)
{
	int l3;

	if(Check[l1][l2][tt + 100] == 0)
	{
		Check[l1][l2][tt + 100] = 1;
		if(l1 == 0 && l2 == 0) D[l1][l2][tt + 100] = 0;
		else if(l1 == 0)
		{
			D[l1][l2][tt + 100] = 0;
			for(l3=1;l3<=l2;l3++)
			{
				D[l1][l2][tt + 100] += (unsigned short)Time2[b[l3]];
			}
			D[l1][l2][tt + 100] -= (unsigned short)tt;
		}
		else if(l2 == 0)
		{
			D[l1][l2][tt + 100] = 0;
			for(l3=1;l3<=l1;l3++)
			{
				D[l1][l2][tt + 100] += (unsigned short)Time1[a[l3]];
			}
			D[l1][l2][tt + 100] -= (unsigned short)tt;
		}
		else
		{
			if(a[l1] == b[l2])
			{
				D[l1][l2][tt + 100] = 60000;
				if(tt >= 0)
				{
					if(D[l1][l2][tt + 100] > Go(l1, l2-1, 0) + (unsigned short)(Time2[b[l2]] - tt))
						D[l1][l2][tt + 100] = Go(l1, l2-1, 0) + (unsigned short)(Time2[b[l2]] - tt);
				}
				if(tt <= 0 && D[l1][l2][tt + 100] > Go(l1-1, l2, 0) + (unsigned short)(Time1[a[l1]] + tt))
				{
					D[l1][l2][tt + 100] = Go(l1-1, l2, 0) + (unsigned short)(Time1[a[l1]] + tt);
				}
			}
			else
			{
				int left1, left2;

				left1 = Time1[a[l1]];
				left2 = Time2[b[l2]];
				if(tt < 0)
				{
					left1 -= -tt;
				}
				else
				{
					left2 -= tt;
				}
				if(left1 == left2)
				{
					D[l1][l2][tt + 100] = Go(l1-1,l2-1,0) + left1;
				}
				else if(left1 < left2)
				{
					D[l1][l2][tt + 100] = Go(l1-1,l2,Time2[b[l2]]-(left2 - left1)) + left1;
				}
				else
				{
					D[l1][l2][tt + 100] = Go(l1,l2-1,-(Time1[a[l1]]-(left1 - left2))) + left2;
				}
			}
		}
	}
	return D[l1][l2][tt + 100];
}

int main(void)
{
	int T;
	int l1, l2, l3;

//	freopen("e.in","r",stdin);

	for(scanf("%d",&T);T>=1;T--)
	{
		scanf("%d",&K);
		for(l1=1;l1<=K;l1++) scanf("%d",&Time1[l1]);
		for(l1=1;l1<=K;l1++) scanf("%d",&Time2[l1]);

		scanf("%d %d",&n,&m);
		for(l1=1;l1<=n;l1++)
		{
			scanf("%d",&a[l1]);
		}
		for(l1=1;l1<=m;l1++)
		{
			scanf("%d",&b[l1]);
		}
		for(l1=0;l1<=n;l1++)
			for(l2=0;l2<=n;l2++)
				for(l3=0;l3<=200;l3++)
					Check[l1][l2][l3] = 0;

		printf("%d\n",Go(n, m, 0));
	}
}