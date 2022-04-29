#include <stdio.h>

int Arr[30][2];
int num[30];

int getGCD(int i, int j);
int getLLL(int i, int j );

void main()
{
	int i, j, k;
	int n;
	int cc;
	int result;

	int constan;

	scanf("%d", &n);

	while(n--)
	{
		constan = 0;
		scanf("%d", &cc);
		int sum = 0;

		for( i = 0 ; i < cc ; i++ )
		{
			scanf("%d %d", &Arr[i][0], &Arr[i][1]);
		}

		scanf("%d", &result);

		int total = getLLL(Arr[0][0], Arr[1][0]);

		for( i = 2 ; i < cc ; i++ )
		{
			total = getLLL(total, Arr[i][0]);
		}

		for( i = 0 ; i < cc ; i++ )
		{
			num[i] = total / Arr[i][0];
		}

		for( i = 0 ; i < cc ; i++ )
		{
			sum += num[i];
			constan += Arr[i][1] * num[i] ;
		}

		constan += ( result * total );

		if( constan % sum == 0 )
            printf("%d\n", constan / sum);
		else
			printf("%d\n", 0);		

	}
}





int getGCD(int i, int j)
{
	while( i != 0 && j != 0 )
	{
		if( i > j )
			i = i % j;
		else
			j = j % i;
	}	

	return i ? i : j;
}

int getLLL(int i, int j )
{
	int ggg = getGCD(i, j);

	return i * j / ggg;
}