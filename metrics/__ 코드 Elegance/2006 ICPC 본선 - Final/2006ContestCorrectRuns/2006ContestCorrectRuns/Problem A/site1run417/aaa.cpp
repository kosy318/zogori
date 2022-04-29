#include <iostream>
#include <string>
using namespace std;

int main()
{
	int nCase;

	int h[2],m[2],s[2];
	string start,end;

	cin >> nCase;

	while(nCase--)
	{
		
		int ss= 0, ee=0;
		int cnt = 0;
		cin >> start >> end;
		
		h[0] = atoi(start.substr(0,2).c_str());
		m[0] = atoi(start.substr(3,2).c_str());
		s[0] = atoi(start.substr(6,2).c_str());

		h[1] = atoi(end.substr(0,2).c_str());
		m[1] = atoi(end.substr(3,2).c_str());
		s[1] = atoi(end.substr(6,2).c_str());

		if(h[0] > h[1]) h[1] += 24;

		ss = atoi(start.substr(0,1).c_str()) + atoi(start.substr(1,1).c_str()) +
			atoi(start.substr(3,1).c_str()) + atoi(start.substr(4,1).c_str()) +
			atoi(start.substr(6,1).c_str()) + atoi(start.substr(7,1).c_str());

		ee = atoi(end.substr(0,1).c_str()) + atoi(end.substr(1,1).c_str()) +
			atoi(end.substr(3,1).c_str()) + atoi(end.substr(4,1).c_str()) +
			atoi(end.substr(6,1).c_str()) + atoi(end.substr(7,1).c_str());

		if (ss%3 == 0) cnt++;
		if (ee%3 == 0) cnt++;

		cout << ((h[1]*3600 + m[1]*60 + s[1]) - (h[0]*3600 + m[0]*60 + s[0]) + 1 + cnt)/3 << endl;

	}

	return 0;
}