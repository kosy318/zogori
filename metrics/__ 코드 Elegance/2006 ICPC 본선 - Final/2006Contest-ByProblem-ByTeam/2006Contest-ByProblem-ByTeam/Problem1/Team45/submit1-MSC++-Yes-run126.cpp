#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>



int main()
{
	int test_case;
	int i,j;
	int dTime1[3],dTime2[3],count,num1,num2;
	char time1[20],time2[20];

	scanf("%d",&test_case);

	for(i=0; i<test_case; i++)
	{
		count= 0 ;
		scanf("%s %s",time1,time2);
		
		dTime1[2]= atoi(&time1[6]);
		time1[5]=0;
		dTime1[1]= atoi(&time1[3]);
		time1[2]=0;
		dTime1[0]= atoi(&time1[0]);
		
		dTime2[2]= atoi(&time2[6]);
		time2[5]=0;
		dTime2[1]= atoi(&time2[3]);
		time2[2]=0;
		dTime2[0]= atoi(&time2[0]);

		num2 = dTime2[0]*10000 + dTime2[1]*100 + dTime2[2];
		while(true)
		{
			num1 = dTime1[0]*10000 + dTime1[1]*100 + dTime1[2];
			if( num1%3 == 0 )
				count ++;
       //   printf("%d, %d\n",num1, num2);

		//	dTime1[0]++;
		//	dTime1[1]++;
			dTime1[2]++;
				
			if( dTime1[2] == 60)
			{
				dTime1[1]++;
				dTime1[2]=0;
			}

			if( dTime1[1] == 60) 
			{
				dTime1[0]++;
				dTime1[1]=0;
			}

			if( dTime1[0] == 24) dTime1[0]=00;

			
			if( num2 == num1 ) break;
		}

	     

		
		printf("%d\n",count);
	}
    

	return 0;
}