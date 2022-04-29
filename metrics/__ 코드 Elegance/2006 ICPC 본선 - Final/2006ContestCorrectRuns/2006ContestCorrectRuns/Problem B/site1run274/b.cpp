#include<string>
#include<iostream>
#include<vector>
using namespace std;
#include<cstdio>

int main()
{
	//freopen("input.txt", "r", stdin);
	int test; cin >> test;
	for (int i = 0; i < test; i++)
	{
		int lnum, llen; cin >> lnum >> llen;
		vector<string> vec;
		for (int j = 0; j < lnum; j++)
		{
			string line; cin >> line; vec.push_back(line);
		}
		string ans;
		//cout << vec[0];
		int sum = 0;
		for (int n = 0; n < llen; n++)
		{
			int count[4] = {0,}; bool fa, fc, fg, ft; fa = false, fc = false, fg =false, ft = false;
			for (int m = 0; m < lnum; m++)
			{
				if (vec[m][n] == 'A')
				{

					count[0]++;
				}
				else if (vec[m][n] == 'C')
				{

					count[1]++;
				}
				else if (vec[m][n] == 'G')
				{
	
					count[2]++;
				}
				else
				{
	
					count[3]++;

				}

			}
			int max = 0;
			int maxix = 0;
			for (int z = 3; z >= 0; z--)
			{
				if (count[z] >= max) 
				{
					max =  count[z];
					maxix = z;
				}
				sum += count[z];
			}
			sum -= max; 
			if (maxix == 0) ans += 'A';
			else if (maxix == 1) ans += 'C';
			else if (maxix == 2) ans += 'G';
			else if (maxix == 3) ans += 'T';

		}
					cout << ans << endl << sum << endl;
	}
	return 0;
}