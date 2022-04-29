// AAA.cpp : Defines the entry point for the console application.
//

#include <stdio.h>


int main(void)
{
	int T, t;
	int M, m;
	int N, n;
	char str[50][1000];
	char result[1000];
	int wCount;
	
	int tempMax;
	int tempMaxIndex;
	int count[4];
	

	scanf("%d", &T);

	for(t = 0; t < T; t++)
	{
		scanf("%d %d", &M, &N);
		for(m = 0; m < M; m++)
		{
			scanf("%s", str[m]);	
		}
		//printf("%s", str[m]);	
		
		// init
		wCount = 0;
		
		//gbogo
		for( n = 0 ; n < N ; n++)
		{
			for (m=0; m<4; m++)
			{
				count[m] = 0;
			}
			for( m = 0 ; m < M ; m++)
			{
				switch (str[m][n])
				{
				case 'A':
					count[0]++;
					break;
				case 'C':
					count[1]++;
					break;
				case 'G':
					count[2]++;
					break;
				case 'T':
					count[3]++;
					break;
				}
			}
			
			tempMaxIndex = 0;
			tempMax = 0;
			for (m=0; m<4; m++)
			{
				if (tempMax < count[m])
				{
					tempMaxIndex = m;
					tempMax = count[m];
				}
			}

			switch (tempMaxIndex)
			{
			case 0:
                printf("%c", 'A');
				break;
			case 1:
                printf("%c", 'C');
				break;
			case 2:
                printf("%c", 'G');
				break;
			case 3:
                printf("%c", 'T');
				break;
			}
			wCount += M - tempMax;

		}
		printf("\n%d\n", wCount);
	}

	return 0;
}

