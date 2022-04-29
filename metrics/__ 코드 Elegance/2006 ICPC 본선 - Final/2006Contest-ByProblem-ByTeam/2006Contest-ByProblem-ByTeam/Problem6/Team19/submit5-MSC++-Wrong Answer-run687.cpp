#include <stdio.h>
#include <math.h>

int a[100], b[100], c[100];
int main()
{
	
	int T;

	scanf("%d", &T);

	while(T--)
	{
		int n;

		scanf("%d", &n);
		

		int times = 1;

		int i = 0;
		while(i < n)
		{
			int ta, tb;
			scanf("%d %d", &ta, &tb);
			
			b[i] = tb;
			c[i] = ta;

			i++;
		}

		for(i = 0; i < n; i++)
		{
			a[i]  = 1;
			for(int j = 0; j < n; j++)
			{
				if(i != j)
				{
					a[i] *= c[j];
					b[i] *= c[j];
				}
			}
		}
		int tc;

    	scanf("%d", &tc);
		
		for(i = 0; i < n; i++)
		{
			tc *= c[i];
		}
		int Up = tc;
		int Down = 0;

		for(i = 0; i < n; i++)
		{
			Up += b[i];
			Down += a[i];
		}
		
		if(Up%Down)
		{
			printf("0\n");
		}
		else
		{
			printf("%d\n", Up/Down);
			
			
		}

		//printf("%f %d\n",  result, re);
	}	
	return 0;
}