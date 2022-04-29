#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#define sz size
using namespace std;
int t[52][5002];

int test(string& x, string& y)
{
	t[0][0] = 0;
	int val = 0;
	for (int n = 1; n < x.sz(); n++)
	{
		for (int m = 1; m < y.sz(); m++)
		{
			val = (x[n] == y[m]) ? 0 : 1;
			t[n][m] = min(t[n-1][m-1]+val, min(t[n-1][m]+1, t[n][m-1]+1));
		}
	}
	return t[x.sz()][y.sz()];
}


int main()
{
	//freopen("input.txt", "r", stdin);

	int test; cin >> test;
	for (int i = 0; i < test; i++)
	{
		string s1, s2; cin >> s1 >> s2;
		int loop = s2.sz() / s1.sz();
		string s1m1, s1m2;
		for (int z = 0; z < loop; z++)
		{
			s1m1 += s1;
		}
		s1m2 = s1m1 + s1;

		t[0][0] = 0;
		int val = 0;
		for (int n = 1; n < s1m1.sz(); n++)
		{
			for (int m = 1; m < s2.sz(); m++)
			{
				val = (s1m1[n] == s2[m]) ? 0 : 1;
				t[n][m] = min(t[n-1][m-1]+val, min(t[n-1][m]+1, t[n][m-1]+1));
			}
		}
		int eds1 =  t[s1m1.sz()-1][s2.sz()-1];
		t[0][0] = 0;
		val = 0;
		for (int n = 1; n < s1m2.sz(); n++)
		{
			for (int m = 1; m < s2.sz(); m++)
			{
				val = (s1m2[n] == s2[m]) ? 0 : 1;
				t[n][m] = min(t[n-1][m-1]+val, min(t[n-1][m]+1, t[n][m-1]+1));
			}
		}
		int eds2 = t[s1m2.sz()-1][s2.sz()-1];
		int ans = 0;
		if (eds1 < eds2)
		{
			ans = (eds1/loop);
			if (eds1%loop != 0)
				ans++;
		}
		else
		{
			ans = (eds2/loop);
			if (eds2%loop != 0)
				ans++;
		}		
		cout << ans << endl;
	}

	return 0;
}