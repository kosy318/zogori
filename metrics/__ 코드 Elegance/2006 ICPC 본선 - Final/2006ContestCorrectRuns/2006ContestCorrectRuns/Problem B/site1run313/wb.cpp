// wb.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>

using namespace std;

int main(void)
{
	int out[1010][4];
	char in[1010];
	char forout[4] = {'A', 'C', 'G', 'T'};
	int m, n, mi, ni;
	int answer, buf, foranswer;
	int t, ti;
	cin >> t;
	for(ti = 0; ti < t; ++ti) {
		cin >> m >> n;
		for(mi = 0; mi < m; ++mi) {
			cin >> in;
			for(ni = 0; ni < n; ++ni) {
				if(mi == 0) {
					out[ni][0] = 0;
					out[ni][1] = 0;
					out[ni][2] = 0;
					out[ni][3] = 0;
				}
				if(in[ni] == 'A') {
					out[ni][0]++;
				} else if(in[ni] == 'C') {
					out[ni][1]++;
				} else if(in[ni] == 'G') {
					out[ni][2]++;
				} else if(in[ni] == 'T') {
					out[ni][3]++;
				}
			}
		}
		answer = 0;
		for(ni=0; ni<n;++ni)
		{
            buf = 0;
			foranswer=0;
			for(mi=0; mi<4; ++mi)
			{
				if(out[ni][buf] < out[ni][mi])
					buf = mi;
				foranswer += out[ni][mi];
			}
			cout << forout[buf];
			answer += foranswer - out[ni][buf];
		}
		cout << endl << answer << endl;
	}
	return 0;
}

