#include <stdio.h>

int main()
{
	int test_cnt, num, i, j, sol = 0;
	int x[20], d[20], result[20];
	int assign, max, sum = 0;

	scanf("%d", &test_cnt);

	while(test_cnt)
	{
		scanf("%d", &num);

		for(i=0; i<num; i++)
		{
			scanf("%d %d", &x[i], &d[i]);
		}

		getchar();
		scanf("%d", &assign);
		
		max = d[0];

		for(i=0; i<num; i++)
		{
			if( d[i] > max )
				max = d[i];
		}

		for(i=max; i<=assign; i++)
		{
			for(j=0; j<num; j++)
			{
				result[j] = (i - d[j])/x[j];
			}
			
			for(j=0; j<num; j++)
			{
				sum += result[j];
			}

			if( sum == assign ) 
			{
				sol = i;
				break;
			}

			sum = 0;
		}
		printf("%d\n", sol);
		test_cnt--;
		sol = 0;
		sum = 0;
	}
	return 0;
}
