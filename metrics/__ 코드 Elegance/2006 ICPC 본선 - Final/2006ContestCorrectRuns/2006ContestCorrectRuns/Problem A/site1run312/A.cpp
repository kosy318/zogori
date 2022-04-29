#include<stdio.h>

int number[240001];

void main()
{
	int h1, m1, s1;
	int h2, m2, s2;
	int i, j, k;

	int n;

	for( i = 0 ; i < 24 ; i++ )
	{
		for( j = 0 ; j < 60 ; j++ )
		{
			for( k = 0 ; k < 60 ; k++ )
			{
				int temp = i * 10000 + j * 100 + k;

				if( temp % 3 == 0 )
					number[temp] = 1;
			}
		}
	}

	for( i = 1 ; i < 240001 ; i++ )
		number[i] += number[i-1]; 

	scanf("%d", &n);
	
	while(n--)
	{
		scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);

		int t1 = h1 * 10000 + m1 * 100 + s1;
		int t2 = h2 * 10000 + m2 * 100 + s2;

		if( t1 > t2 )
		{
			printf("%d\n", number[t2] + ( number[240000] - number[t1-1] ));			
		}
		else
			printf("%d\n", number[t2] - number[t1-1]);
	}
}


