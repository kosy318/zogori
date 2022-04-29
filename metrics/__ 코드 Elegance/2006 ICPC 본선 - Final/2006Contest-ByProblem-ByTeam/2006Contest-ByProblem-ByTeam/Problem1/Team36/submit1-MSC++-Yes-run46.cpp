#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>

using namespace std;

int T;
string start, end;

string inv_ci(int h, int m, int s) {
	char buf[12];
	sprintf(buf, "%02d:%02d:%02d", h, m, s);
	string ret(buf);
	return ret;
}

int ci(string time) {
	int ret;
	string res = "000000";
	stringstream ss;
	time[2] = ' ';
	time[5] = ' ';
	res[0] = time[0];
	res[1] = time[1];
	res[2] = time[3];
	res[3] = time[4];
	res[4] = time[6];
	res[5] = time[7];
	ss << res;
	ss >> ret;
	return ret;
}

void next_time(int &h, int &m, int &s) {
	s++;
	if(s>=60) {
		m++;
		s = 0;
	}
	if(m>=60) {
		h++;
		m = 0;
	}
}

int main(void) {
	int h, m, s, he, me, se;
	int result, each;
	string start2, end2;
	cin >> T;
	stringstream ss;
	while(T--) {
		result = 0;
		ss.clear();
		cin >> start >> end;
		start2 = start;
		start2[2] = ' ';
		start2[5] = ' ';
		ss << start2;
		ss >> h >> m >> s;

		ss.clear();
		end2 = end;
		end2[2] = ' ';
		end2[5] = ' ';
		ss << end2;
		ss >> he >> me >> se;

		if(he*3600+me*60+se < h*3600+m*60+s) he = he + 24;

		while(1) {
			each = ci(inv_ci(h, m, s));
			if(each % 3 == 0) result++;
			if(inv_ci(h, m, s) == inv_ci(he, me, se)) break;
			next_time(h, m, s);
		}
		cout << result << endl;
	}
	return 0;
}