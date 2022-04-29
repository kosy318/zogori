#include <iostream>
using namespace std;
#include <string>
#include <cmath>
#include <cstdio>

//#include <fstream>
//fstream fin("a.in");
//#define cin fin

int sh, sm, ss;
int eh, em, es;

void plusC(int* h, int*m, int*s)
{
	(*s)++;
	if (*s >= 60) {
		*s = 0;
		(*m)++;
	}
	if (*m >= 60) {
		*m = 0;
		(*h)++;
	}
}

bool tempC(int h, int m , int s)
{
	if ((h * 10000 + m * 100 + s) % 3 == 0)
		return true;
	return false;
}

int countClock(int ssh, int ssm, int sss, int eeh, int eem, int ees) 
{
	int c = 0;
	while (1) {
		if (tempC(ssh, ssm, sss))
			c++;
		if (ssh == eeh && ssm == eem && sss == ees) 
			break;
		plusC(&ssh, &ssm, &sss);
	}
	return c;
}

void process()
{
	int c = 0;
	int i, j, k;

	if (sh * 10000 + sm * 100 + ss > eh * 10000 + em * 100 + es) {
		c += countClock(sh, sm, ss, 23, 59, 59);
		c += countClock(0,0,0,eh,em,es);
	}
	else {
		c += countClock(sh,sm,ss,eh,em,es);
	}
	cout << c << endl;
}

int main()
{
	int nCase;
	cin >> nCase;

	for (int i = 0; i < nCase; ++i)
	{
		cin >> sh;
		cin.get();
		cin >> sm;
		cin.get();
		cin >> ss;
		cin >> eh;
		cin.get();
		cin >> em;
		cin.get();
		cin >> es;
		process();
	}
	return 0;
}