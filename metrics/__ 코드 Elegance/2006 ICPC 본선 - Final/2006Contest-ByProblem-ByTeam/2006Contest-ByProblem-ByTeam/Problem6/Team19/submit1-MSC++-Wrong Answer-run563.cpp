#include <stdio.h>

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

		while(n--)
		{
			scanf("%d %d", &a, &b);
			Up += b/(float)a;
			Down += 1/(float)a;
		}

		scanf("%d", &a);
		Up += a;

		result = Up/Down;

		int re = (result+0.001)	;

		if(result-re > 0.0)
		{
			printf("0\n");
		}
		else
		{
			printf("%.0f\n", result);
		}
		//printf("%f %d\n", result,re);
	}

		
		
	return 0;
}