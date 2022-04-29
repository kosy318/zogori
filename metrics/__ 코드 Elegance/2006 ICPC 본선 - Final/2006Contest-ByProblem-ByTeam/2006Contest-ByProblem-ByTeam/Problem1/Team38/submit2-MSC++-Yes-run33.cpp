#include <iostream>
using namespace std;

class Clock{ 
public :
	void Set(int h, int m, int s) { hour = h; min = m; sec = s; }
	void Inc();
	bool IsSame(Clock& c);
	int GetInt() { return hour*10000+ min*100 + sec; }
	int hour, min, sec;
};

void Clock::Inc() {
	sec++;
	if ( sec < 60 ) return;
	sec = 0;
	min++;
	if ( min < 60 ) return;
	min = 0;
	hour++;
	if ( hour < 24 ) return;
	hour = 0;
}

bool Clock::IsSame(Clock& c) {
	return hour == c.hour && min == c.min && sec == c.sec;
}



int main() {
	int t;

	cin >> t;

	for(int i = 0; i < t; ++i) {
		Clock c1, c2;
		char dummy;
		int count = 0;

		cin >> c1.hour >> dummy >> c1.min>> dummy >> c1.sec;
		cin >> c2.hour >> dummy >> c2.min>> dummy >> c2.sec;

		while(1) {
            if ( c1.GetInt() %3 == 0 ) 
				count++;
			if ( c1.IsSame(c2) ) break;
			c1.Inc();
		}
		cout << count << endl;
	}

	return 0;
}