
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
	int T, t;
	int N, n;

	char intBuf[255];
	int h, m, s;
	int h1, m1, s1;
	int start;
	int limit;
	int result;

	scanf("%d", &T);

	for(t = 0; t < T; t++)
	{
		scanf("%d:%d:%d", &h, &m, &s);
		sprintf(intBuf, "%d%0.2d%0.2d", h, m, s);
		start = atoi(intBuf);
		
		scanf("%d:%d:%d", &h1, &m1, &s1);
		sprintf(intBuf, "%d%0.2d%0.2d", h1, m1, s1);
		limit = atoi(intBuf);

		if (limit < start) 
		{
			limit += 240000;
		}
		
		result = 0;
		while (limit >= start)
		{
			if (start % 3 == 0)
			{
				result++;
			}

			if (++s >= 60) 
			{
				s = 0;
				if (++m >= 60)
				{
					m = 0;
					h++;
				}
			}

			sprintf(intBuf, "%d%0.2d%0.2d", h, m, s);
			start = atoi(intBuf);
		}
		printf("%d\n", result);

		
	}




	return 0;
}