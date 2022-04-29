# include <cstdio>


# define FOR( I,A,B ) for( (I)=(A) ; (I)<=(B) ; (I)++ )
# define maxw 50005
# define maxn 1005

typedef struct point
{
	int x, y;
}point;

point p[maxn];
int w, h, n, T;
int minx[maxw], miny[maxw], maxx[maxw], maxy[maxw];
int result;


void input()
{
	int i;

	scanf( "%d %d", &w, &h );
	scanf( "%d", &n );

	FOR( i, 1, n )
		scanf( "%d %d", &p[i].x, &p[i].y );
}

void updateX( int x, int y )
{
	if( x<0 || y<0 )
		return;
	if( minx[y] == -1 || minx[y] > x )
		minx[y] = x;
	if( maxx[y] == -1 || maxx[y] < x )
		maxx[y] = x;
}

void updateY( int y, int x )
{
	if( x<0 || y<0 )
		return;
	if( miny[x] == -1 || miny[x] > y )
		miny[x] = y;
	if( maxy[x] == -1 || maxy[x] < y )
		maxy[x] = y;
}

void process()
{
	int i, j;
	int min, max, sum;

	FOR( i, 0, h-1 )
		minx[i] = maxx[i] = -1;
	FOR( i, 0, w-1 )
		miny[i] = maxy[i] = -1;

	FOR( i, 1, n )
	{
		updateX( p[i].x-1, p[i].y-1 );
		updateX( p[i].x, p[i].y-1 );
		updateX( p[i].x+1, p[i].y-1 );
		updateX( p[i].x-1, p[i].y );
		updateX( p[i].x, p[i].y );
		updateX( p[i].x+1, p[i].y );

		updateY( p[i].y-1, p[i].x-1 );
		updateY( p[i].y, p[i].x-1 );
		updateY( p[i].y+1, p[i].x-1 );
		updateY( p[i].y-1, p[i].x );
		updateY( p[i].y, p[i].x );
		updateY( p[i].y+1, p[i].x );
	}

	FOR( i, 0, h-1 )
	{
		if( i > 0 && i < h-1 )
			if( minx[i] < 0 && minx[i-1] < 0 && minx[i+1] < 0 )
			{
				continue;
			}

		sum = 0;

		min = minx[0];
		max = maxx[0];

		FOR( j, 0, i-1 )
		{
			if( minx[j]  >= 0 )
			{

			if( min > minx[j] || min == -1 )
				min = minx[j];
			if( max < maxx[j] || max == -1 )
				max = maxx[j];
			}
			sum += max - min;
		}

		sum += w;

		min = minx[h-1];
		max = maxx[h-1];
		for( j = h-1 ; j > i ; j-- )
		{
			if( minx[j]  >= 0 )
			{

			if( min > minx[j] || min == -1)
				min = minx[j];
			if( max < maxx[j] || max == -1 )
				max = maxx[j];
			}
			sum += max - min;
		}

		if( sum < result || result== 0 )
			result = sum;
	}

	FOR( i, 0, w-1 )
	{
		if( i > 0 && i < w-1 )
            if( miny[i] < 0 && miny[i-1] < 0 && miny[i+1] < 0 )
			{
				continue;
			}

		sum = 0;
		min = miny[0];
		max = maxy[0];

		FOR( j, 0, i-1 )
		{
			if( miny[j] >= 0 )
			{

			if( min > miny[j] || min == -1 )
				min = miny[j];
			if( max < maxy[j] || max == -1  )
				max = maxy[j];
			}
			sum += max - min;
		}

		sum += h;

		min = miny[w-1];
		max = maxy[w-1];
		for( j = w-1 ; j > i ; j-- )
		{
			if( miny[j] >= 0  )
			{
			if( min > miny[j] || min == -1 )
				min = miny[j];
			if( max < maxy[j] || max == -1  )
				max = maxy[j];
			}

			sum += max - min;
		}

		if( sum < result || result== 0 )
			result = sum;
	}
}

void main()
{
	int casecnt;

	scanf( "%d", &T );

	FOR( casecnt, 1, T )
	{
		input();

		result = 0;

		process();

		printf( "%d\n", result );
	}
}