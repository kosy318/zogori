#include <stdio.h>

int main()
{
	int test;
	int num;
	int i;
	int a, b, z, m;
	int value[100][2];

	scanf("%d", &test);

	while(test--)
	{
		scanf("%d", &num);
		
		for(i = 0; i < num; i++)
			scanf("%d %d", &value[i][0], &value[i][1]);

		scanf("%d", &m);

/*
		for(i = 0; i < num; i++
			printf("%d %d\n", value[i][0], value[i][1]);
*/				

		a = 1 ;
		for(i = 0; i < num; i++)
			a *= value[i][0];
		
		m *= a;

		z = 0;
		for(i = 0; i < num; i++)
			z += (a / value[i][0]);

		
		b = 0;	
		for(i = 0; i < num ; i++)
			b += value[i][1] * ( a / value[i][0]);

		if(((m + b) % z) != 0)
			printf("0\n");
		else
			printf("%d\n", (m + b) / z); 

	}
}
