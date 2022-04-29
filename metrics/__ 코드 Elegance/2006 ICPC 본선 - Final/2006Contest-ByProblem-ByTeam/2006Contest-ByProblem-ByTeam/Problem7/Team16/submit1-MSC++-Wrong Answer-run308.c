#include <stdio.h>

int result[10000][1000][2];

main()
{
	int i, j;
	int tcase, n, line[1000][3], max, cnt, allcnt[10000], sum;

	scanf("%d", &tcase);
	for(i=0;i<tcase;i++)
	{
		scanf("%d", &n);
		for(j=0;j<n;j++)
			scanf("%d %d %d", &line[j][0], &line[j][1], &line[j][2]);

		allcnt[i]=0;
		while(1)
		{
			sum=0;
			for(j=0;j<n;j++)
				sum+=line[j][2];
			if(!sum) break;

			cnt=0;
			max=0;
			for(j=0;j<n;j++)
				if(line[j][2]>line[max][2])
					max=j;

			for(;line[max][2];line[max][2]--)
			{
				if(cnt==max)
					cnt++;
				if(line[cnt][2])
				{
					line[cnt][2]--;
					result[i][allcnt[i]][0]=max+1;
					result[i][allcnt[i]][1]=cnt+1;
					allcnt[i]++;
				}
				else
					line[max][2]++;
				cnt++;
			}
		}
	}
	for(i=0;i<tcase;i++)
		for(j=0;j<allcnt[i];j++)
			printf("%d %d\n", result[i][j][0], result[i][j][1]);
}