#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Time
{
public:
	Time(int, int, int);
	int h;
	int m;
	int s;
	void incr();
	bool isMulOf3();
	bool isEqual(Time &t);
};

Time::Time(int a, int b, int c)
{
	h = a;
	m = b;
	s = c;
}

void Time::incr()
{
	s++;
	if(s == 60)
	{
		s = 0;
		m++;
		if(m == 60)
		{
			m = 0;
			h++;
			if(h == 24)
			{
				h = 0;
			}
		}
		
	}
};

bool Time::isMulOf3()
{
	int temp = s + 100 * m + 10000 * h;

	if(temp % 3)
	{
		return 0;
	}
	else return 1;
}


bool Time::isEqual(Time &t)
{	
	if(
		this->h == t.h &&
		this->m == t.m &&
		this->s == t.s 
		)
			return 1;
	else return 0;
}

int main()
{
	int time;
	cin >> time;

	for(int t = 0; t < time; t++)
	{
		char str1[100];
		char str2[100];
		
		cin >> str1 >> str2;

		int a = atoi(strtok(str1, ":"));
		int b = atoi(strtok(0, ":"));
		int c = atoi(strtok(0, ":"));

		int d = atoi(strtok(str2, ":"));
		int e = atoi(strtok(0, ":"));
		int f = atoi(strtok(0, ":"));

		Time start(a, b, c), end(d, e, f); 
		int result = 0;
		while(1)
		{
			if(start.isEqual(end))
			{
				break;
			}
			if(start.isMulOf3())
			{
				result ++;
			}
			start.incr();
		}
		cout << result << endl;
	}
}