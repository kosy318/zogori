#include <stdio.h>
#include <stdlib.h>

int main()
{
	int test_case, ptNum;
	float towH, tmpH, degree, b, min;
	int i, j, k;
	float point[1000][2];
	
	scanf("%d",&test_case);

	for(i=0; i<test_case; i++)
	{
		
		min = 1000.0;

		scanf("%d", &ptNum);

		for(j=0; j<ptNum; j++)
		{
			scanf("%f %f", &point[j][0], &point[j][1]);
		}

		for(j=0; j<ptNum; j++)
		{
			towH = tmpH = 0.0;
			for(k=0; k<ptNum-1; k++)
			{
				degree = (point[k+1][1] - point[k][1]) / (point[k+1][0] - point[k][0]);
				b = point[k][1] - degree * point[k][0];
				
				tmpH = degree * point[j][0] + b;
				tmpH = tmpH - point[j][1];
				if(tmpH > 0 && tmpH > towH)
				{ 
					printf("maximum : %d %f\n", k, tmpH);
					towH = tmpH;
				}
			}
			if(min > towH){
				min = towH;
				printf("minimum : %d %f\n", j, min);
			}
		}
		if(min >= 1000.0)	printf("IMPOSSIBLE\n");
		else				printf("%.1f\n", min);
		
	}

	return 0;
}