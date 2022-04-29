#include<stdio.h>

int coor[1001][2];

int main()
{
	int T, n;
	int i, j;
	double min, temp;
	double r;
	double b;
	double t2;
	int ind;
	int b1, b2;

	int ci;
	double ch;
	double cr, cb;

	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for( i=0 ; i<n ; i++ )
		{
			scanf("%d%d", &coor[i][0], &coor[i][1]);
		}

		min = 10000.0;
		b1 = coor[0][0];
		b2 = coor[n-1][0];
		
		ci = 0;
		for( i=b1 ; i<=b2 ; i++ )
		{
			while( ci+1<n && coor[ci+1][0] <= i ) {
				ci++;
			}
			cr = (double)(coor[ci+1][1]-coor[ci][1])/(coor[ci+1][0]-coor[ci][0]);
			cb = coor[ci][1] - cr*coor[ci][0];
			ch = cr*i + cb;

			temp = 0.0;
			for( j=0 ; j<n-1 ; j++ )
			{
				r = (double)(coor[j+1][1]-coor[j][1])/(coor[j+1][0]-coor[j][0]);
				b = coor[j][1] - r*coor[j][0];

				t2 = r*i + b;

				if( ch + temp < t2) {
					temp = t2 - ch;
				}
			}

			if( temp < min )
			{
				min = temp;
				ind = i;
			}
		}
		if( min >= 1000.0 )
			printf("IMPOSSIBLE\n");
		else
		{
			printf("%.1f\n", min);
			//printf("index : %d\n", ind);
		}
	}
	return 0;
}
