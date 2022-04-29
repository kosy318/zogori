#include<stdio.h>

char str[51][1001];
char sol[1001];
int chk[100];

int main()
{
	int T, m, n;
	int i, j;
	int max;
	int dist;

	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &m, &n);
		for( i=0 ; i<m ; i++ )
		{
			scanf("%s", &str[i][0]);
		}

		
		dist = 0;

		for( j=0 ; j<n ; j++ )
		{
			for( i=0 ; i<100 ; i++ )
			{
				chk[i] = 0;
			}
			for( i=0 ; i<m ; i++ )
			{
				chk[str[i][j]]++;
			}
			max = 0;
			for( i=0 ; i<100 ; i++ )
			{
				if( chk[max] < chk[i] )
				{
					max = i;
				}
			}
			sol[j] = max;
		}
		sol[n] = '\0';

		for( i=0 ; i<n ; i++ )
		{
			for( j=0 ; j<m ; j++ )
			{
				if( sol[i]!=str[j][i] )
					dist++;
			}
		}
		printf("%s\n", sol);
		printf("%d\n", dist);
	}
	return 0;
}