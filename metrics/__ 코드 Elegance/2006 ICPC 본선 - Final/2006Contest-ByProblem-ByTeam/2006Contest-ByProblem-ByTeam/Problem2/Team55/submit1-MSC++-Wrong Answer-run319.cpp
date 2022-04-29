#include <stdio.h>
#include <stdlib.h>

#define MIN_Y		4
#define	MAX_Y		50

#define	MIN_X		4
#define MAX_X		1000

#define DNA_A	0
#define DNA_C	1
#define DNA_G	2
#define DNA_T	3


char g_data[MAX_Y][MAX_X];
char g_dna[4];

void Process()
{
	int dataX, dataY;
	int differentCount= 0;
	int x, y, i;

	int count[4];
	char result[MAX_Y];

	scanf("%d %d", &dataY, &dataX);

	for(y = 0; y < dataY; ++y)
			scanf("%s", g_data[y]);

	for(x = 0; x < dataX; ++x)
	{
		count[0] = 0; count [1] = 0; count[2] =0; count[3] =0;
		for(y = 0; y < dataY; ++y)
		{	
			switch(g_data[y][x])
			{
			case 'T':
				++count[DNA_T]; 
				break;
			case 'A':
				++count[DNA_A];
				break;
			case 'G':
				++count[DNA_G];
				break;
			case 'C':
				++count[DNA_C];
				break;
			}
		}
		int min = 0;
		int max = 0;

		for(i = 0; i < 4; ++i)
		{
			if(count[i] > count[max])
				max = i;
		}
		result[x] = g_dna[max];
		printf("%c",result[x]);

		for(y = 0; y < dataY; ++y)
		{
			if(g_data[y][x] != result[x])
				++differentCount;
		}	
	}
	printf("\n%d\n",differentCount);
}


void main()
{
	int nNTC;
	int i;
	g_dna[DNA_G] = 'G';
	g_dna[DNA_A] = 'A';
	g_dna[DNA_C] = 'C';
	g_dna[DNA_T] = 'T';

	scanf("%d", &nNTC);

	for(i = 0; i < nNTC; ++i)
	{
		Process();
	}
}
