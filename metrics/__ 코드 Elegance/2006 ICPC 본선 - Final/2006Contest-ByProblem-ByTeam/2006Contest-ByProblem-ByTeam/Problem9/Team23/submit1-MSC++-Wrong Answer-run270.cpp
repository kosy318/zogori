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

	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for( i=0 ; i<n ; i++ )
		{
			scanf("%d%d", &coor[i][0], &coor[i][1]);
		}

		min = 10000.0;
		
		for( i=0 ; i<n ; i++ )
		{
			temp = 0.0;
			for( j=0 ; j<n-1 ; j++ )
			{
				r = (double)(coor[j+1][1]-coor[j][1])/(coor[j+1][0]-coor[j][0]);
				b = coor[j][1] - r*coor[j][0];

				t2 = r*coor[i][0] + b;
				if( coor[i][1] + temp < t2) {
					temp = t2 - coor[i][1];
				}
			}
			if( temp > 1000 )
				continue;
			if( temp < min )
			{
				min = temp;
				ind = i;
			}
		}
		if( min > 1000.0 )
			printf("IMPOSSIBLE\n");
		else
		{
			printf("%.1f\n", min);
			//printf("index : %d\n", ind);
		}
	}
	return 0;
}
