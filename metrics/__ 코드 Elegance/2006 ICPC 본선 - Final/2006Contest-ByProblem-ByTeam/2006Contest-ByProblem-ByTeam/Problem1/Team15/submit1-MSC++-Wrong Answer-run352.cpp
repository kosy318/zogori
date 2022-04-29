#include<stdio.h>
#include<stdlib.h>
void main()
{
	int n;
	char arStart[9],arEnd[9];
	char brStart[6],brEnd[6];
	scanf("%d",&n);
	int end  = 0;
	int start = 0;
	for(int i=0; i<n;i++)
	{
		int count =0;
		scanf("%s",arStart);
		
		scanf("%s",arEnd);

		brStart[0] = arStart[0];
		brStart[1] = arStart[1];
		brStart[2] = arStart[3];
		brStart[3] = arStart[4];
		brStart[4] = arStart[6];
		brStart[5] = arStart[7];

		brEnd[0] = arEnd[0];
		brEnd[1] = arEnd[1];
		brEnd[2] = arEnd[3];
		brEnd[3] = arEnd[4];
		brEnd[4] = arEnd[6];
		brEnd[5] = arEnd[7];

		//printf("%d", atoi(brStart));
		//printf("%d\n", atoi(brStart));
		//printf("%d\n", atoi(brEnd));

		//start = arStart[0] * 100000 + arStart[1] * 10000 + arStart[3] *  1000+ arStart[4] * 100 + arStart[6] * 10+ arStart[7];
		//end = arEnd[0] * 100000 + arEnd[1] * 10000 + arEnd[3] *  1000+ arEnd[4] * 100 + arEnd[6] * 10+ arEnd[7];
		start = atoi(brStart);
		end = atoi(brEnd);
		if(start > end )
		{
			end = end + 120000;
			start = start - 120000;
		}
		while(true)
		{
			if(start % 3 == 0) 
				count++;
			start ++;
			if(start % 100 == 60)
			{
				start = start + 100;
				start = start /100;
				start = start * 100;
			}
			if(start % 10000 /100 == 60)
			{
				start = start + 10000;
				start = start /10000;
				start = start * 10000;
			}
			if(start % 100000  / 10000 == 4)
			{
				start = start + 100000;
				start = start /100000;
				start = start * 100000;
			}
			if(start >= end)
			{
				if(start % 3 == 0)
					count ++;
				break;
			}
			//printf("%d\n",start);
		}
		printf("%d\n",count);
	}

}