#include <stdio.h>
#include <stdlib.h>

#define MAX 1001

typedef struct 
{
	int d; 
	char c; 
} D; 

char dna[MAX][MAX];	//input
int n, m;			//input

int compare(D *x, D *y)
{
	if (x->d == y->d)
		return x->c > y->c ? 1 : -1; 
	return x->d < y->d ? 1 : -1; 
}

void error()
{	
	int i, j; 
	D d[4]; 
	int e = 0; 
	char answer[MAX]; 


	for(i=0; i < n; i++)
	{
		d[0].d = 0; d[1].d = 0; d[2].d = 0; d[3].d = 0; 
		d[0].c = 'A'; d[1].c = 'C'; d[2].c = 'G'; d[3].c = 'T'; 

		for(j=0; j < m; j++) 
		{
			//printf("%c\n", dna[j][i]); 
			if (dna[j][i] == 'A')
				d[0].d++; 
			if (dna[j][i] == 'C')
				d[1].d++; 
			if (dna[j][i] == 'G')
				d[2].d++; 
			if (dna[j][i] == 'T')
				d[3].d++; 
		}
		//printf("%d %d %d %d\n", d[0].d, d[1].d, d[2].d, d[3].d); 
		qsort(d, 4, sizeof(D), compare); 
		//printf("%d %d %d %d\n", d[0].d, d[1].d, d[2].d, d[3].d); 
		//printf("%c\n", d[0].c);
		answer[i] = d[0].c;
		e += (m - d[0].d);
	}
	answer[i] = '\0';
	printf("%s\n%d\n", answer, e); 
}
int main(void)
{
	int T; 
	int i, j; 

	scanf("%d", &T); 
	//printf("%d\n", T); 
	for(i=0; i < T; i++)
	{
		scanf("%d%d", &m, &n); 
		//printf("%d %d\n", m, n); 

		for(j=0; j < m; j++)
		{
			scanf("%s\n", dna[j]); 
			//printf("%s\n", dna[j]); 
		}
		error();
	}
	return 0; 
}