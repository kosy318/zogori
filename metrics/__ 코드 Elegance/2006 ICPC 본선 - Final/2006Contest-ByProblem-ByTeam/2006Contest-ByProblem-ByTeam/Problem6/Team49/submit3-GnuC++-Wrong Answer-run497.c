// az_a.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

int main(void)
{
	int T, t;
	int N, n;
	int count[20];
	int num[20][2];
	int sumMulti;
	int z;
	int reSum;

	scanf("%d", &T);

	for(t = 0; t < T; t++)
	{
		scanf("%d", &N);
		sumMulti = 1;
		for(n = 0; n < N; n++)
		{
			scanf("%d %d", &num[n][0], &num[n][1]);
			sumMulti *= num[n][0];
		}
		scanf("%d", &z);
		z *= sumMulti;
		reSum = 0;
		for(n = 0; n < N; n++)
		{
			num[n][0] = sumMulti / num[n][0];
			reSum += num[n][0];
			//num[n][1] = num[n][1] * num[n][0];
			z += num[n][1] * num[n][0];
		}

		if (z % reSum) 
		{
			printf("0\n");
		}
		else
		{
			printf("%d\n", z / reSum);
		}
		
	}

	return 0;
}

