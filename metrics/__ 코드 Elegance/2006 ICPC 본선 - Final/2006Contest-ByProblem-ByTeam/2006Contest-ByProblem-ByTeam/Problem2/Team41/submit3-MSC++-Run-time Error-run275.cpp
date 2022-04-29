#include <stdio.h>

int table[1000+1][1000+1];
bool used[1000+1];
int n, ppp;
int cnt;
bool checker;
void dfs(int x)
{
	int i;
	if( cnt == 2 && x == ppp ){
		checker = 1;
		return;
	}
	if( checker ) return;
	for( i = 1; i <= n; i++)
	{
		if( !used[i] && table[i][x] )
		{
			if( table[i][x] == 2 ){
				cnt++;
				used[i] = 1;
				table[x][i] = 0;
				table[i][x] = 0;
				dfs(i);
				cnt--;
				used[i] = 0;
				table[i][x] = 2;
				table[x][i] = 2;
			}
			else{
				used[i] = 1;
				table[x][i] = 0;
				table[i][x] = 0;
				dfs(i);
				used[i] = 0;
				table[i][x] = 1;
				table[x][i] = 1;
			}
		}
	}
}
void main()
{
	int T, i, p, x, y, m, j;
	scanf("%d", &T);
	for( int t = 1; t <= T; t++)
	{
		cnt = 0;
		checker = 0;
		scanf("%d%d", &n, &m);
		for( i = 1; i <= m; i++)
		{
			scanf("%d%d", &x, &y);
			table[x][y] = 1;
			table[y][x] = 1;
		}
		scanf("%d%d", &x, &y);
		ppp = x;
		table[x][y] = 2;
		table[y][x] = 2;
		scanf("%d%d", &x, &y);
		table[y][x] = 2;
		table[x][y] = 2;
		scanf("%d", &p);
		for( i = 1; i <= p; i++){
			scanf("%d%d", &x, &y);
			table[x][y] = 0;
			table[y][x] = 0;
		}
		dfs(ppp);
		if( checker )
			printf("YES\n");
		else
			printf("NO\n");
		for( i = 1; i <= n; i++)
		{
			for( j = 1; j <= n; j++)
			{
				table[i][j] = 0;
			}
		}
	}
}

