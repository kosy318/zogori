#include <stdio.h>

void main()
{
	int num[20+1][2];
	int cnt, n, T, M;
	bool checker;
	bool checker1;
	scanf("%d", &T);
	int i, j;
	for(int t = 1; t <= T; t++)
	{
		scanf("%d", &n);
		for( i = 1; i <= n; i++)
		{
			scanf("%d%d", &num[i][0], &num[i][1]);
		}
		scanf("%d", &M);
		checker1 = 0;
		for( i = 1; i <= 102000; i++)
		{
			checker = 0;
			cnt = 0;
			for( j = 1; j <= n; j++)
			{	
				if( i-num[j][1] > 0 ){
					if( (i-num[j][1]) % num[j][0] != 0  ){
						checker = 1;
						break;
					}
					else{
						cnt += (i-num[j][1])/num[j][0];
					}
				}
				else break;
			}
			if( !checker )
			{
				if( cnt == M )
				{
					printf("%d\n", i);
					checker1 = 1;
					break;
				}
			}
		}
		if( !checker1 )
		{
			printf("0\n");
		}
	}
}