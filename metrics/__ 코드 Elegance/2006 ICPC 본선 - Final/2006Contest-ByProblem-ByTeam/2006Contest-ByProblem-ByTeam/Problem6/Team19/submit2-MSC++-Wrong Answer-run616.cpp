#include <stdio.h>
#include <math.h>

int main()
{
	
	int T;

	scanf("%d", &T);

	while(T--)
	{
		int n;

		scanf("%d", &n);
		float Up = 0, Down = 0;
		float result;

		int a, b;

		int times = 1;

		while(n--)
		{
			scanf("%d %d", &a, &b);
			Up += b/(float)a;
			Down += 1/(float)a;
			times *= a;
		}

		scanf("%d", &a);
		Up += a;

		result = Up/Down;
		result+=0.000001;

		int re = result;

//		int iUp = (Up+0.00001)*times;
//		int iDown = Down*times;

		if(result-re > 0.00001)
		{
			printf("0\n");
		}
		else
		{
			printf("%.0f\n", result);
		}

		//printf("%f %d\n",  result, re);
	}	
	return 0;
}