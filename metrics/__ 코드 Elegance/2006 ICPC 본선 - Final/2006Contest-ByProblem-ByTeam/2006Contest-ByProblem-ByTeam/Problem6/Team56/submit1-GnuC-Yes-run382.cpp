#include "stdio.h"
struct xxx
{
	int a,b;
	int total;
};
struct xxx a[40];
int main()
{
	int cases;
	int n,i,m;
	int min,id;
	for(scanf("%d",&cases);cases>0;cases--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&a[i].a,&a[i].b);
			a[i].total = 0;
		}
		scanf("%d",&m);
		while(m--)
		{
			min = 0x7fffffff;
			for(i=0;i<n;i++)
			{
				if(a[i].total < min)
				{
					id = i;
					min = a[i].total ;
				}
			}
			if(a[id].total == 0)
			{
				a[id].total = a[id].a + a[id].b ; 
			}
			else a[id].total += a[id].a ;
		}
		for(i=1;i<n;i++)
		{
			if( a[i].total != a[0].total )
				break;
		}
		if( i>= n)
			printf("%d\n",a[0].total);
		else printf("0\n");

	
	}

	return 0;
}