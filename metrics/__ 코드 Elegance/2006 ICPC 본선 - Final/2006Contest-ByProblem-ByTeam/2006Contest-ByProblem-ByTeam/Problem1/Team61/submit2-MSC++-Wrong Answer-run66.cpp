#include <iostream>
#include <string>

#define START int testcase; \
	cin >> testcase;\
	while(testcase--)

#define LOOP(a, b, c) for(int a = b ; a < c ; a++)
#define FOR(a, b) LOOP(a, 0, b)

using namespace std;


int main()
{
	int t1, t2, t3, t4, t5, t6;
	int time1, time2;
	int result = 0;

	START
	{
		result = 0;
		scanf("%d:%d:%d %d:%d:%d", &t1, &t2, &t3, &t4, &t5,&t6);
		
		time1 = t1 * 3600 + t2 * 60 + t3;
		time2 = t4 * 3600 + t5 * 60 + t6;

        if(time1 - time2 > 0)
		{
			time2 += (24*3600);
			result--;
		}
		
		LOOP(i, time1, time2+1)
		{
			if(i % 3 == 0)
			{
				result++;
			}
		}/*
		result = (time2-time1 + 1);
		if(result % 3 == 0)
		{
			cout << result / 3 << endl;
		}
		else
		{
			cout << 1+(result / 3) << endl;
		}*/

		cout << result << endl;

	}
}