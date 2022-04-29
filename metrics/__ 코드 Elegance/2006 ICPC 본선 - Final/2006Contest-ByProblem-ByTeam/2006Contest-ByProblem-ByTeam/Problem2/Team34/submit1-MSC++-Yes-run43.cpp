#include <stdio.h>

char gene[55][1100];
int cnt[1100][4];
char table[4] = {'A', 'C', 'G', 'T'};
char str[1100];

inline index( char a )
{
	int i;
	for( i=0 ; i<4 ; i++ )
		if( table[i] == a )
			return i;

	return 0;
}

inline maximum( int *a )
{
	int i;
	int max, p;
	p = 0;
	max = a[0];
	for( i=1 ; i<4 ; i++ )
	{
		if( a[i] > max )
		{
			max = a[i];
			p = i;
		}
	}

	return p;
}

int main()
{
	int c, t;

	int n, m;

	int i, j;

	int sum;

	scanf( "%d", &c );

	for( t=1 ; t<=c ; t++ )
	{
		scanf( "%d%d", &n, &m );

		for( i=0 ; i<m ; i++ )
		{
			cnt[i][0] = 0;
			cnt[i][1] = 0;
			cnt[i][2] = 0;
			cnt[i][3] = 0;
		}

		for( i=0 ; i<n ; i++ )
		{
			scanf( "%s", gene[i] );

			for( j=0 ; j<m ; j++ )
				cnt[j][ index( gene[i][j] ) ]++;
		}

		for( i=0 ; i<m ; i++ )
		{
			str[i] = table[ maximum( cnt[i] ) ];
		}

		sum = 0;

		for( i=0 ; i<n ; i++ )
		{
			for( j=0 ; j<m ; j++ )
				sum += str[j] != gene[i][j];
		}

		str[m] = 0;
		printf( "%s\n", str );
		printf( "%d\n", sum );
	}

	return 0;
}