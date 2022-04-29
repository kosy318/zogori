#include "stdio.h"
char str[60][1006];
char last[1007];
int no[6];
int chartoint(char c)
{
	if( c== 'A')
		return 0;
	if( c == 'C')
		return 1;
	if( c == 'G')
		return 2;
	return 3;
}
char inttochar(int i)
{
	if( i == 0)
		return 'A';
	if( i==1)
		return 'C';
	if( i== 2)
		return 'G';
	return 'T';
}
int main()
{
	int cases;
	int n,m;
	int i,j,k;
	int total;
	int min,id;
	for(scanf("%d",&cases);cases>0;cases--)
	{
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%s",str[i]);
		}
		total = 0;
		for(i=0;i<m;i++)
		{
			for(j=0;j<6;j++)
				no[j] = 0;
			for(j=0;j<n;j++)
			{
				k = chartoint(str[j][i]);
				no[k]++;
			}
			min = -1;
			for(j=0;j<4;j++)
			{
				if( no[j] > min)
				{
					min = no[j] ;
					id = j;
				}
			}
			last[i] = inttochar(id);
			total = total + n - no[id] ;
		}
		last[m] = 0;
		printf("%s\n%d\n",last,total);
	}
	return 0;
}

