#include <stdio.h>
#include <string.h>

int t,n,m;
int a[20],b[20],x[20];

int getT (int a, int b, int x)
{
	return (a*x)+b;
}
int getX (int a, int b, int T)
{
	int e = T-b;
	if (e%a==0)
	{
		return e/a;
	}
	return -1;
}

void main()
{
	scanf ("%d",&t);

	for (int i=0;i<t;++i)
	{
		scanf ("%d",&n);
		for (int j=0;j<n;++j)
		{
			scanf ("%d %d",&a[j],&b[j]);
		}
		scanf ("%d",&m);
		int flag=0;
		for (j=0;j<=m;++j)
		{
			
			int tmp=j;
			
			memset (x,0,sizeof(int)*20);
			x[0]=j;

			int tmpT= getT(a[0],b[0],x[0]);
            for (int k=1;k<n;++k)
			{
				int tmpX = getX(a[k],b[k],tmpT);
				tmp+=tmpX;
				if (tmpX == -1 || tmp > 10000)
				{
					break;
				}
				x[k]=tmpX;
			}

			if (tmp == m)
			{
				printf ("%d\n",tmpT);
				flag=1;
				break;
			}
		}
		if (flag == 0)
			printf ("0\n");
	}
}