# include <cstdio>

# define maxn 1005
# define maxm 55
# define maxt 55
# define FOR( I,A,B ) for( (I)=(A) ; (I)<=(B) ; (I)++ )
int T, n[maxt], m[maxt];
char gene[maxt][maxm][maxn];
char result[maxt][maxn];
int sum[maxt];

void input()
{
	int i, j;

	scanf( "%d", &T );

	FOR( i, 1 , T )
	{
		scanf( "%d %d", &n[i] ,&m[i] );

		FOR( j, 1, n[i] )
			scanf( "%s", gene[i][j] );
	}
}

void process()
{
	int i, j, k, maxi;

	char GENE[4]={'A','C','G','T' };

	FOR( i , 1, T )
	{
		FOR( j, 0, m[i]-1 )
		{
			int cnt[5] = {0};
			FOR( k, 1, n[i] )
			{
				if( gene[i][k][j] == 'A' )
					cnt[ 0 ]++;
				else if( gene[i][k][j] =='C' )
					cnt[1]++;
				else if( gene[i][k][j] =='G' )
					cnt[2]++;
				else
					cnt[3]++;
			}

			maxi = 0;
			FOR( k, 1, 3 )
				if( cnt[ maxi ] < cnt[k] )
					maxi = k;

			result[i][j] = GENE[ maxi ];
			sum[i] += n[i] - cnt[maxi];
		}
	}
}

	void output()
	{
		int i;
		FOR( i, 1, T )
		{
			printf( "%s\n%d\n", result[i],sum[i] );
		}
	}

	void main()
	{
		input();

		process();

		output();
	}