#include <stdio.h>

#define MAXN 1000


int n, m;
int map[MAXN+1][MAXN+1];
int a, b, c, d;

int dfn[MAXN+1];
int low[MAXN+1];
int stack[MAXN+1];
int stack_n;


int list_n;
int list[MAXN+1];

int ans;

int Check()
{
	int i;
	int oa, ob, oc, od;
	oa = ob = oc = od = 0;
	for(i=1;i<=list_n;i++)
	{
		if(list[i] == a) oa = 1;
		if(list[i] == b) ob = 1;
		if(list[i] == c) oc = 1;
		if(list[i] == d) od = 1;
	}
	if(oa && ob && oc && od) return 1;
	return 0;
}

int DFS(int v, int w)
{
	int i, ct;
	stack[++stack_n] = v;
	dfn[v] = low[v] = w;
	for(i=1;i<=n;i++) if(map[v][i])
	{
		if(dfn[i])
		{
			if(dfn[i] < low[v]) low[v] = dfn[i];
		}
		else
		{
			ct = stack_n;
			w = DFS(i, w + 1);
			if(low[i] >= dfn[v])
			{
				list_n = 0;
				while(stack_n > ct)
				{
					list[++list_n] = stack[stack_n];
					stack_n --;
				}
				list[++list_n] = v;
				if(Check()) ans = 1;
			}
			if(low[i] < low[v]) low[v] = low[i];
		}
	}
	return w;
}

void Solve()
{
	int i, w = 0;
	ans = 0;
	for(i=1;i<=n;i++) dfn[i] = 0;
	for(i=1;i<=n;i++) if(!dfn[i])
	{
		w = DFS(i, w + 1);
	}
	if(ans)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}

int main()
{
	int i, j, f, x, y;
	int ca;
	scanf("%d", &ca);
	while(ca-- > 0)
	{
		scanf("%d %d", &n, &m);
		for(i=1;i<=n;i++) for(j=1;j<=n;j++) map[i][j] = 0;
		for(i=1;i<=m;i++)
		{
			scanf("%d %d", &x, &y);
			map[x][y] = map[y][x] = 1;
		}
		scanf("%d %d %d %d", &a, &b, &c, &d);
		scanf("%d", &f);
		for(i=1;i<=f;i++)
		{
			scanf("%d %d", &x, &y);
			map[x][y] = map[y][x] = 0;
		}
		Solve();
	}
	return 0;
}