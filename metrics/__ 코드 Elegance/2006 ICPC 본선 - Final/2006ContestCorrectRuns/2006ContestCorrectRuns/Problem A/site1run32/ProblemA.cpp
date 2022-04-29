#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string inps, inpe;

void solve()
{
	int hh1, hh2;
	int mm1, mm2;
	int ss1, ss2;
	int s, e;
	int cnt = 0;

	hh1 = ( inps[0] - '0' ) * 10 + inps[1] -'0';
	hh2 = ( inpe[0] - '0' ) * 10 + inpe[1] -'0';
	mm1 = ( inps[3] - '0' ) * 10 + inps[4] -'0';
	mm2 = ( inpe[3] - '0' ) * 10 + inpe[4] -'0';
	ss1 = ( inps[6] - '0' ) * 10 + inps[7] -'0';
	ss2 = ( inpe[6] - '0' ) * 10 + inpe[7] -'0';

	s = hh1 * 10000 + mm1 * 100 + ss1;
	e = hh2 * 10000 + mm2 * 100 + ss2;

	if ( s % 3 == 0 )
		cnt++;

	while( s != e )
	{
		ss1++;
		if ( ss1 == 60 )
		{
			ss1 = 0;
			mm1++;
		}
		if ( mm1 == 60 )
		{
			mm1 = 0;
			hh1++;
		}

		if ( hh1 == 24 )
			hh1 = 0;

		//cout << hh1 <<"  " << mm1 <<  " " << ss1 << endl;
		s = hh1 * 10000 + mm1 * 100 + ss1;
		if ( s % 3 == 0 )
			cnt++;
    }

	cout << cnt << endl;
}

int main()
{
	//ifstream fin("input.txt");
	int nT;

	cin >> nT;
	while( nT-- )
	{
		cin >> inps >> inpe;
		solve();
	}
}