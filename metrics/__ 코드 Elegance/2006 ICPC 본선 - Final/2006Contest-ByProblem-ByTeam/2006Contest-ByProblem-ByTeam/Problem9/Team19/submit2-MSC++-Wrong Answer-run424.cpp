#include <stdio.h>

struct point
{
	float x;
	float y;
};

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		int n;
		scanf("%d", &n);
		point points[1000];

		float result = 1000;

		for(int i = 0; i < n; i++)
		{
			scanf("%f %f", &points[i].x, &points[i].y);
		}

		for(int i = 0; i < n; i++)
		{
			float resultS = 0;
			for(int j = 0; j < n-1; j++)
			{
				float a = (points[j+1].y - points[j].y)/(points[j+1].x - points[j].x);

				if(i > j && a < 0) continue;
				if(i < j && a > 0) continue;

				float y = a*(points[i].x - points[j].x) + points[j].y;

				//printf("%d, %d, %.1f, %.1f,%.1f, %.1f ",i, j, a, points[i].x, points[i].y, y);

				if(resultS < (y - points[i].y))
				{
					resultS = (y - points[i].y);
				}
				//printf("%.1f\n", resultS);

			}

			if(result > resultS)
			{
				result = resultS;
			}

		}

		if(result >= 1000)
		{
			printf("IMPOSSIBLE\n");
		}
		else
		{
			printf("%.1f\n", result);
		}
	}

	return 0;
}

				

