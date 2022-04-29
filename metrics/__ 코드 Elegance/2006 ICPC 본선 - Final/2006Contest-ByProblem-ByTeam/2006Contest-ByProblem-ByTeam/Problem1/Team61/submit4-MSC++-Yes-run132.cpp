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
		

		time2 = t4 * 10000 + t5 * 100 + t6;


		
		while(1)
		{
			time1 = t1 * 10000 + t2 * 100 + t3;
			if(time1%3 == 0)
				result++;

			t3++;
			if (t3 == 60)
			{t3=0;
			t2++;}
			if (t2 == 60)
			{
				t2 = 0;
				t1 ++;
			}
			if (t1 == 24)
			{
				t2 = t3 =0;
				t1 = 0;
			}

			if(time1 == time2)
				break;

		}


		cout << result << endl;

	}
}