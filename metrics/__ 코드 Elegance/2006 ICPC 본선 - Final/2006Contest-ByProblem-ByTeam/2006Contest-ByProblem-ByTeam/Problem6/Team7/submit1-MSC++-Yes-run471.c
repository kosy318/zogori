#include <stdio.h>
#include <stdlib.h>

#define MAX 21

typedef struct gas
{
	int a, b; 
} Gas; 

int n; 
Gas g[MAX]; 
int M; 

int compare(Gas *x, Gas *y)
{
	if (x->a == y->a) 
		return x->b < y->b ? 1 : -1; 
	return x->a < y->a ? 1 : -1; 
}
int answer()
{
	int x[MAX]; 
	int y; 
	int i, j; 
	int sum; 

	for(i=1; i <= M; i++)
	{		
		y = g[0].a*i + g[0].b; 		
		x[0] = i; 
		//printf("%d %d\n", y, x[0]); 

		sum = 0; 
		sum += x[0]; 
		for(j=1; j < n; j++)
		{
			if ((y-g[j].b) % g[j].a != 0)
				break; 
			x[j] = (y-g[j].b) / g[j].a; 
			sum += x[j]; 
		}
		if (j == n)
			if (sum == M)
				return y; 
	}
	return 0; 
}
int main(void)
{
	int T; 
	int i, j; 


	scanf("%d", &T); 
	for(i=0; i < T; i++)
	{
		scanf("%d", &n); 
		for(j=0; j < n; j++)
		{
			scanf("%d%d", &g[j].a, &g[j].b); 
			//printf("%d %d\n", g[j].a, g[j].b); 
		}
		scanf("%d", &M); 
		qsort(g, n, sizeof(Gas), compare); 
		
		
		printf("%d\n", answer()); 
	}


	return 0; 
}