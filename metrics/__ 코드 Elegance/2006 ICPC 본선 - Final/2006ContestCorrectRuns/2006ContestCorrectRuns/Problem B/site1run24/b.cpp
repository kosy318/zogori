#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int T, n, l;
	int i, j, k;

	char t[1200];
	int c[1200][4];

	string out;
	int error;

	cin >> T;
	for (i = 0;i < T;i++)
	{
		cin >> n >> l;
		for (k = 0;k < l;k++)
		{
			c[k][0] = c[k][1] = c[k][2] = c[k][3] = 0;
		}
		for (j = 0;j < n;j++)
		{
			cin >> t;
			for (k = 0;k < l;k++)
			{
				if (t[k] == 'A' || t[k] == 'a')
				{
					c[k][0]++;
				}
				if (t[k] == 'C' || t[k] == 'c')
				{
					c[k][1]++;
				}
				if (t[k] == 'G' || t[k] == 'g')
				{
					c[k][2]++;
				}
				if (t[k] == 'T' || t[k] == 't')
				{
					c[k][3]++;
				}
			}
		}
		out.clear();
		error = 0;
		for (k = 0;k < l;k++)
		{
			if (c[k][0] >= c[k][1] && c[k][0] >= c[k][2] && c[k][0] >= c[k][3])
			{
				out.push_back('A');
				error += (n - c[k][0]);
				continue;
			}
			if (c[k][1] >= c[k][2] && c[k][1] >= c[k][3])
			{
				out.push_back('C');
				error += (n - c[k][1]);
				continue;
			}
			if (c[k][2] >= c[k][3])
			{
				out.push_back('G');
				error += (n - c[k][2]);
				continue;
			}
			out.push_back('T');
			error += (n - c[k][3]);
		}
		cout << out << endl << error << endl;
	}
	return 0;
}