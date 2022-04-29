#include <stdio.h>

int value[100][2];
int divide[100];
int num;

int isDivided( void ){

	int i;

	for( i = 0 ; i < num ; i++ )
	       if( divide[i] != 1 )
	       		return 0;
	return 1;	

}

int main()
{
	int test;
	int mul;
	int min;
	int i;
	unsigned long a, b, z, m;

	scanf("%d", &test);

	while(test--)
	{
		scanf("%d", &num);
		
		for(i = 0; i < num; i++){
			scanf("%d %d", &value[i][0], &value[i][1]);
			divide[i] = value[i][0];
		}
		scanf("%d", &m);

/*
		for(i = 0; i < num; i++
			printf("%d %d\n", value[i][0], value[i][1]);
*/				

		mul = 1;
		while( !isDivided() ){
			for( i = 0, min = 11 ; i < num ; i++ )
				if( divide[i] != 1 && min > divide[i] )
					min = divide[i];	
			for( i = 0 ; i < num ; i++ )
				if( divide[i] % min == 0 )
					divide[i] /= min;
			mul *= min;
		}
		
		m *= mul;

		z = 0;
		for(i = 0; i < num; i++)
			z += (mul / value[i][0]);

		
		b = 0;	
		for(i = 0; i < num ; i++)
			b += value[i][1] * ( mul / value[i][0]);

		if(((m + b) % z) != 0)
			printf("0\n");
		else
			printf("%d\n", (m + b) / z); 

	}
}
