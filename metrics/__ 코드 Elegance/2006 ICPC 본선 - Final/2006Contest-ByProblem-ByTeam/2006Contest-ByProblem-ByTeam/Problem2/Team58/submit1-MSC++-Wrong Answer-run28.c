#include <stdio.h>

int t, n, m;
char data[51][1001];
char sol[1001];

int main()
{
	int c, i, j, min, tmp, sum;
	scanf("%d", &t);
	
	for ( c = 0 ; c < t; c++ )
	{
		scanf("%d %d",&m, &n);

		for ( i = 0 ; i < m; i ++ )
		{
			scanf("%s", data[i]);
		}

		sum = 0;
		for ( j = 0 ; j < n; j++ )
		{
			min = 10000000;
			// A
			tmp = 0;

			for ( i = 0 ; i < m; i++ )
			{
				if ( data[i][j] != 'A' ) tmp ++;
			}

			if ( min > tmp ) 
			{
				min = tmp;
				sol[j] = 'A';
			}
			// G
			tmp = 0;

			for ( i = 0 ; i < m; i++ )
			{
				if ( data[i][j] != 'G' ) tmp ++;
			}

			if ( min > tmp ) 
			{
				min = tmp;
				sol[j] = 'G';
			}
			// C
			tmp = 0;

			for ( i = 0 ; i < m; i++ )
			{
				if ( data[i][j] != 'C' ) tmp ++;
			}

			if ( min > tmp ) 
			{
				min = tmp;
				sol[j] = 'C';
			}
			// T
			tmp = 0;

			for ( i = 0 ; i < m; i++ )
			{
				if ( data[i][j] != 'T' ) tmp ++;
			}

			if ( min > tmp ) 
			{
				min = tmp;
				sol[j] = 'T';
			}

			sum += min;
		}
		sol[n] = '\0';

		printf("%s\n%d\n", sol, sum);
	}

	return 0;
}