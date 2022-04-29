#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int nTestCase;

	// test case
	scanf("%d", &nTestCase);

	while(nTestCase--)
	{
		int a1, a2, a3;
		int b1, b2, b3;
		int result = 0;
		scanf("%d:%d:%d %d:%d:%d", &a1, &a2, &a3, &b1, &b2, &b3);

		while(1)
		{
			char start[7], end[7];

			sprintf(start, "%d%d%d", a1,a2,a3);
			sprintf(end, "%d%d%d", b1, b2, b3);

			int starttime;
			int endtime;

			starttime = atoi(start);
			endtime = atoi(end);

			if(starttime%3 == 0)
			{
				result++;
			}
			if(starttime == endtime)
			{
				break;
			}
			a3++;

			if(a3 >= 60)
			{
				a3 = 0;
				a2++;
			}
			if(a2 >= 60)
			{
				a2 = 0;
				a1++;
			}

			if(a1> 24)
			{
				a1 = 1;
			}
		}

		printf("%d\n", result);

	}

	return 0;
}
