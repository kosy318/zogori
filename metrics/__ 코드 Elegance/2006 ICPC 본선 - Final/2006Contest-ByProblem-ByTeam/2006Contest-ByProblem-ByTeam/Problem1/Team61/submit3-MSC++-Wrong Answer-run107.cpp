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
	int time1, time2, cnt;
	int result = 0;

	START
	{
		result = 0;
		scanf("%d:%d:%d %d:%d:%d", &t1, &t2, &t3, &t4, &t5,&t6);
		
		time1 = t1 * 3600 + t2 * 60 + t3;
		time2 = t4 * 3600 + t5 * 60 + t6;
		cnt = time2 - time1 + 2;

        if(time1 - time2 > 0)
		{
			cnt += (24*3600);
		}
		
		while(cnt != 0)
		{
			t3++;
			if (t3 == 60)
			{t3=0;
			t2++;}
			if (t2 == 60)
			{
				t2 = 0;
				t3 ++;
			}
			if (t3 == 24)
			{
				t1 = t2 = t3 =0;
			}
			time1 = t1 * 10000 + t2 * 100 + t3;
			if(time1%3 == 0)
				result++;

			cnt--;
		}


		cout << result << endl;

	}
}