#include <iostream>
#include <fstream>

using namespace std;


int x[ 10000 ];
int y[ 10000 ];
int w, h;
int n;

int MIN( int a, int b )
{
	return ( a < b )? a : b;
}

int MAX( int a, int b )
{
	return ( a > b )? a : b;
}

int minYS[ 50000 ];
int maxYS[ 50000 ];
int maxYU[ 50000 ];
int minYU[ 50000 ];
int minY[ 50000 ];
int maxY[ 50000 ];
int cminy[ 50000 ];
int cmaxy[ 50000 ];

int sub_solve( int a)
{
	int area;
	int nowx, now_miny, now_maxy;
	int minYL[ 50000 ];
	int maxYL[ 50000 ];
	int i, j;
	int prevx, prevy;

	for( i = 0; i < w; i++ )
	{
		minYL[ i ] = minYU[ i ];
		maxYL[ i ] = maxYU[ i ];
	}

	prevx = maxY[ a ];
	prevy = minY[ a ];

	maxY[ a ] = h; 
	minY[ a ] = 0;

	for( i = 0; i <= a; i++ )
	{
		minYL[ i ] = 0;
		maxYL[ i ] = h;
	}

	nowx = 0;
	now_miny = 0;
	now_maxy = 0;

	for ( i = 0; i < w; i++ )
	{
		if ( maxY[ i ] != -1 )
		{
			nowx = i;
			now_miny = minY[ i ];
			now_maxy = maxY[ i ];
			break;
		}
	}

	for( i = nowx; i < w; i++ )
	{
		if ( maxY[ i ] > now_maxy )
		{
			now_maxy = maxY[ i ];
		} else
		{
			if ( maxYL[ i ] < now_maxy )
			{
				now_maxy = maxYL[ i ];
			}
		}

		if ( minY[ i ] < now_miny )
		{
			now_miny = minY[ i ];
		} else
		{
			if ( minYL[ i ] > now_miny )
			{
				now_miny = minYL[ i ];
			}
		}

		cmaxy[ i ] = now_maxy;
		cminy[ i ] = now_miny;
	}

	area = 0;
	for( i = nowx; i < w; i++ )
	{
		if( cminy[ i ] < cmaxy[ i ] )
			area += cmaxy[ i ] - cminy[ i ];

	}
	maxY[ a ] = prevx;
	minY[ a ] = prevy;
	return area;
}

int sub_solve2( int a)
{
	int area;
	int nowx, now_miny, now_maxy;
	int minYL[ 50000 ];
	int maxYL[ 50000 ];
	int i, j;

	for( i = 0; i < w; i++ )
	{
		minYS[ i ] = minY[ i ];
		maxYS[ i ] = maxY[ i ];
		minYL[ i ] = minYU[ i ];
		maxYL[ i ] = maxYU[ i ];
	}

	for( i = 0; i < w; i++ )
	{
		if( minYS[ i ] > a )
			minYS[ i ] = a;
		if( maxYS[ i ] < a + 1 )
			maxYS[ i ] = a + 1;
	}

	for( i = 0; i < w; i++ )
	{

		if ( minYU[ i ] > a ) 
			minYL[ i ] = a;
		if( maxYU[ i ] < a + 1 )
			maxYL[ i ] = a + 1;
	}

	nowx = 0;
	now_miny = 0;
	now_maxy = 0;

	for ( i = 0; i < w; i++ )
	{
		if ( maxYS[ i ] != -1 )
		{
			nowx = i;
			now_miny = minYS[ i ];
			now_maxy = maxYS[ i ];
			break;
		}
	}

	for( i = nowx; i < w; i++ )
	{
		if ( maxYS[ i ] > now_maxy )
		{
			now_maxy = maxYS[ i ];
		} else
		{
			if ( maxYL[ i ] < now_maxy )
			{
				now_maxy = maxYL[ i ];
			}
		}

		if ( minYS[ i ] < now_miny )
		{
			now_miny = minYS[ i ];
		} else
		{
			if ( minYL[ i ] > now_miny )
			{
				now_miny = minYL[ i ];
			}
		}

		cmaxy[ i ] = now_maxy;
		cminy[ i ] = now_miny;
	}

	area = 0;
	for( i = nowx; i < w; i++ )
	{
		if( cminy[ i ] < cmaxy[ i ] )
			area += cmaxy[ i ] - cminy[ i ];

	}

	return area;
}

void solve()
{
	int xx, yy;
	int i, j;
	int nowx, now_miny, now_maxy;
	int area;
	int result = 200000000;
	int ret;

	for( i = 0; i < w; i++ )
	{
		minY[ i ] = w + 1;
		maxY[ i ] = -1;
	}

	for( i = 0; i < n; i++ )
	{
		xx = x[ i ];
		yy = y[ i ];

		minY[ xx - 1 ] = MAX( MIN( minY[ xx - 1 ] , yy - 1 ), 0);
		minY[ xx ] = MAX( MIN( minY[ xx ] , yy - 1 ), 0 );

		maxY[ xx - 1 ] = MIN( MAX( maxY[ xx - 1 ] , yy + 1 ), h);
		maxY[ xx  ] = MIN( MAX( maxY[ xx ] , yy + 1 ), h );
	}
	nowx = 0;
	now_miny = 0;
	now_maxy = 0;

	for ( i = 0; i < w; i++ )
	{
		if ( maxY[ i ] != -1 )
		{
			nowx = i;
			now_miny = minY[ i ];
			now_maxy = maxY[ i ];
			break;
		}
	}

	for( i = 0; i <w; i++ )
	{
		maxYU[ i ] = -1;
		minYU[ i ] = h;
		for( j = i; j < w;j++ )
		{
			maxYU[ i ] = MAX( maxYU[ i ] , maxY[ j ] );
			minYU[ i ] = MIN( minYU[ i ], minY[ j ] );
		}
		
	}

	for( i = nowx; i < w; i++ )
	{
		if ( maxY[ i ] > now_maxy )
		{
			now_maxy = maxY[ i ];
		} else
		{
			if ( maxYU[ i ] < now_maxy )
			{
				now_maxy = maxYU[ i ];
			}
		}

		if ( minY[ i ] < now_miny )
		{
			now_miny = minY[ i ];
		} else
		{
			if ( minYU[ i ] > now_miny )
			{
				now_miny = minYU[ i ];
			}
		}

		cmaxy[ i ] = now_maxy;
		cminy[ i ] = now_miny;
	}

	for( i = 0; i < w; i++ )
	{
		ret = sub_solve( i );
		if ( result > ret )
			result = ret;
	}

	for( i = 0; i < h; i++ )
	{
		ret= sub_solve2(i );
		if( result > ret )
			result = ret;
	}
	cout << result << endl;
}

int main()
{
	int nT;
	//ifstream fin("input.txt");

	cin >> nT;

	while( nT-- )
	{
		cin >> w >> h;
		cin >> n;

		for( int i = 0; i < n; i++ )
		{
			cin >> x[ i ] >> y[ i ];
		}
		solve();
	}
	return 0;

}