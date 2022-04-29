#include <stdio.h>
#include <stdlib.h>


int cmp(const void *vp, const void *vq)
{
	const char *p = vp;
	const char *q = vq;
	int diff = *p - *q;

	return ((diff >= 0) ? ((diff > 0) ? -1 : 0) : +1);
}

int main()
{
	int caseNum, m, n, max, result;
	int a, t, g, c;
	int i, j, k;
	char dna[1001][51], maxCh;
	scanf("%d", &caseNum);

	for(i = 0; i < caseNum; i++)
	{
		scanf("%d %d\n", &m, &n);

		for(j = 0; j < m; j++)
		{
			for(k = 0; k < n; k++)
			{
				scanf("%c", &dna[k][j]);
			}
			getchar();
		}

		result = 0;
		for(j = 0; j < n; j++)
		{
			a = t = g = c = 0;
		
			for(k = 0; k < m; k++)
			{
				switch(dna[j][k]){
				case 'A':
					a++;	break;
				case 'T':
					t++;	break;
				case 'G':
					g++;	break;
				case 'C':
					c++;	break;
				}
			}

			max = t;	maxCh = 'T';
			if ( max < g ){
				max = g;	maxCh = 'G';
			}
			if ( max < c ){
				max = c;	maxCh = 'C';
			}
			if ( max < a ){
				max = a;	maxCh = 'A';
			}

			printf("%c", maxCh);
			for(k = 0; k < m; k++)
			{
				if(dna[j][k] != maxCh)
					result++;
			}
			
		}
		printf("\n%d\n", result);

	}

	return 0;
}