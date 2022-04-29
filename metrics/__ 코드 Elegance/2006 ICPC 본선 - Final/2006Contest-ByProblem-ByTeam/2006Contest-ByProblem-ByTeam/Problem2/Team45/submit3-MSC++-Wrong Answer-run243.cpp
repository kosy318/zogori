#include <stdio.h>
#include <stdlib.h>

int main()
{
	int test_case;
	int num, length, conerr, A, T, G, C, max;
	int i, j, k;
	char dna[50][1000], constr[1000];
	
	scanf("%d",&test_case);

	for(i=0; i<test_case; i++)
	{
		conerr = 0;
		scanf("%d %d", &num, &length);

		for(j=0; j<num; j++)
		{
			scanf("%s", dna[j]);
		}

		for(j=0; j<length; j++)
		{
			A = 0;
			T = 0;
			G = 0;
			C = 0;
			max = 0;
			for(k=0; k<num; k++)
			{
				if(dna[k][j] == 'A')	A++;
				if(dna[k][j] == 'T')	T++;
				if(dna[k][j] == 'G')	G++;
				if(dna[k][j] == 'C')	C++;
			}

			if(A > max)		max = A;
			if(T > max)		max = T;
			if(G > max)		max = G;
			if(C > max)		max = C;

			if(max == C)	constr[j] = 'C';
			if(max == G)	constr[j] = 'G';
			if(max == T)	constr[j] = 'T';
			if(max == A)	constr[j] = 'A';			

			conerr = conerr + num - max;
		}
		constr[j] = '\0';
		printf("%s\n%d\n", constr, conerr);
	}

	return 0;
}