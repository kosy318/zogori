#include <stdio.h>

main()
{
	int i, j, k;
	int tcase, n, a[20], b[20], x[20], s[20], m, result[100000], sum, check, set, cal, exitset;

	scanf("%d", &tcase);
	for(i=0;i<tcase;i++)
	{
		scanf("%d", &n);
		for(j=0;j<n;j++)
		{
			scanf("%d %d", &a[j], &b[j]);
			x[j]=1;
		}
		scanf("%d", &m);
		set=x[n-1]=m-(n-1);

		while(1)
		{
			cal=0;
			exitset=0;
			sum=0;
			check=0;
			s[0]=0;
			for(j=0;j<n;j++)
				sum+=x[j];
			if(sum==m)
			{
				s[0]=a[0]*x[0]+b[0];
				for(j=1;j<n;j++)
				{
					s[j]=a[j]*x[j]+b[j];
					if(s[0]!=s[j])
					{
						check=1;
						break;
					}
				}
				if(!check)
				{
					result[i]=s[0];
					break;
				}
			}

			if(result[i]==s[0])
				break;

			x[n-1]--;
			x[n-2]++;
			if(x[n-1]<=1)
			{
				for(j=0;j<n-1;j++)
				{
					if(x[j]==set)
					{
						x[j-1]++;
						x[j]=1;
						break;
					}
				}
				for(;j<n-1;j++)
					x[j]=1;
				for(j=0;j<n-1;j++)
					cal+=x[j];
				x[n-1]=m-cal;
			}
			if(x[0]>=m-2)
			{
				result[i]=0;
				break;
			}
		}
	}

	for(i=0;i<tcase;i++)
		printf("%d\n", result[i]);
}