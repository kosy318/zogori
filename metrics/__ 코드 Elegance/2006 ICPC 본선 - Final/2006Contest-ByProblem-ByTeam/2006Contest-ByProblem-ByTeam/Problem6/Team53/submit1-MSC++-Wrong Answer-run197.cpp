#include<stdio.h>
int a[1001];
int b[1001];
void main()
{
	int t,n,i,m,s,k,j,sw;
	//freopen("f.in","r",stdin);
	scanf("%d",&t);
	for(t;t>=1;t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&a[i],&b[i]);
		}
		scanf("%d",&m);
		s=0;
		sw=0;
		for(i=1;i<=m;i++)
		{
			s=i;
			k=a[1]*i+b[1];
			for(j=2;j<=n;j++)
			{
				if((k-b[j])%a[j] !=0 || (k-b[j])< 0)
				{
					break;
				}
				else
				{
					s=s+(k-b[j])/a[j];
				}
			}
			if(s==m) 
			{
				sw=1;
				printf("%d\n",k);
				break;
			}
		}
		if(sw==0) printf("0\n");
	}
}
