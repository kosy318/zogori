#include <stdio.h>
#include <string.h>

int main()
{
	char DNA[50][1000], cmpstr[1000];
	int test_cnt, num_dna, loop, i, j, k = 0;
	int A = 0, T = 0, G = 0, C = 0, dis = 0, idx = 0;

	scanf("%d", &test_cnt);

	while(test_cnt)
	{
		scanf("%d %d", &loop, &num_dna);

		for(i=0; i<loop; i++)
		{
			scanf("%s", DNA[i]);
		}

		num_dna = strlen(DNA[idx]);
		idx++;

		for(i=0; i<num_dna; i++)
		{
			for(j=0; j<loop; j++)
			{
				switch(DNA[j][i])
				{
				case 'A':
					A++;
					break;
				case 'T':
					T++;
					break;
				case 'G':
					G++;
					break;
				case 'C':
					C++;
					break;
				}
			}

			if( A > T && A > C && A > G )
				cmpstr[k] = 'A';
			else if( T > A && T > C && T > G )
				cmpstr[k] = 'T';
			else if( C > T && C > A && C > G )
				cmpstr[k] = 'C';
			else if( G > T && G > C && G > A )
				cmpstr[k] = 'G';
			else if( A == C || A == T || A == G )
				cmpstr[k] = 'A';
			else if( C == T || C == G )
				cmpstr[k] = 'C';
			else if( G == T )
				cmpstr[k] = 'G';
			else
				cmpstr[k] = 'T';

			A = 0;
			C = 0;
			G = 0;
			T = 0;
			k++;
		}

		k = 0;

		for(i=0; i<loop; i++)
		{
			for(j=0; j<num_dna; j++)
			{
				if(DNA[i][j] != cmpstr[k])
					dis++;
				k++;
			}
			k = 0;
		}

		cmpstr[num_dna] = '\0';
		printf("%s\n", cmpstr);
		printf("%d\n", dis);
		dis = 0;
		idx = 0;
		k = 0;
		test_cnt--;
	}
	return 0;
}
