#include <iostream>

using namespace std;

int d[310][310][210];

int main(void)
{
	int T;
	int l0, i, j, k;
	int n, la[51], lb[51];
	int na, nb;
	int sa[310], sb[310];

	int temp;

	cin >> T;

	for (l0 = 0;l0 < T;l0++)
	{
		cin >> n;
		for (i = 0;i < n;i++)
		{
			cin >> la[i];
		}
		for (i = 0;i < n;i++)
		{
			cin >> lb[i];
		}
		cin >> na >> nb;
		for (i = 0;i < na;i++)
		{
			cin >> sa[i];
			sa[i]--;
		}
		for (i = 0;i < nb;i++)
		{
			cin >> sb[i];
			sb[i]--;
		}

		for (i = 0;i <= na;i++)
		{
			for (j = 0;j <= nb;j++)
			{
				for (k = 0;k <= 200;k++)
				{
					d[i][j][k] = -1;
				}
			}
		}
		d[0][0][100] = 0;
		for (i = 0;i <= na;i++)
		{
			for (j = 0;j <= nb;j++)
			{
					//cout << i << ' ' << j;
				for (k = 0;k <= 200;k++)
				{
					if (d[i][j][k] != -1)
					{
						if (k <= 100) // upper is longer. attach to lower
						{
							if (j == nb) goto a;
							temp = k - 100 + lb[sb[j]];
							//cout << temp << ' ';
							if (temp <= 0)
							{
								if (d[i][j + 1][temp + 100] == -1 || d[i][j + 1][temp + 100] > d[i][j][k])
								{
									d[i][j + 1][temp + 100] = d[i][j][k];
								}
							}
							else
							{
								if (j != nb && sa[i] == sb[j])
								{
									//cout << "t";
									if (d[i][j + 1][100] == -1 || d[i][j + 1][100] > d[i][j][k] + temp)
									{
										d[i][j + 1][100] = d[i][j][k] + temp;
									}
								}
								else
								{
									if (d[i][j + 1][temp + 100] == -1 || d[i][j + 1][temp + 100] > d[i][j][k])
									{
										d[i][j + 1][temp + 100] = d[i][j][k];
									}
								}
							}
						}
a:;
						if (k >= 100) // lower is longer. attach to upper
						{
							if (i == na) goto b;
							temp = k - 100 - la[sa[i]];
							//cout << temp << '|';
							if (temp >= 0)
							{
								if (d[i + 1][j][temp + 100] == -1 || d[i + 1][j][temp + 100] > d[i][j][k] + la[sa[i]])
								{
									d[i + 1][j][temp + 100] = d[i][j][k] + la[sa[i]];
								}
							}
							else
							{
								if (i != na && sa[i] == sb[j])
								{
									//cout << "t";
									if (d[i + 1][j][100] == -1 || d[i + 1][j][100] > d[i][j][k] + la[sa[i]])
									{
										d[i + 1][j][100] = d[i][j][k] + la[sa[i]];
									}
								}
								else
								{
									if (d[i + 1][j][temp + 100] == -1 || d[i + 1][j][temp + 100] > d[i][j][k] + la[sa[i]])
									{
										d[i + 1][j][temp + 100] = d[i][j][k] + la[sa[i]];
									}
								}
							}
						}
b:;
					}
				}
					//cout << endl;
			} 
		}
		//cout << "---";
		temp = -1;
		//cout << endl;
		for (i = 0;i <= 200;i++)
		{
			if (d[na][nb][i] != -1)
			{
				//cout << i << ' ';
				if (temp == -1 || temp > d[na][nb][i] + ((i - 100) > 0 ? (i - 100) : 0))
				{
					temp = d[na][nb][i] + ((i - 100) > 0 ? (i - 100) : 0);
				}
			}
		}
		//cout << endl;
		cout << temp << endl;
	}
	return 0;
}