#include <stdio.h>

void up( int &h, int &m, int &s )
{
	s++;

	if( s >= 60 )
	{
		s = 0;
		m++;
	}

	if( m >= 60 )
	{
		m = 0;
		h++;
	}

	if( h >= 24 )
		h = 0;
}

int ismult3( int h, int m, int s )
{
	int a;
	a = s + m*100 + h * 10000;

	return (a % 3) == 0;
}

int main()
{
	int h1, h2, m1, m2, s1, s2;
	int n;
	int cnt;

	scanf( "%d", &n );

	while( n-- )
	{
		cnt = 0;

		scanf("%d:%d:%d", &h1, &m1, &s1 );
		scanf("%d:%d:%d", &h2, &m2, &s2 );

		while( h1 != h2 || m1 != m2 || s1 != s2 )
		{
			if( ismult3( h1, m1, s1 ) )
				cnt++;

			up( h1, m1, s1 );
		}

		if( ismult3( h1, m1, s1 ) )
			cnt++;

		printf( "%d\n", cnt );
	}

	return 0;
}