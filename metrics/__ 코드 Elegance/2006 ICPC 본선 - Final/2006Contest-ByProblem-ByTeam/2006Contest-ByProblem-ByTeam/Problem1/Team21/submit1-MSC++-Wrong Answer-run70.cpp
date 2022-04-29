#include <iostream>
#include <string>
using namespace std;

int getTime(string str, int&h, int&m, int&s);
int getTID(int h, int m, int s);
int nextTime(int&h, int&m, int&s);

int main()
{
	int testcase;
	int temp, eid;
	int cnt;
	int sh, sm, ss, eh, em, es;
	string start, end;
	cin >> testcase;

	for(int i=0; i<testcase; i++) {
		cin >> start >> end;
		getTime(start, sh, sm, ss);
		getTime(end, eh, em, es);
		eid = getTID(eh, em, es);
		cnt=0;
		
		while((temp=getTID(sh, sm, ss))!=eid) {
			if(temp%3 == 0)
				cnt++;
			nextTime(sh, sm, ss);
		}
		cout << cnt << endl;
	}

	return 0;
}

int getTime(string str, int&h, int&m, int&s) {
	h=m=s=0;
	h=(str[0]-'0')*10+(str[1]-'0');
	m=(str[3]-'0')*10+(str[4]-'0');
	s=(str[6]-'0')*10+(str[7]-'0');
	return 0;
}

int getTID(int h, int m, int s) {
	return h*10000+m*100+s;
}

int nextTime(int&h, int&m, int&s) {
	s++;
	if(s==60) {
		s=0;
		m++;
	}
	if(m==60) {
		m=0;
		h++;
	}
	if(h==24) {
		h=0;
	}
	return 0;
}