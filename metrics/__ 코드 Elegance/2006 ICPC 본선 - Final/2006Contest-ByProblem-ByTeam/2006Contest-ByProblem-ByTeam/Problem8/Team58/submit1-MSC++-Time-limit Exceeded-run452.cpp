#include <stdio.h>
#include <string.h>

int t, c, sol, i, j;
int nA, nB;
char A[5024];
char B[5024];
int min[5024];
int d2[5024][100];
int Max(int a, int b)
{
	if ( a> b)
		return a;
	else
		return b;
}

int dynamic(char *a, char *b, int nA, int nB)
{
	int i, j;
	//i==0
	for ( j = 0 ; j < nB ; j++ )
	{
		if ( a[0] == b[j] )
		{
			d2[0][j] = j;
		} else
		{
			d2[0][j] = j + 1;
		}
	}
	//j==0
	for ( i = 0 ; i < nA ; i++ )
	{
		if ( a[i] == b[0] )
		{
			d2[i][0] = i;
		} else
		{
			d2[i][0] = i + 1;
		}
	}
	for ( i = 1 ; i < nA; i++ )
	{
		for ( j = 1 ; j < nB ; j++ )
		{
            if ( a[i] == b[j] )
			{
				d2[i][j] = d2[i-1][j-1];
			}
			else
			{
				d2[i][j] = d2[i-1][j-1] + 1;
			}

			if ( d2[i][j] > d2[i-1][j] + 1 )
			{
				d2[i][j] = d2[i-1][j] + 1;
			}
			if ( d2[i][j] > d2[i][j-1] + 1 )
			{
				d2[i][j] = d2[i][j-1] + 1;
			}
		}
	}
	return d2[nA-1][nB-1];
}


int main()
{
	int c, sum, k;
	scanf("%d",&t);
	for ( c = 0 ; c < t ; c++ )
	{
		scanf("%s", A);
		scanf("%s", B);

		nA = strlen( A );
		nB = strlen( B );

		for ( j = 0 ; j < nB ; j++ )
		{
			min[j] = 1000000;
            for ( i = 0 ; i <= j ; i++ )
			{
				if ( i == 0 )
					k = dynamic( B+i, A, j - i + 1, nA );
				else
					k = Max(min[i-1], dynamic( B+i, A, j - i + 1, nA ));
				if ( min[j] > k )
					min[j] = k;
			}
		}
		sol = min[nB-1];
		printf("%d\n",sol);
	}
	return 0;
}
