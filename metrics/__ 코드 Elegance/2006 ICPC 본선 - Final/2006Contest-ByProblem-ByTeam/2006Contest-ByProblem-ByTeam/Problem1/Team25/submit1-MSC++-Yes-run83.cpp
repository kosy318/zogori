#include <iostream>

using namespace std;

class Time
{
public:
	int hh, mm, ss;
	Time(char* time)
	{
		hh = (time[0]-'0')*10 + (time[1]-'0');
		mm = (time[3]-'0')*10 + (time[4]-'0');
		ss = (time[6]-'0')*10 + (time[7]-'0');
	}

	bool compareTo(Time& time)
	{
		return hh == time.hh && mm == time.mm && ss == time.ss;
	}

	bool hasThreeFactor()
	{
		int digit = hh/10 + hh%10 + mm/10 + mm%10 + ss%10 + ss/10;
		return (digit%3)==0;
	}

	void incSS()
	{
		ss++;
		if( ss == 60 ) {
			ss = 0;
			incMM();
		}
	}

	void incMM()
	{
		mm++;
		if( mm == 60 ) {
			mm = 0;
			incHH();
		}
	}

	void incHH()
	{
		hh++;
		if( hh == 24 ) {
			hh = 0;
		}
	}
};

int main()
{
	int nCase;
	cin >> nCase;
	for(int i=0; i<nCase; i++) {
		char timeA[10], timeB[10];

		cin >> timeA >> timeB;
		Time a(timeA), b(timeB);

        int result =0;
		while( a.compareTo(b) == false ) {
			if( a.hasThreeFactor() )
				result++;
			a.incSS();
		}
		if( a.hasThreeFactor() )
			result++;

		cout << result << endl;
    }
}

/*
3
00:59:58 01:01:24
22:47:03 01:03:24
00:00:09 00:03:37
*/