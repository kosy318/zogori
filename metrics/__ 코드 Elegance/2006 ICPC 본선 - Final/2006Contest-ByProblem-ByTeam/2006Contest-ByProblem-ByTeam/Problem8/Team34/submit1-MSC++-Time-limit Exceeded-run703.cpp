#include <cstdio>
#include <cstring>

char x[5002];
char y[12];
int xn, yn;
//int pre[5000][5000];

int distance(int xs, int xlen)
{
	int table[5001][11];

	for(int i = 0 ; i <= xlen ; i++)
		table[i][0] = 0;

	for(int i = 0 ; i <= yn ; i++)
		table[0][i] = i;

	for(int i = 1 ; i <= xlen ; i++)
	{
		for(int j = 1 ; j <= yn ; j++)
		{
			if(x[xs + i - 1] == y[j])
				table[i][j] = table[i - 1][j - 1];
			else
			{
				int min = table[i - 1][j];

				if(table[i][j - 1] < min) min = table[i][j - 1];
				if(table[i - 1][j - 1] < min) min = table[i - 1][j - 1];

				table[i][j] = min + 1;
			}
		}
	}

	return table[xlen][yn];
}

void solve()
{
	int table[5001];

	table[0] = 0;

	for(int i = 1 ; i <= xn ; i++)
	{
		int min = table[0] + distance(1, i);

		for(int j = 1 ; j < i ; j++)
		{
			int d = distance(j+1, i-j);

			if(table[j] + d < min)
				min = table[j] + d;
		}

		table[i] = min;
	}

	printf("%d\n", table[xn]);
}

int main()
{
	int T;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%s", y + 1);
		scanf("%s", x + 1);

		xn = strlen(x + 1);
		yn = strlen(y + 1);

		solve();
	}

	return 0;
}