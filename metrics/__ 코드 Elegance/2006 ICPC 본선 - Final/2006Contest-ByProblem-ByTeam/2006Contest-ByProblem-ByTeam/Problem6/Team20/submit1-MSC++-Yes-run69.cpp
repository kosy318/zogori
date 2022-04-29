#include <stdio.h>
#include <stdlib.h>

const int maxn=25;
int a[maxn],b[maxn];
int i,j,m,n;
bool check(int x)
{
	int i;
	int tot=0,xx;
	for (i=1;i<=n;i++)
	{
		if ((x-b[i])%a[i]>=0)
		{
			xx=(x-b[i])/a[i];
			if (xx>=0) tot+=xx;
			else return false;
		}else
		return false;
	}
	if (tot==m) return true;
	return false;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{
			scanf("%d %d",&a[i],&b[i]);
		}
		scanf("%d",&m);
		for (i=1;i<=101200;i++)
		{
			if (check(i)) break;
		}
		if (i<=101200)
			printf("%d\n",i);
		else
			printf("0\n");
	}
}