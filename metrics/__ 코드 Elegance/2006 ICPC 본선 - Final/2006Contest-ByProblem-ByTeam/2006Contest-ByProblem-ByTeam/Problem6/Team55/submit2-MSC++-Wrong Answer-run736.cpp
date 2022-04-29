#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


#define MAX_DATA		20

typedef struct _data
{
	int a;
	int b;
}data;

data g_data[MAX_DATA];
int g_result[MAX_DATA];
int g_count[MAX_DATA];

void Process()
{
	int numberOfData;
	int dataC;
	int i, j;
	
	scanf("%d\n", &numberOfData);

	for(i = 0; i < numberOfData; ++i)
	{
		scanf("%d %d", &g_data[i].a, &g_data[i].b);
	}
	scanf("\n%d", &dataC);

	unsigned int min = 0xffffffff;
	int minPos = 0;

	for(i = 0; i < numberOfData; ++i)
		g_count[i] = 0;
	int totalCount = 0;

	while(1)
	{
		for(i = 0; i < numberOfData; ++i)
		{
			if(g_result[i] <= min )
				g_result[i] = g_data[i].a * g_count[i] + g_data[i].b;
			if (g_result[i] <= min)
			{
				min = g_result[i];
				minPos = i;
			}
		}
		for(i =0 ; i < numberOfData; ++i)
		{
			if (g_result[i] == min)
			{
				g_count[i]++;
				totalCount++;
			}

			if(totalCount -1 == dataC)
			{
				int eq = 0;
				if(i == 0)
				{
					eq = g_result[0];
					for(j =0 ; j < numberOfData; ++j)
					{
						if(eq != g_result[j])
							eq = 0;

					}	
				}
				printf("%d\n", eq);
				return ;
			}
				
		}
		min = g_result[0];
	}
}

void main()
{
	int nNTC;
	int i;

	scanf("%d", &nNTC);

	for(i = 0; i < nNTC; ++i)
	{
		Process();
	}
}
