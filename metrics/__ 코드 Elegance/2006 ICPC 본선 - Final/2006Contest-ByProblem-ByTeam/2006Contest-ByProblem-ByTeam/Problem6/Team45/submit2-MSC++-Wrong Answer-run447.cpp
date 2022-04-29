#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int test_case;
	int i,j,k;
	int num_equ, a[20],b[20];
	int answer, M,temp,temp2;
	


	scanf("%d",&test_case);

	for(i=0; i<test_case ; i++)
	{
		answer=0;
		scanf("%d",&num_equ);
		for(j=0; j<num_equ; j++)
		{
			scanf("%d %d",&a[j],&b[j]);
		}
		scanf("%d",&M);
        
		temp=1;
		for(j=0; j<num_equ ; j++)
		{
			temp *= a[j];
		}
		answer += M * temp;

		// bun ja
		temp2=1;
		for(j=0; j<num_equ ; j++)
		{
			temp2=1;
			for(k=0; k<num_equ;  k++)
			{
				if( j==k ) 
					temp2 *= b[j];
				else
					temp2 *= a[k];
			}
			answer += temp2;
		}

		// bun mo
		temp=0 ;
		for(j=0; j<num_equ ; j++)
		{
			temp2 = 1 ;
			for(k=0;k<num_equ; k++)
			{
				if( j != k ) 
					temp2 *= a[k];
			}
			temp += temp2;
		}

		if( answer %temp ==0)
			printf("%d\n",(int)(answer / temp));
		else
			printf("0\n");
	}
	return 0;
}
